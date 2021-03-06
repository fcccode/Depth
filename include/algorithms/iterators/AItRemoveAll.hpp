/*!
 *  \file    AItRemoveAll.hpp Contains general template implementation of the
 *           iterator remove all items algorithm.
 *  \brief   Iterator remove all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator remove all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   16.05.2007 20:58:37

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
#ifndef __AITREMOVEALL_HPP__
#define __AITREMOVEALL_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/functions/FBoolEqual.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorRemoveForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorRemoveBackward.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Forward iterator remove all items.
/*!
    Algorithm removes all items from the sequence represented with its forward
    iterator.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \return Count of removed items.
*/
template <class T_Iterator>
Tuint removeAllNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator remove all items with given value.
/*!
    Algorithm removes all items with given value from the sequence represented
    with its forward iterator.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_crValue - Constant reference to the removing value.
    \return Count of removed items.
*/
template <class T_Iterator, typename T_ValueType>
Tuint removeAllNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward iterator remove all items with given value using 'Equal' predicate.
/*!
    Algorithm removes all items with given value from the sequence represented
    with its forward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_crValue - Constant reference to the removing value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of removed items.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
Tuint removeAllNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator remove all items.
/*!
    Algorithm removes  all  items  from  the  sequence  represented  with  its
    backward iterator.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \return Count of removed items.
*/
template <class T_Iterator>
Tuint removeAllPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator remove all items with given value.
/*!
    Algorithm removes all items with given value from the sequence represented
    with its backward iterator.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_crValue - Constant reference to the removing value.
    \return Count of removed items.
*/
template <class T_Iterator, typename T_ValueType>
Tuint removeAllPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator remove all items with given value using 'Equal' predicate.
/*!
    Algorithm removes all items with given value from the sequence represented
    with its backward iterator.

    In this algorithm 'Equal' binary predicate should return 'true' if  X == Y
    and 'false' otherwise.

    Important: This algorithm updates data under the  sequence's  iterator  so
    make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_crValue - Constant reference to the removing value.
    \param a_fEqual - 'Equal' binary predicate.
    \return Count of removed items.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
Tuint removeAllPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fEqual);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItRemoveAll.inl>
/*==========================================================================*/
#endif
