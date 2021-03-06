/*!
 *  \file    AItCountIf.hpp Contains general template implementation of the
 *           iterator counting algorithm with unary 'If' predicate.
 *  \brief   Iterator counting algorithm with unary 'If' predicate.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator counting algorithm with unary 'If' predicate.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   12.09.2006 20:54:43

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
#ifndef __AITCOUNTIF_HPP__
#define __AITCOUNTIF_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AReverseIt.hpp>
#include <Depth/include/concept/functions/MConceptPredicate1.hpp>
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
//! Algorithm: Forward iterator counting with unary 'If' predicate.
/*!
    Algorithm returns count of the forward iterators accepted with  the  given
    unary 'If' predicate.

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's forward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Count of forward iterators including the given iterator.
*/
template <class T_Iterator, typename T_UnaryIfPredicate>
Tuint countIfNext(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf);
/*--------------------------------------------------------------------------*/
//! Algorithm: Backward iterator counting with unary 'If' predicate.
/*!
    Algorithm get count of the backward  iterators  accepted  with  the  given
    unary 'If' predicate.

    In this algorithm unary 'If' predicate should return 'true' if it  accepts
    the value and 'false' otherwise.

    \param a_crIterator - Constant reference to the container's backward iterator.
    \param a_fIf - Unary 'If' predicate.
    \return Count of backward iterators including the given iterator.
*/
template <class T_Iterator, typename T_UnaryIfPredicate>
Tuint countIfPrev(const T_Iterator& a_crIterator, T_UnaryIfPredicate a_fIf);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/iterators/AItCountIf.inl>
/*==========================================================================*/
#endif
