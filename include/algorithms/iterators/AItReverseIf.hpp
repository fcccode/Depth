/*!
 *  \file    AItReverseIf.hpp Contains general template implementation of the
 *           iterator reverse all items algorithm with binary 'If' predicate.
 *  \brief   Iterator reverse all items algorithm with binary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator reverse all items algorithm with binary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   29.05.2007 20:42:47

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
#ifndef __AITREVERSEIF_HPP__
#define __AITREVERSEIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/algorithms/iterators/AItDistance.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
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
//! Algorithm: Forward iterator reverse all items with binary 'If' predicate.
/*!
    Algorithm reverses all items which accepted with  the  given  binary  'If'
    predicate in the sequence represented with its forward iterator.

    In this algorithm binary 'If' predicate should return 'true' if it accepts
    reversed swapped values from the sequence and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_fIf - Binary 'If' predicate.
    \return Count of reversed swapped items.
*/
template <class T_Iterator, typename T_BinaryIfPredicate>
Tuint reverseIfNext(const T_Iterator& a_crIterator, T_BinaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator reverse all items with binary 'If' predicate.
/*!
    Algorithm reverses all items which accepted with  the  given  binary  'If'
    predicate in the sequence represented with its backward iterator.

    In this algorithm binary 'If' predicate should return 'true' if it accepts
    reversed swapped values from the sequence and 'false' otherwise.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_fIf - Binary 'If' predicate.
    \return Count of reversed swapped items.
*/
template <class T_Iterator, typename T_BinaryIfPredicate>
Tuint reverseIfPrev(const T_Iterator& a_crIterator, T_BinaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItReverseIf.inl>
/*==========================================================================*/
#endif
