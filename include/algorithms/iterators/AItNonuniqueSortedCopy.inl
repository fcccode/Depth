/*!
 *  \file    AItNonuniqueSortedCopy.inl Contains general template
 *           implementation of the iterator non unique and copy
 *           all sorted items algorithm.
 *  \brief   Iterator non unique and copy all sorted items algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Iterator non unique and copy all sorted items algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common iterators algorithms
    VERSION:   1.0
    CREATED:   05.06.2007 21:18:03

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
#ifndef __AITNONUNIQUESORTEDCOPY_INL__
#define __AITNONUNIQUESORTEDCOPY_INL__
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
template <class T_Iterator, class T_IteratorCopy>
inline Tuint nonuniqueSortedCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueSortedCopyNext(a_crIterator, a_crIteratorCopy, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint nonuniqueSortedCopyNext(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyForward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert forward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertForward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 1;
  Tuint result = 0;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  T_IteratorCopy it3(a_crIteratorCopy);
  if (it1.isValid() && it2.isValid() && it3.isValidContainer())
  {
    while ((it2.stepForward() > 0) && (it2 != a_crIterator))
    {
      count = 1;
      // Check if items are unique.
      while (a_fEqual(it1.getValueRef(), it2.getValueRef()))
      {
        ++count;
        // Get next sequence item.
        if ((it2.stepForward() == 0) || (it2 == a_crIterator))
        {
          if ((count >= a_cMinCount) && (count <= a_cMaxCount))
          {
            // Copy current value.
            if (it3.isValid())
            {
              if (!it3.insertNext(it1.getValueRef()) || (it3.stepForward() == 0))
                return result;
            }
            else
            {
              if (!it3.insertBackward(it1.getValueRef()))
                return result;
            }
            ++result;
          }
          return result;
        }
      }
      // Count non unique item.
      if ((count >= a_cMinCount) && (count <= a_cMaxCount))
      {
        // Copy current value.
        if (it3.isValid())
        {
          if (!it3.insertNext(it1.getValueRef()) || (it3.stepForward() == 0))
            return result;
        }
        else
        {
          if (!it3.insertBackward(it1.getValueRef()))
            return result;
        }
      	++result;
      }
      count = 0;
      // Update iterators.
      it1 = it2;
    }
    // Count the last non unique item.
    if ((count > 0) && (count >= a_cMinCount) && (count <= a_cMaxCount))
    {
      // Copy current value.
      if (it3.isValid())
      {
        if (!it3.insertNext(it1.getValueRef()) || (it3.stepForward() == 0))
          return result;
      }
      else
      {
        if (!it3.insertBackward(it1.getValueRef()))
          return result;
      }
      ++result;
    }
  }
  return result;
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy>
inline Tuint nonuniqueSortedCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  return nonuniqueSortedCopyPrev(a_crIterator, a_crIteratorCopy, NFunctions::FBoolEqual<const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&>(), a_cMinCount, a_cMaxCount);
}
/*--------------------------------------------------------------------------*/
template <class T_Iterator, class T_IteratorCopy, typename T_BinaryPredicate>
inline Tuint nonuniqueSortedCopyPrev(const T_Iterator& a_crIterator, const T_IteratorCopy& a_crIteratorCopy, T_BinaryPredicate a_fEqual, const Tuint a_cMinCount/* = 2 */, const Tuint a_cMaxCount/* = NBase::CUnsignedInteger::getMax() */)
{ CALL
  // Check T_Iterator class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_Iterator> >();
  // Check T_IteratorCopy class constraint to be an any backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorAnyBackward<T_IteratorCopy> >();
  // Check T_IteratorCopy class constraint to be an insert backward iterator.
  NConcept::MConstraint::requiresConcept<NConcept::NIterators::MConceptIteratorInsertBackward<T_IteratorCopy> >();
  // Check T_BinaryPredicate type constraint to be a suitable binary predicate.
  NConcept::MConstraint::requiresConcept<NConcept::NFunctions::MConceptPredicate2<T_BinaryPredicate, const typename T_Iterator::TReturn&, const typename T_Iterator::TReturn&> >();

  Tuint count = 1;
  Tuint result = 0;

  // Make values non unique only of valid iterator.
  T_Iterator it1(a_crIterator);
  T_Iterator it2(a_crIterator);
  T_IteratorCopy it3(a_crIteratorCopy);
  if (it1.isValid() && it2.isValid() && it3.isValidContainer())
  {
    while ((it2.stepBackward() > 0) && (it2 != a_crIterator))
    {
      count = 1;
      // Check if items are unique.
      while (a_fEqual(it1.getValueRef(), it2.getValueRef()))
      {
        ++count;
        // Get previous sequence item.
        if ((it2.stepBackward() == 0) || (it2 == a_crIterator))
        {
          if ((count >= a_cMinCount) && (count <= a_cMaxCount))
          {
            // Copy current value.
            if (it3.isValid())
            {
              if (!it3.insertPrev(it1.getValueRef()) || (it3.stepBackward() == 0))
                return result;
            }
            else
            {
              if (!it3.insertForward(it1.getValueRef()))
                return result;
            }
            ++result;
          }
          return result;
        }
      }
      // Count non unique item.
      if ((count >= a_cMinCount) && (count <= a_cMaxCount))
      {
        // Copy current value.
        if (it3.isValid())
        {
          if (!it3.insertPrev(it1.getValueRef()) || (it3.stepBackward() == 0))
            return result;
        }
        else
        {
          if (!it3.insertForward(it1.getValueRef()))
            return result;
        }
      	++result;
      }
      count = 0;
      // Update iterators.
      it1 = it2;
    }
    // Count the last non unique item.
    if ((count > 0) && (count >= a_cMinCount) && (count <= a_cMaxCount))
    {
      // Copy current value.
      if (it3.isValid())
      {
        if (!it3.insertPrev(it1.getValueRef()) || (it3.stepBackward() == 0))
          return result;
      }
      else
      {
        if (!it3.insertForward(it1.getValueRef()))
          return result;
      }
      ++result;
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
