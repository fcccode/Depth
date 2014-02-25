/*!
 *  \file    CSystemBaseRWLock-Unix.cpp Base system class contains
 *           common functionality such as memory routines, math functions,
 *           error handling, standard I/O routines.
 *  \brief   Base system class - Unix OS - reader/writer lock methods (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.01.2011
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Base system class - Unix OS - reader/writer lock methods (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   20.01.2011 19:48:42

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the  hope  that  it  will  be  useful,  but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
    or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
    for more details.

    You should have received a copy of the GNU General  Public  License  along
    with this program; if not, write to the Free Software Foundation, Inc., 59
    Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
/*--------------------------------------------------------------------------*/
/*
    FILE ID: $Id$

    CHANGE LOG:

    $Log$
*/
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/system/CSystemBase.hpp>
/*--------------------------------------------------------------------------*/
#include "../Unix.hpp"
/*==========================================================================*/
#ifndef __CSYSTEMBASERWLOCK_UNIX_CPP__
#define __CSYSTEMBASERWLOCK_UNIX_CPP__
/*==========================================================================*/
#if defined(__UNIX__)
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSystem {
/*==========================================================================*/
/* CLASS IMPLEMENTATIONS                                                    */
/*==========================================================================*/
Tptr CSystemBase::RWLCreate()
{ CALL
  // Allocate memory for a new reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)CSystemBase::memoryAllocate(sizeof(pthread_rwlock_t));
  // Initialize the reader/writer lock.
  if (rwl != NULL)
  {
    // Initialize rw lock.
    if (pthread_rwlock_init(rwl, NULL) != 0)
    {
      WARNING(STR("Cannot create a new rw lock for reader/writer lock."));
      CSystemBase::memoryFree(rwl);
      return NULL;
    }
  }
  return rwl;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLDestroy(const Tptr a_cpRWLHandle)
{ CALL
  // Destroy the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Destroy the rw lock.
    if (pthread_rwlock_destroy(rwl) != 0)
    {
      WARNING(STR("Cannot destroy the rw lock of the reader/writer lock."));
      return false;
    }

    return CSystemBase::memoryFree(rwl);
  }
  else
    return true;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader lock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Reader rw lock.
    if (pthread_rwlock_rdlock(rwl) != 0)
    {
      WARNING(STR("Cannot reader lock the reader/writer lock with a rw lock handle - %p.") COMMA rwl);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer lock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Writer rw lock.
    if (pthread_wrlock_rdlock(rwl) != 0)
    {
      WARNING(STR("Cannot writer lock the reader/writer lock with a rw lock handle - %p.") COMMA rwl);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Reader unlock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Reader rw unlock.
    if (pthread_rwlock_unlock(rwl) != 0)
    {
      WARNING(STR("Cannot reader unlock the reader/writer lock with a rw lock handle - %p.") COMMA rwl);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLUnlockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Writer unlock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
  {
    // Writer rw unlock.
    if (pthread_rwlock_unlock(rwl) != 0)
    {
      WARNING(STR("Cannot writer unlock the reader/writer lock with a rw lock handle - %p.") COMMA rwl);
      return false;
    }
    else
      return true;
  }
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockReader(const Tptr a_cpRWLHandle)
{ CALL
  // Try to reader lock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
    return (pthread_rwlock_tryrdlock(rwl) == 0);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
Tbool CSystemBase::RWLTryLockWriter(const Tptr a_cpRWLHandle)
{ CALL
  // Try to writer lock the non empty reader/writer lock.
  pthread_rwlock_t* rwl = (pthread_rwlock_t*)a_cpRWLHandle;
  if (rwl != NULL)
    return (pthread_rwlock_trywrlock(rwl) == 0);
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
#endif
