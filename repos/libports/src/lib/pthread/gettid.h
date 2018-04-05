/*
 * \brief  Linux gettid(2) emulation
 * \author Alexander Senier
 * \date   2018-04-05
 *
 */

/*
 * Copyright (C) 2018 Componolit GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU Affero General Public License version 3.
 */

#include <base/thread.h>

#include <pthread.h>
#include "thread.h"

inline pid_t gettid()
{
    return pthread_registry().id(pthread_self());
}
