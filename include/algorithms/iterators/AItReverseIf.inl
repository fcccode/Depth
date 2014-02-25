/*!
 *  \file    AItReverseIf.inl Contains general template implementation of the
 *           iterator reverse all items algorithm with binary 'If' predicate.
 *  \brief   Iterator reverse all items algorithm with binary 'If' predicate (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator reverse all items algorithm with binary 'If' predicate (inline).

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
#ifndef __AITREVERSEIF_INL__
#define __AITREVERSEIF_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Iterator, typename T_BinaryIfPredicate>
inline Tuint reverseIfNext(const T_Iterator& a_crIterator, T_BinaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_BinaryIfPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryIfPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;
  Tuint length = NIterators::distanceNext(a_crIterator);

  // Reverse values only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    // Find end iterator.
    if (it2.stepForward(length) != length)
      return result;

    // Half a length.
    ++length;
    length >>= 2;

    // Swap values.
    while (length > 0)
    {
      if (a_fIf(it1.getValueRef(), it2.getValueRef()))
      {
        NCommon::swap(it1.getValueRef(), it2.getValueRef());
        ++result;
      }
      --length;

      // Move to the next iterator's pair.
      if ((it1.stepForward() == 0) || (it2.stepBackward() == 0))
        return result;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, typename T_BinaryIfPredicate>
inline Tuint reverseIfPrev(const T_Iterator& a_crIterator, T_BinaryIfPredicate a_fIf)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_BinaryIfPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryIfPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint result = 0;
  Tuint length = NIterators::distancePrev(a_crIterator);

  // Reverse values only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  if (it1.isValid() && it2.isValid())
  {
    // Find end iterator.
    if (it2.stepBackward(length) != length)
      return result;

    // Half a length.
    ++length;
    length >>= 2;

    // Swap values.
    while (length > 0)
    {
      if (a_fIf(it1.getValueRef(), it2.getValueRef()))
      {
        NCommon::swap(it1.getValueRef(), it2.getValueRef());
        ++result;
      }
      --length;

      // Move to the previous iterator's pair.
      if ((it1.stepBackward() == 0) || (it2.stepForward() == 0))
        return result;
    }
  }
  return result;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
