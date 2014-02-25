/*!
 *  \file    AItLowerBound.hpp Contains general template implementation of the
 *           lower bound searching algorithm.
 *  \brief   Lower bound searching algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.08.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Lower bound searching algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   23.08.2006 01:18:57

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
#ifndef __AITLOWERBOUND_HPP__
#define __AITLOWERBOUND_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/details/CLowerBoundHelper.hpp>
#include <Depth/include/algorithms/functions/FBoolLessThan.hpp>
#include <Depth/include/traits/MTraitsIterator.hpp>
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
//! Algorithm: Forward lower bound searching for the first iterator with value equal or more than given one.
/*!
    Algorithm searches forward for the first iterator with value equal or more
    than given one. It implements searching  in  container  which  represented
    with given forward iterator. It  stops  searching  process  when  iterator
    cannot step forward anymore, or if iteration cycle  restarts  (for  cycled
    containers).

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the lower bound searching value.
    \return Forward iterator to the lower bound value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType>
T_Iterator lowerBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Forward lower bound searching for the first iterator with value equal or more than given one using 'LessThan' predicate.
/*!
    Algorithm searches forward for the first iterator with value equal or more
    than given one. It implements searching  in  container  which  represented
    with given forward iterator. It  stops  searching  process  when  iterator
    cannot step forward anymore, or if iteration cycle  restarts  (for  cycled
    containers).

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_crValue - Constant reference to the lower bound searching value.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Forward iterator to the lower bound value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
T_Iterator lowerBoundNext(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward lower bound searching for the first iterator with value equal or more than given one.
/*!
    Algorithm searches backward for the first iterator  with  value  equal  or
    more  than  given  one.  It  implements  searching  in   container   which
    represented with given backward iterator. It stops searching process  when
    iterator cannot step backward anymore, or if iteration cycle restarts (for
    cycled containers).

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the lower bound searching value.
    \return Backward iterator to the lower bound value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType>
T_Iterator lowerBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward lower bound searching for the first iterator with value equal or more than given one using 'LessThan' predicate.
/*!
    Algorithm searches backward for the first iterator  with  value  equal  or
    more  than  given  one.  It  implements  searching  in   container   which
    represented with given backward iterator. It stops searching process  when
    iterator cannot step backward anymore, or if iteration cycle restarts (for
    cycled containers).

    In  this  algorithm 'LessThan' binary  predicate  should  return 'true' if
    X < Y and 'false' otherwise.

    Important: This algorithm requires container to be sorted.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_crValue - Constant reference to the lower bound searching value.
    \param a_fLessThan - 'LessThan' binary predicate.
    \return Backward iterator to the lower bound value, or invalid iterator.
*/
template <class T_Iterator, typename T_ValueType, typename T_BinaryPredicate>
T_Iterator lowerBoundPrev(const T_Iterator& a_crIterator, const T_ValueType& a_crValue, T_BinaryPredicate a_fLessThan);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItLowerBound.inl>
/*==========================================================================*/
#endif
