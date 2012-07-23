/*
 * \brief  Connection to Gpio session
 * \author Ivan Loskutov
 * \date   2012-06-16
 */

/*
 * Copyright 2012 Ksys Labs LLC
 * Contact: <ivan.loskutov@ksyslabs.org>
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__GPIO_SESSION__CONNECTION_H_
#define _INCLUDE__GPIO_SESSION__CONNECTION_H_

#include <gpio_session/client.h>
#include <base/connection.h>

namespace Gpio {

	class Connection : public Genode::Connection<Session>, public Session_client
	{
		public:
			Connection()
			:
				Genode::Connection<Session>(session("ram_quota=4K")),
				Session_client(cap())
			{ }
	};
}

#endif /* _INCLUDE__GPIO_SESSION__CONNECTION_H_ */