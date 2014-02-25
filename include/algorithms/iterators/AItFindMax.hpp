/*!
 *  \file    AItFindMax.hpp Contains general template implementation of the
 *           find maximum value algorithm.
 *  \brief   Find maximum value algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.04.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Find maximum value algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   03.04.2007 02:28:53

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
#ifndef __AITFINDMAX_HPP__
#define __AITFINDMAX_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/concept/functions/MConceptPredicate2.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorAnyForward.hpp>
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
//! Algorithm: Forward searching for the iterator with maximum value.
/*!
    Algorithm searches  forward  for  the  iterator  with  maximum  value.  It
    implements searching in container which  represented  with  given  forward
    iterator. It stops searching process when  iterator  cannot  step  forward
    anymore, or if iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's forward iterator.
    \return Forward iterator to the maximum value, or invalid iterator.
*/
template <class T_Iterator>
T_Iterator findMaxNext(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward searching for the iterator with maximum value using 'LessThan' predicate.
/*!
    Algorithm searches  forward  for  the  iterator  with  maximum  value.  It
    implements searching in container which  represented  with  given  forward
    iterator. It stops searching process when  iterator  cannot  step  forward
    anymore, or if iteration cycle restarts (for cycled containers).

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Forward iterator to the maximum value, or invalid iterator.
*/
template <class T_Iterator, typename T_BinaryPredicate>
T_Iterator findMaxNext(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward searching for the iterator with maximum value.
/*!
    Algorithm searches backward  for  the  iterator  with  maximum  value.  It
    implements searching in container which represented  with  given  backward
    iterator. It stops searching process when iterator  cannot  step  backward
    anymore, or if iteration cycle restarts (for cycled containers).

    \param a_crIterator - Constant reference to the container's backward iterator.
    \return Backward iterator to the maximum value, or invalid iterator.
*/
template <class T_Iterator>
T_Iterator findMaxPrev(const T_Iterator& a_crIterator);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward searching for the iterator with maximum value using 'LessThan' predicate.
/*!
    Algorithm searches backward  for  the  iterator  with  maximum  value.  It
    implements searching in container which represented  with  given  backward
    iterator. It stops searching process when iterator  cannot  step  backward
    anymore, or if iteration cycle restarts (for cycled containers).

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Backward iterator to the maximum value, or invalid iterator.
*/
template <class T_Iterator, typename T_BinaryPredicate>
T_Iterator findMaxPrev(const T_Iterator& a_crIterator, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItFindMax.inl>
/*==========================================================================*/
#endif
