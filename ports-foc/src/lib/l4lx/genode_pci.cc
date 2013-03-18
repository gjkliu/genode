/*
 * \brief  Genode C API for PCI functions of the L4Linux support library
 * \author Alexander Tarasikov <tarasikov@ksyslabs.org>
 * \date   2013-03-04
 */

/*
 * Copyright (C) 2013 Ksys Labs LLC
 * Copyright (C) 2009-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

/* Genode includes */
#include <pci_session/connection.h>
#include <pci_device/client.h>

#include <base/env.h>
#include <base/printf.h>

namespace Fiasco {
#include <genode/pci.h>
}

static Pci::Connection *pci;

#define PCI_SLOT(devfn)         (((devfn) >> 3) & 0x1f)
#define PCI_FUNC(devfn)         ((devfn) & 0x07)

static bool DEBUG = false;
#define CPDBG(x, arg...) do { if (DEBUG) PDBG(x, ##arg); } while (0)

extern "C" {
	unsigned genode_read_pci_config(unsigned char bus, unsigned char slot,
		unsigned char func, unsigned char offset)
	{
		return 0;
	}

	int genode_pci_read(void *data, unsigned devfn, unsigned where,
		unsigned size, unsigned *value)
	{
		if (!data) {
			CPDBG("%s: data is NULL", __func__);
			return -1;
		}

		unsigned char slot = PCI_SLOT(devfn);

		Pci::Device_client **devs = (Pci::Device_client**)data;
		Pci::Device_client *dev = devs[slot];

		if (!dev) {
			CPDBG("%s: device %x not found", __func__, slot);
			return -1;
		}

		enum Pci::Device::Access_size sz = Pci::Device::ACCESS_8BIT;
			
		switch (size) {
			case 2:
				sz = Pci::Device::ACCESS_16BIT;
				break;
			case 4:
				sz = Pci::Device::ACCESS_32BIT;
				break;
		}
		*value = dev->config_read(where, sz);
	
		CPDBG("%s: devfn=%x where=%x size=%x -> %x",
			__func__, devfn, where, size, *value);

		return 0;
	}

	int genode_pci_write(void *data, unsigned devfn, unsigned where,
		unsigned size, unsigned value)
	{
		CPDBG("%s: devfn=%x where=%x size=%x value=%x",
				__func__, devfn, where, size, value);

		if (!data) {
			CPDBG("%s: data is NULL", __func__);
			return -1;
		}

		unsigned char slot = PCI_SLOT(devfn);

		Pci::Device_client **devs = (Pci::Device_client**)data;
		Pci::Device_client *dev = devs[slot];

		if (!dev) {
			CPDBG("%s: device %x not found", __func__, slot);
			return -1;
		}

		enum Pci::Device::Access_size sz = Pci::Device::ACCESS_8BIT;
			
		switch (size) {
			case 2:
				sz = Pci::Device::ACCESS_16BIT;
				break;
			case 4:
				sz = Pci::Device::ACCESS_32BIT;
				break;
		}
		dev->config_write(where, value, sz);
		return 0;
	}

	void genode_pci_init_l4lx(void **busses) {
		static Pci::Connection _pci;
		pci = &_pci;

		if (!busses) {
			CPDBG("%s: busses is NULL", __func__);
			return;
		}

		Pci::Device_client ***devs = (Pci::Device_client***)busses;
		Pci::Device_capability cap = pci->first_device();

		while (cap.valid()) {
			Pci::Device_client device(cap);
			
			unsigned char _dev, _bus, _fn;
			device.bus_address(&_bus, &_dev, &_fn);
			CPDBG("%s: found bus=%x dev=%x fn=%x vid=%x pid=%x",
				__func__, _bus, _dev, _fn,
				device.vendor_id(), device.device_id());

			if (!devs[_bus]) {
				devs[_bus] = new (Genode::env()->heap())
					Pci::Device_client*[Fiasco::GENODE_MAX_PCI_DEV]; 
				Genode::memset(devs[_bus], 0,
					Fiasco::GENODE_MAX_PCI_DEV * sizeof(Pci::Device_client*));
			}

			devs[_bus][_dev] = new (Genode::env()->heap()) Pci::Device_client(cap);
			CPDBG("%s: devs=%p devs[%x]=%p devs[%x][%x]=%p",
				__func__, devs, _bus, devs[_bus],
				_bus, _dev, devs[_bus][_dev]);

			cap = pci->next_device(cap);
		}
	}
}
