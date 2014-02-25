/*!
 *  \file    CTreeIteratorDepthPostOrder.inl Tree depth post-order iterator
 *           definitions. It gives ability to do depth post-order moving
 *           through the tree nodes (first visit all child nodes, then
 *           visit parent node).
 *  \brief   Tree depth post-order iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree depth post-order iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   14.07.2006 21:57:48

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
#ifndef __CTREEITERATORDEPTHPOSTORDER_INL__
#define __CTREEITERATORDEPTHPOSTORDER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator>::CTreeIteratorDepthPostOrder() :
  T_TreeIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator>::CTreeIteratorDepthPostOrder(const T_TreeIterator& a_crTreeIterator) :
  T_TreeIterator()
{ CALL
  set(a_crTreeIterator);
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator>::~CTreeIteratorDepthPostOrder()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator>& CTreeIteratorDepthPostOrder<T_TreeIterator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator>& CTreeIteratorDepthPostOrder<T_TreeIterator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> CTreeIteratorDepthPostOrder<T_TreeIterator>::operator ++ (int)
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> CTreeIteratorDepthPostOrder<T_TreeIterator>::operator -- (int)
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> operator + (const CTreeIteratorDepthPostOrder<T_TreeIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> operator - (const CTreeIteratorDepthPostOrder<T_TreeIterator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> CTreeIteratorDepthPostOrder<T_TreeIterator>::getForward() const
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CTreeIteratorDepthPostOrder<T_TreeIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline CTreeIteratorDepthPostOrder<T_TreeIterator> CTreeIteratorDepthPostOrder<T_TreeIterator>::getBackward() const
{ CALL
  CTreeIteratorDepthPostOrder<T_TreeIterator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CTreeIteratorDepthPostOrder<T_TreeIterator>());
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline Tuint CTreeIteratorDepthPostOrder<T_TreeIterator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_TreeIterator::isValid(), STR("Cannot step forward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step depth forward by given steps.
  T_TreeIterator it_next;
  while (counter > 0)
  {
    // Visit all sibling nodes.
    it_next = T_TreeIterator::getNextSibling();
    if (it_next.isValid())
    {
      T_TreeIterator::operator = (it_next);
      // Travel to deepest child node.
      it_next = T_TreeIterator::getFirstChild();
      while (it_next.isValid())
      {
        T_TreeIterator::operator = (it_next);
        it_next = T_TreeIterator::getFirstChild();
      }
    }
    else
    {
      // Visit parent node.
      it_next = T_TreeIterator::getParent();
      if (it_next.isValid())
        T_TreeIterator::operator = (it_next);
      else
        break;
    }
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline Tuint CTreeIteratorDepthPostOrder<T_TreeIterator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(T_TreeIterator::isValid(), STR("Cannot step backward with the invalid tree iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step depth backward by given steps.
  T_TreeIterator it_prev;
  while (counter > 0)
  {
    // Visit all sibling nodes.
    it_prev = T_TreeIterator::getPrevSibling();
    if (it_prev.isValid())
    {
      T_TreeIterator::operator = (it_prev);
      // Travel to deepest child node.
      it_prev = T_TreeIterator::getLastChild();
      while (it_prev.isValid())
      {
        T_TreeIterator::operator = (it_prev);
        it_prev = T_TreeIterator::getLastChild();
      }
    }
    else
    {
      // Visit parent node.
      it_prev = T_TreeIterator::getParent();
      if (it_prev.isValid())
        T_TreeIterator::operator = (it_prev);
      else
        break;
    }
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
template <class T_Archive>
inline Tbool CTreeIteratorDepthPostOrder<T_TreeIterator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CTreeIteratorDepthPostOrder<T_TreeIterator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((T_TreeIterator&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_TreeIterator>
inline void CTreeIteratorDepthPostOrder<T_TreeIterator>::swap(CTreeIteratorDepthPostOrder<T_TreeIterator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((T_TreeIterator&)(*this), (T_TreeIterator&)a_rInstance);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
