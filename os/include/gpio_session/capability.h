/*
 * \brief  Gpio session capability type
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

#ifndef _INCLUDE__GPIO_SESSION__CAPABILITY_H_
#define _INCLUDE__GPIO_SESSION__CAPABILITY_H_

#include <base/capability.h>
#include <gpio_session/gpio_session.h>

namespace Gpio { typedef Genode::Capability<Session> Session_capability; }

#endif /* _INCLUDE__GPIO_SESSION__CAPABILITY_H_ */