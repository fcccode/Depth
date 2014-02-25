/*!
 *  \file    AItCopyWhile.hpp Contains general template implementation of the
 *           iterator copy algorithm with unary 'While' predicate.
 *  \brief   Iterator copy algorithm with unary 'While' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator copy algorithm with unary 'While' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   17.05.2007 02:47:23

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
#ifndef __AITCOPYWHILE_HPP__
#define __AITCOPYWHILE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/functions/MConceptPredicate1.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyBackward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertForward.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertBackward.hpp>
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
//! Algorithm: Forward iterator copy with unary 'While' predicate.
/*!
    Algorithm copies values of  one  sequence  represented  with  its  forward
    iterator into the another one. It copies values  until  'While'  predicate
    returns 'false'.

    In this algorithm unary 'While' predicate  should  return  'false'  if  it
    stops the copy process and 'true' otherwise.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's forward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's forward iterator.
    \param a_fWhile - Unary 'While' predicate.
    \return Count of copied items.
*/
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryWhilePredicate>
Tuint copyWhileNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryWhilePredicate a_fWhile);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator copy with unary 'While' predicate.
/*!
    Algorithm copies values of one  sequence  represented  with  its  backward
    iterator into the another one. It copies values  until  'While'  predicate
    returns 'false'.

    In this algorithm unary 'While' predicate  should  return  'false'  if  it
    stops the copy process and 'true' otherwise.

    Important: This algorithm updates data under the copy sequence's  iterator
    so make sure to update its value after the algorithm returns.

    \param a_crIterator - Constant reference to the sequence's backward iterator.
    \param a_crIteratorCopy - Constant reference to the copy sequence's backward iterator.
    \param a_fWhile - Unary 'While' predicate.
    \return Count of copied items.
*/
template <class T_Iterator, class T_IteratorCopy, typename T_UnaryWhilePredicate>
Tuint copyWhilePrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_UnaryWhilePredicate a_fWhile);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItCopyWhile.inl>
/*==========================================================================*/
#endif
