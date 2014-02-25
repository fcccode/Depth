/*!
 *  \file    ANonuniqueSortedCopy.hpp Contains general template
 *           implementation of the container non unique and copy
 *           all sorted items algorithm.
 *  \brief   Container non unique and copy all sorted items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container non unique and copy all sorted items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 21:29:27

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
#ifndef __ANONUNIQUESORTEDCOPY_HPP__
#define __ANONUNIQUESORTEDCOPY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/containers/AGetItLast.hpp>
#include <Depth/include/algorithms/iterators/AItNonuniqueSortedCopy.hpp>
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
//! Algorithm: Container non unique and copy all sorted items.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the sorted container.
    \param a_rContainerCopy - Reference to the copy container.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of copied non unique items.
    \see NDepth::NAlgorithms::NIterators::nonuniqueSortedCopyNext()
    \see NDepth::NAlgorithms::NIterators::nonuniqueSortedCopyPrev()
*/
template <class T_Container, class T_ContainerCopy>
Tuint nonuniqueSortedCopy(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*--------------------------------------------------------------------------*/
//! Algorithm: Container non unique and copy all sorted items using 'Equal' predicate.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the sorted container.
    \param a_rContainerCopy - Reference to the copy container.
    \param a_fEqual - 'Equal' binary predicate.
    \param a_cMinCount - Minimum count of non unique items (default is 2).
    \param a_cMaxCount - Maximum count of non unique items (default is NDepth::Base::CUnsignedInteger::getMax()).
    \return Count of copied non unique items.
    \see NDepth::NAlgorithms::NIterators::nonuniqueSortedCopyNext()
    \see NDepth::NAlgorithms::NIterators::nonuniqueSortedCopyPrev()
*/
template <class T_Container, class T_ContainerCopy, typename T_BinaryPredicate>
Tuint nonuniqueSortedCopy(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount = 2, const Tuint a_cMaxCount = NBase::CUnsignedInteger::getMax());
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/ANonuniqueSortedCopy.inl>
/*==========================================================================*/
#endif
