/*!
 *  \file    AItForEach.hpp Contains general template implementation of the
 *           iterator for each calling algorithm.
 *  \brief   Iterator for each calling algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator for each calling algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 00:23:52

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
#ifndef __AITFOREACH_HPP__
#define __AITFOREACH_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/concept/functions/MConceptFunction1.hpp>
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
//! Algorithm: Forward iterator for each calling.
/*!
    Algorithm calls  given  function  for  each  forward  iterator.  Algorithm
    returns count of the  forward  iterators  which  were  called  with  given
    predicate.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fFunction - Unary function.
    \return Count of the forward iterators which were called with given function.
*/
template <class T_Iterator, typename T_UnaryFunction>
Tuint forEachNext(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator for each calling.
/*!
    Algorithm calls given  function  for  each  backward  iterator.  Algorithm
    returns count of the backward  iterators  which  were  called  with  given
    predicate.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fFunction - Unary function.
    \return Count of the backward iterators which were called with given function.
*/
template <class T_Iterator, typename T_UnaryFunction>
Tuint forEachPrev(const T_Iterator& a_crIterator, T_UnaryFunction a_fFunction);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItForEach.inl>
/*==========================================================================*/
#endif
