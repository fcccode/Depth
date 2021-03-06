/*!
 *  \file    ANonuniqueCount.hpp Contains general template implementation of
 *           the container get count of the non unique items algorithm.
 *  \brief   Container get count of the non unique items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container get count of the non unique items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 02:03:26

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
#ifndef __ANONUNIQUECOUNT_HPP__
#define __ANONUNIQUECOUNT_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/iterators/AItNonuniqueCount.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Container get count of the non unique items.
/*!
    \param a_rContainer - Reference to the container.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
    \see NDepth::NAlgorithms::NIterators::nonuniqueCountNext()
    \see NDepth::NAlgorithms::NIterators::nonuniqueCountPrev()
*/
template <class T_Container>
Tuint nonuniqueCount(T_Container& a_rContainer, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Container get count of the non unique items using 'Equal' predicate.
/*!
    \param a_rContainer - Reference to the container.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of non unique items.
    \see NDepth::NAlgorithms::NIterators::nonuniqueCountNext()
    \see NDepth::NAlgorithms::NIterators::nonuniqueCountPrev()
*/
template <class T_Container, typename T_BinaryPredicate>
Tuint nonuniqueCount(T_Container& a_rContainer, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ANonuniqueCount.inl>
/*==========================================================================*/
#endif
