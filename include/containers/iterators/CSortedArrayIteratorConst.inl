/*!
 *  \file    CSortedArrayIteratorConst.inl Sorted array constant iterator
 *           definitions. It gives ability to get sorted array items and
 *           to do random moving through the sorted array items.
 *  \brief   Sorted array constant iterator class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    30.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Sorted array constant iterator class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers iterators
    VERSION:   1.0
    CREATED:   30.09.2006 21:42:53

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
#ifndef __CSORTEDARRAYITERATORCONST_INL__
#define __CSORTEDARRAYITERATORCONST_INL__
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
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIteratorConst() :
  NCommon::NIterators::IIteratorConst<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIteratorConst(const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* a_cpContainer) :
  NCommon::NIterators::IIteratorConst<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(a_cpContainer),
  m_Index((a_cpContainer != NULL) ? a_cpContainer->getSize() : 0)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIteratorConst(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::CSortedArrayIteratorConst(const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance) :
  NCommon::NIterators::IIteratorConst<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveAssociative<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::NIterators::IIteratorMoveRandom<CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>, T_Type, T_Type, CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> >(),
  NCommon::ISeekable(),
  m_cpContainer(NULL),
  m_Index(0)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::~CSortedArrayIteratorConst()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator == (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index == a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_pContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator != (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer != a_crInstance2.m_cpContainer) || (a_crInstance1.m_Index != a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator < (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator < (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator < (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index < a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator > (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator > (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator > (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index > a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator <= (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator <= (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator <= (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index <= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator >= (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_pContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator >= (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_pContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool operator >= (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance1, const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance2)
{ CALL
  return ((a_crInstance1.m_cpContainer == a_crInstance2.m_cpContainer) && (a_crInstance1.m_Index >= a_crInstance2.m_Index));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator = (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator += (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepForward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -= (const Tuint a_cStepCount/* = 1 */)
{ CALL
  stepBackward(a_cStepCount);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ ()
{ CALL
  stepForward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- ()
{ CALL
  stepBackward();
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator ++ (int)
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepForward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator -- (int)
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(*this);

  stepBackward();
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator + (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepForward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> operator - (const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance, const Tuint a_cStepCount)
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> temp(a_crInstance);

  temp.stepBackward(a_cStepCount);
  return temp;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const T_Type& a_crItem) const
{ CALL
  return find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tsint a_cIndex) const
{ CALL
  return getIndex((Tuint)a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::operator [] (const Tuint a_cIndex) const
{ CALL
  return getIndex(a_cIndex);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_pContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::set(const CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_crInstance)
{ CALL
  m_cpContainer = a_crInstance.m_cpContainer;
  m_Index = a_crInstance.m_Index;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getForward() const
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform forward step and return forward iterator instance or invalid one.
  return ((it.stepForward() == 1) ? it : CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getBackward() const
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform backward step and return backward iterator instance or invalid one.
  return ((it.stepBackward() == 1) ? it : CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getIndex(const Tuint a_cIndex) const
{ CALL
  CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> it(*this);
  // Perform indexed step and return indexed iterator instance or invalid one.
  return (it.stepIndex(a_cIndex) ? it : CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>(m_cpContainer));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValid() const
{ CALL
  return (isValidContainer() && (m_Index < m_cpContainer->getSize()));
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::isValidContainer() const
{ CALL
  return (m_cpContainer != NULL);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerRef() const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Taking reference to the invalid iterator container value leads to the error."));

  return *m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const CSortedArray<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>* CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getContainerPtr() const
{ CALL
  return m_cpContainer;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type& CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValueRef() const
{ CALL
  // Verify the iterator to be the valid one.
  VERIFY(isValid(), STR("Taking reference to the iterator value for invalid iterator leads to the error."));

  return m_cpContainer->m_pData[m_Index];
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline const T_Type* CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getValuePtr() const
{ CALL
  if (isValid())
    return &m_cpContainer->m_pData[m_Index];
  else
    return NULL;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator> CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::find(const T_Type& a_crItem) const
{ CALL
  // Verify the iterator container to be the valid one.
  VERIFY(isValidContainer(), STR("Cannot find given item in the sorted array with the invalid iterator container."));

  return m_cpContainer->find(a_crItem);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepForward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step forward with the invalid sorted array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, (m_cpContainer->getSize() - m_Index - 1));
  // Step forward by given steps.
  m_Index += steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepBackward(const Tuint a_cStepCount/* = 1 */)
{ CALL
  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("Cannot step backward with the invalid sorted array iterator."))
  {
    return 0;
  }

  // Get available steps count.
  Tuint steps = NAlgorithms::NCommon::min(a_cStepCount, m_Index);
  // Step forward by given steps.
  m_Index -= steps;
  // Return step count, that we have done.
  return steps;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::stepIndex(const Tuint a_cIndex)
{ CALL
  // Check if the iterator's container is in the valid state.
  ASSERT(isValidContainer(), STR("Cannot do indexed step with the invalid sorted array container."))
  {
    return false;
  }
  // Check index value and the array bounds.
  ASSERT(((a_cIndex < m_cpContainer->getSize()) || (a_cIndex == 0)), STR("Cannot do indexed step with the out of bounds index (index = %u, size = %u).") COMMA a_cIndex COMMA m_cpContainer->getSize())
  {
    return false;
  }

  m_Index = a_cIndex;
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getSize() const
{ CALL
  return (isValidContainer() ? m_cpContainer->getSize() : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::setPosition(const Tuint a_cPosition)
{ CALL
  return stepIndex(a_cPosition);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline Tuint CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::getPosition() const
{ CALL
  return (isValidContainer() ? m_Index : 0);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::load(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  WARNING(STR("Constant iterator value cannot be loaded."));
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::save(T_Archive& a_rArchive) const
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  // Check if the iterator is in the valid state.
  ASSERT(isValid(), STR("The iterator should be in the valid state to perform a serialization."))
  {
    return false;
  }

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NContainers::NIterators::CSortedArrayIterator<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(getValueRef(), STR("value")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
template <class T_Archive>
inline Tbool CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::serialize(T_Archive& a_rArchive)
{ CALL
  // Split 'serialize()' class method into 'load()' and 'save()' ones.
  return serializeSplitMethod(a_rArchive, *this);
}
/*--------------------------------------------------------------------------*/
template <typename T_Type, typename T_BinaryPredicate, class T_ResizePolicy, class T_CopyPolicy, class T_Allocator>
inline void CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>::swap(CSortedArrayIteratorConst<T_Type, T_BinaryPredicate, T_ResizePolicy, T_CopyPolicy, T_Allocator>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_cpContainer, a_rInstance.m_cpContainer);
  NAlgorithms::NCommon::swap(m_Index, a_rInstance.m_Index);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
