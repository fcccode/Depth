/*!
 *  \file    AMax.hpp Contains general template implementation of the max
 *           algorithm.
 *  \brief   Max algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Max algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common algorithms
    VERSION:   1.0
    CREATED:   03.04.2006 02:41:22

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
#ifndef __AMAX_HPP__
#define __AMAX_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
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
//! Algorithm: Find maximum of two values.
/*!
    \param a_crX - Constant reference to the value X.
    \param a_crY - Constant reference to the value Y.
    \return Maximal value.
*/
template <typename T_Type>
T_Type max(const T_Type& a_crX, const T_Type& a_crY);
/*--------------------------------------------------------------------------*/
//! Algorithm: Find maximum of two values. Use 'LessThan' binary predicate.
/*!
    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crX - Constant reference to the value X.
    \param a_crY - Constant reference to the value Y.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Maximal value.
*/
template <typename T_Type, typename T_LessThanBinaryPredicate>
T_Type max(const T_Type& a_crX, const T_Type& a_crY, T_LessThanBinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/common/AMax.inl>
/*==========================================================================*/
#endif
