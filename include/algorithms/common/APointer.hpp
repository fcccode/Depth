/*!
 *  \file    APointer.hpp Contains general template implementation of the
 *           pointer wrapper algorithm.
 *  \brief   Pointer wrapper algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Pointer wrapper algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   10.10.2006 00:07:43

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
#ifndef __APOINTER_HPP__
#define __APOINTER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CPointer.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Get pointer wrapper to the given object.
/*!
    This algorithm constructs and  returns  pointer  wrapper  to  the  given
    object. This may be useful for passing pointers to function templates
    (algorithms) that would usually take copies of their arguments.

    \param a_pX - Pointer to the wrapping object.
    \return Pointer wrapper for the given object.
*/
template <typename T_Type>
NBase::CPointer<T_Type> ptr(T_Type* a_pX);
/*--------------------------------------------------------------------------*/
//! Algorithm: Get constant pointer wrapper to the given object.
/*!
    This algorithm constructs and returns constant pointer  wrapper  to  the
    given object. This may be useful for passing pointers to function
    templates (algorithms) that would usually take copies of their arguments.

    \param a_cpX - Constant pointer to the wrapping object.
    \return Constant pointer wrapper for the given object.
*/
template <typename T_Type>
const NBase::CPointer<const T_Type> cptr(const T_Type*& a_cpX);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/APointer.inl>
/*==========================================================================*/
#endif
