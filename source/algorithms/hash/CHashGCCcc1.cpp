/*!
 *  \file    CHashGCCcc1.cpp GCC cc1 hash function algorithm.
 *  \brief   GCC cc1 hash function algorithm (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: GCC cc1 hash function algorithm (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 23:15:32

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    under the terms of the GNU General Public License as published by the Free
    Software Foundation; either version 2 of the License, or (at your  option)
    any later version.

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
#include <Depth/include/algorithms/hash/CHashGCCcc1.hpp>
/*==========================================================================*/
#ifndef __CHASHGCCCC1_CPP__
#define __CHASHGCCCC1_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM IMPLEMENTATIONS                                                */
/*==========================================================================*/
Tuint CHashGCCcc1::hash(Tcbuffer a_cpBuffer, const Tuint a_cSize)
{ CALL
  Tuint i = a_cSize;
  while (i-- > 0)
    m_Hash = 614 * m_Hash + (*a_cpBuffer++);
  return a_cSize;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
