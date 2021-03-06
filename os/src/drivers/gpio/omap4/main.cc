/*
 * \brief  Gpio driver for the OMAP4
 * \author Ivan Loskutov <ivan.loskutov@ksyslabs.org>
 * \date   2012-06-23
 */

/*
 * Copyright (C) 2012 Ksys Labs LLC
 * Copyright (C) 2012-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <gpio_session/gpio_session.h>
#include <cap_session/connection.h>
#include <dataspace/client.h>
#include <base/printf.h>
#include <base/sleep.h>
#include <root/component.h>
#include <os/config.h>
#include <os/static_root.h>
#include <util/string.h>

/* local includes */
#include "driver.h"
#include "irq_handler.h"


namespace Gpio {
	using namespace Genode;
	class Session_component;
};


class Gpio::Session_component : public Genode::Rpc_object<Gpio::Session>
{
	private:

		Driver &_driver;

		Signal_context_capability _read_avail_sigh;

	public:
		Session_component(Driver &driver)
		:
			_driver(driver)
		{
		}

		/************************************
		 ** Gpio::Session interface **
		 ************************************/

		void direction_output(int gpio, bool enable)
		{
			_driver.set_gpio_dataout(gpio, enable);
			_driver.set_gpio_direction(gpio, false);
		}

		void direction_input(int gpio)
		{
			_driver.set_gpio_direction(gpio, true);
		}

		void dataout(int gpio, bool enable)
		{
			_driver.set_gpio_dataout(gpio, enable);
		}

		int datain(int gpio)
		{
			return _driver.get_gpio_datain(gpio);
		}

		void debounce_enable(int gpio, bool enable)
		{
			_driver.set_gpio_debounce_enable(gpio, enable);
		}

		void debouncing_time(int gpio, unsigned int us)
		{
			_driver.set_gpio_debouncing_time(gpio, us);
		}

		void falling_detect(int gpio, bool enable)
		{
			_driver.set_gpio_falling_detect(gpio, enable);
		}

		void rising_detect(int gpio, bool enable)
		{
			_driver.set_gpio_rising_detect(gpio, enable);
		}

		void irq_enable(int gpio, bool enable)
		{
			_driver.set_gpio_irq_enable(gpio, enable);
		}

		void irq_sigh(Signal_context_capability cap, int gpio)
		{
			_driver.register_signal(cap, gpio);
		}
};


int main(int, char **)
{
	using namespace Gpio;

	printf("--- omap4 gpio driver ---\n");

	Driver       driver;

	Irq_handler  gpio1_irq(Driver::GPIO1_IRQ, driver);
	Irq_handler  gpio2_irq(Driver::GPIO2_IRQ, driver);
	Irq_handler  gpio3_irq(Driver::GPIO3_IRQ, driver);
	Irq_handler  gpio4_irq(Driver::GPIO4_IRQ, driver);
	Irq_handler  gpio5_irq(Driver::GPIO5_IRQ, driver);
	Irq_handler  gpio6_irq(Driver::GPIO6_IRQ, driver);

	/*
	 * Configure GPIO
	 * Example:
	 * <config>
	 *     <gpio num="123" mode="I"/>
	 *     <gpio num="124" mode="O" value="0"/>
	 * </config>
	 *
	 * num - GPIO pin number
	 * mode - input(I) or output(O)
	 * value - output level (1 or 0), only for output mode
	 */
	try {
		Genode::Xml_node gpio_node = Genode::config()->xml_node().sub_node("gpio");
		for (;; gpio_node = gpio_node.next("gpio")) {
			unsigned num;
			char     mode[2] = {0};
			unsigned value = 0;
			bool     value_ok;

			do {
				try {
					gpio_node.attribute("num").value(&num);
				}
				catch(Genode::Xml_node::Nonexistent_attribute)
				{
					PERR("Missing \"num\" attribute. Ignore node.");
					break;
				}

				try {
					gpio_node.attribute("mode").value(mode, sizeof(mode));
				}
				catch(Genode::Xml_node::Nonexistent_attribute)
				{
					PERR("Missing \"mode\" attribute. Ignore node.");
					break;
				}

				try {
					value_ok = gpio_node.attribute("value").value(&value);
				}
				catch(Genode::Xml_node::Nonexistent_attribute)
				{
					value_ok = false;
				}

				if (mode[0] == 'O' || mode[0] == 'o')
				{
					if (!value_ok) {
						PERR("Missing \"value\" attribute for Output mode. Ignore node.");
						break;
					}
					if (value > 1) {
						PERR("Incorrect \"value\" attribute for Output mode. Ignore node.");
						break;
					}
					driver.set_gpio_dataout(num, value);
					driver.set_gpio_direction(num, false);
				} else if (mode[0] == 'I' || mode[0] == 'i') {
					driver.set_gpio_direction(num, true);
				} else {
					PERR("Incorrect value of \"mode\" attribute. Ignore node.");
					break;
				}

				PDBG("gpio %d mode %s value=%s",
						num, mode, value_ok ? (value==0 ? "0" : value==1 ? "1" : "error") : "-"
				);

			} while(0);
			if (gpio_node.is_last("gpio")) break;
		}
	}
	catch (...) {
		PDBG("No GPIO config");
	}

	/*
	 * Initialize server entry point
	 */
	enum { STACK_SIZE = 4096 };
	static Cap_connection cap;
	static Rpc_entrypoint ep(&cap, STACK_SIZE, "gpio_ep");

	/*
	 * Let the entry point serve the gpio session and root interfaces
	 */
	static Session_component          gpio_session(driver);
	static Static_root<Gpio::Session> gpio_root(ep.manage(&gpio_session));

	/*
	 * Announce service
	 */
	env()->parent()->announce(ep.manage(&gpio_root));

	Genode::sleep_forever();
	return 0;
}

