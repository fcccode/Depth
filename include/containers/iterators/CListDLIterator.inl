/*!
 *  \file    CListDLIterator.inl Double linked list non constant iterator
 *           definitions. It gives ability to get and modify double linked
 *           list items and to do forward and backward moving through the
 *           double linked list nodes.
 *  \brief   Double linked list non constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    17.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Double linked list non constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   17.02.2006 20:52:59

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
#ifndef __CLISTDLITERATOR_INL__
#define __CLISTDLITERATOR_INL__
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
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>::CListDLIterator() :
  NCommon::NIterators::IIterator<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>::CListDLIterator(CListDL<T_Type, T_Allocator>* a_pContainer) :
  NCommon::NIterators::IIterator<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  m_pContainer(a_pContainer),
  m_pNode(NULL)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>::CListDLIterator(const CListDLIterator<T_Type, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIterator<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorInsertBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  NCommon::NIterators::IIteratorRemoveBackward<CListDLIterator<T_Type, T_Allocator>, T_Type, T_Type, CListDL<T_Type, T_Allocator> >(),
  m_pContainer(NULL),
  m_pNode(NULL)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>::~CListDLIterator()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator == (const CListDLIterator<T_Type, T_Allocator>& a_crInstance1, const CListDLIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_pNode == a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool operator != (const CListDLIterator<T_Type, T_Allocator>& a_crInstance1, const CListDLIterator<T_Type, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_pNode != a_crInstance2.m_pNode));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::operator = (const CListDLIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> CListDLIterator<T_Type, T_Allocator>::operator ++ (int)
{ CALL
  CListDLIterator<T_Type, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> CListDLIterator<T_Type, T_Allocator>::operator -- (int)
{ CALL
  CListDLIterator<T_Type, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> operator + (const CListDLIterator<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CListDLIterator<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> operator - (const CListDLIterator<T_Type, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CListDLIterator<T_Type, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListDLIterator<T_Type, T_Allocator>::set(const CListDLIterator<T_Type, T_Allocator>& a_crInstance)
{ CALL
  m_pContainer = a_crInstance.m_pContainer;
  m_pNode = a_crInstance.m_pNode;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> CListDLIterator<T_Type, T_Allocator>::getForward() const
{ CALL
  CListDLIterator<T_Type, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CListDLIterator<T_Type, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDLIterator<T_Type, T_Allocator> CListDLIterator<T_Type, T_Allocator>::getBackward() const
{ CALL
  CListDLIterator<T_Type, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CListDLIterator<T_Type, T_Allocator>(m_pContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_pNode != NULL));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::isValidContainer() const
{ CALL
  return (m_pContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDL<T_Type, T_Allocator>& CListDLIterator<T_Type, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline CListDL<T_Type, T_Allocator>* CListDLIterator<T_Type, T_Allocator>::getContainerPtr() const
{ CALL
  return m_pContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type& CListDLIterator<T_Type, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_pNode->m_Item;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline T_Type* CListDLIterator<T_Type, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_pNode->m_Item;
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListDLIterator<T_Type, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid double linked list iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step forward by given steps.
  while ((m_pNode->m_pNext != NULL) && (counter > 0))
  {
    m_pNode = m_pNode->m_pNext;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tuint CListDLIterator<T_Type, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid double linked list iterator."))
  {
    return 0;
  }

  Tuint counter = a_cStepCount;
  // Try to step backward by given steps.
  while ((m_pNode->m_pPrev != NULL) && (counter > 0))
  {
    m_pNode = m_pNode->m_pPrev;
    --counter;
  }
  // Return step count, that we have done.
  return a_cStepCount - counter;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::insertForward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid double linked list container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_pNode != NULL)), STR("Cannot insert a new item to the invalid iterator of the non empty double linked list."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SListDLNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pNode == NULL)
    {
      node->m_pPrev = NULL;
      node->m_pNext = NULL;
      m_pContainer->m_pFirst = node;
      m_pContainer->m_pLast = node;
    }
    else
    {
      node->m_pPrev = m_pNode;
      node->m_pNext = m_pNode->m_pNext;
      m_pNode->m_pNext = node;
      if (m_pContainer->m_pLast == m_pNode)
        m_pContainer->m_pLast = node;
      else
        node->m_pNext->m_pPrev = node;
    }
    m_pNode = node;
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double linked list node for the forward iterator inserting into the double linked list (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::insertNext(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item to the next forward position of the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SListDLNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pPrev = m_pNode;
    node->m_pNext = m_pNode->m_pNext;
    m_pNode->m_pNext = node;
    if (m_pContainer->m_pLast == m_pNode)
      m_pContainer->m_pLast = node;
    else
      node->m_pNext->m_pPrev = node;
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double linked list node for the next forward iterator inserting into the double linked list (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::insertBackward(const T_Type& a_crItem)
{ CALL
  // Check if the iterator container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot insert a new item into the invalid double linked list container."))
  {
    return false;
  }
  // Check if the current iterator points to the empty container.
  ASSERT((m_pContainer->isEmpty() || (m_pNode != NULL)), STR("Cannot insert a new item to the invalid iterator of the non empty double linked list."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SListDLNode>(a_crItem);

  if (node != NULL)
  {
    if (m_pNode == NULL)
    {
      node->m_pPrev = NULL;
      node->m_pNext = NULL;
      m_pContainer->m_pFirst = node;
      m_pContainer->m_pLast = node;
    }
    else
    {
      node->m_pPrev = m_pNode->m_pPrev;
      node->m_pNext = m_pNode;
      m_pNode->m_pPrev = node;
      if (m_pContainer->m_pFirst == m_pNode)
        m_pContainer->m_pFirst = node;
      else
        node->m_pPrev->m_pNext = node;
    }
    m_pNode = node;
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double linked list node for the backward iterator inserting into the double linked list (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::insertPrev(const T_Type& a_crItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot insert a new item to the previous backward position of the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node = m_pContainer->m_Allocator.template createOne<typename TContainer::SListDLNode>(a_crItem);

  if (node != NULL)
  {
    node->m_pPrev = m_pNode->m_pPrev;
    node->m_pNext = m_pNode;
    m_pNode->m_pPrev = node;
    if (m_pContainer->m_pFirst == m_pNode)
      m_pContainer->m_pFirst = node;
    else
      node->m_pPrev->m_pNext = node;
    ++m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot create a new double linked list node for the previous backward iterator inserting into the double linked list (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeForward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    if ((node_prev == NULL) && (node_next == NULL))
    {
      m_pNode = NULL;
      m_pContainer->m_pFirst = NULL;
      m_pContainer->m_pLast = NULL;
    }
    else if (node_next == NULL)
    {
      m_pNode = node_prev;
      m_pNode->m_pNext = NULL;
      m_pContainer->m_pLast = m_pNode;
    }
    else
    {
      m_pNode = node_next;
      m_pNode->m_pPrev = node_prev;
      if (node_prev == NULL)
        m_pContainer->m_pFirst = m_pNode;
      else
        node_prev->m_pNext = m_pNode;
    }
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the current position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeForward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    if ((node_prev == NULL) && (node_next == NULL))
    {
      m_pNode = NULL;
      m_pContainer->m_pFirst = NULL;
      m_pContainer->m_pLast = NULL;
    }
    else if (node_next == NULL)
    {
      m_pNode = node_prev;
      m_pNode->m_pNext = NULL;
      m_pContainer->m_pLast = m_pNode;
    }
    else
    {
      m_pNode = node_next;
      m_pNode->m_pPrev = node_prev;
      if (node_prev == NULL)
        m_pContainer->m_pFirst = m_pNode;
      else
        node_prev->m_pNext = m_pNode;
    }
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the current position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeNext()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next item from the invalid double linked list iterator."))
  {
    return false;
  }
  // Check if the next forward iterator position is exist.
  ASSERT((m_pNode->m_pNext != NULL), STR("Removing from the next forward double linked list position without a corresponding item (from the end double linked list position)."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext->m_pNext;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pNext = node_next;
    if (node_next == NULL)
      m_pContainer->m_pLast = m_pNode;
    else
      node_next->m_pPrev = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the next forward position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeNext(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove next item from the invalid double linked list iterator."))
  {
    return false;
  }
  // Check if the next forward iterator position is exist.
  ASSERT((m_pNode->m_pNext != NULL), STR("Removing from the next forward double linked list position without a corresponding item (from the end double linked list position)."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext->m_pNext;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pNext = node_next;
    if (node_next == NULL)
      m_pContainer->m_pLast = m_pNode;
    else
      node_next->m_pPrev = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the next forward position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeBackward()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    if ((node_prev == NULL) && (node_next == NULL))
    {
      m_pNode = NULL;
      m_pContainer->m_pFirst = NULL;
      m_pContainer->m_pLast = NULL;
    }
    else if (node_prev == NULL)
    {
      m_pNode = node_next;
      m_pNode->m_pPrev = NULL;
      m_pContainer->m_pFirst = m_pNode;
    }
    else
    {
      m_pNode = node_prev;
      m_pNode->m_pNext = node_next;
      if (node_next == NULL)
        m_pContainer->m_pLast = m_pNode;
      else
        node_next->m_pPrev = m_pNode;
    }
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the current position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removeBackward(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove item from the invalid double linked list iterator."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode;
  typename TContainer::SListDLNode* node_next = m_pNode->m_pNext;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    if ((node_prev == NULL) && (node_next == NULL))
    {
      m_pNode = NULL;
      m_pContainer->m_pFirst = NULL;
      m_pContainer->m_pLast = NULL;
    }
    else if (node_prev == NULL)
    {
      m_pNode = node_next;
      m_pNode->m_pPrev = NULL;
      m_pContainer->m_pFirst = m_pNode;
    }
    else
    {
      m_pNode = node_prev;
      m_pNode->m_pNext = node_next;
      if (node_next == NULL)
        m_pContainer->m_pLast = m_pNode;
      else
        node_next->m_pPrev = m_pNode;
    }
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the current position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removePrev()
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove previous item from the invalid double linked list iterator."))
  {
    return false;
  }
  // Check if the previous backward iterator position is exist.
  ASSERT((m_pNode->m_pNext != NULL), STR("Removing from the previous backward double linked list position without a corresponding item (from the begin double linked list position)."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode->m_pPrev;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev->m_pPrev;

  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pPrev = node_prev;
    if (node_prev == NULL)
      m_pContainer->m_pFirst = m_pNode;
    else
      node_prev->m_pNext = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the previous backward position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline Tbool CListDLIterator<T_Type, T_Allocator>::removePrev(T_Type& a_rItem)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot remove previous item from the invalid double linked list iterator."))
  {
    return false;
  }
  // Check if the previous backward iterator position is exist.
  ASSERT((m_pNode->m_pNext != NULL), STR("Removing from the previous backward double linked list position without a corresponding item (from the begin double linked list position)."))
  {
    return false;
  }

  typename TContainer::SListDLNode* node_cur = m_pNode->m_pPrev;
  typename TContainer::SListDLNode* node_prev = m_pNode->m_pPrev->m_pPrev;

  a_rItem = node_cur->m_Item;
  if (m_pContainer->m_Allocator.deleteOne(node_cur))
  {
    m_pNode->m_pPrev = node_prev;
    if (node_prev == NULL)
      m_pContainer->m_pFirst = m_pNode;
    else
      node_prev->m_pNext = m_pNode;
    --m_pContainer->m_Size;
    return true;
  }
  else
  {
    WARNING(STR("Cannot remove double linked list node from the previous backward position of the double linked list iterator (requested size is %u bytes).") COMMA (sizeof(typename TContainer::SListDLNode)));
    return false;
  }
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
template <class T_Archive>
inline Tbool CListDLIterator<T_Type, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CListDLIterator<T_Type, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, class T_Allocator>
inline void CListDLIterator<T_Type, T_Allocator>::swap(CListDLIterator<T_Type, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_pContainer, a_rInstance.m_pContainer);
  NAlgorithms::NCommon::swap(m_pNode, a_rInstance.m_pNode);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
