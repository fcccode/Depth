/*!
 *  \file    MConceptIteratorRemoveBackward.inl Template checking conception.
 *           Checks if template argument is a backward remove iterator type.
 *  \brief   Backward remove iterator template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Backward remove iterator template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   16.02.2006 02:49:26

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
#ifndef __MCONCEPTITERATORREMOVEBACKWARD_INL__
#define __MCONCEPTITERATORREMOVEBACKWARD_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptIteratorRemoveBackward<T_Class>::MConceptIteratorRemoveBackward() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptIteratorRemoveBackward<T_Class>::~MConceptIteratorRemoveBackward()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptIteratorRemoveBackward<T_Class>::constraints()
{ CALL
  // Check T_Class template argument constraint to be a forward remove iterator.
  MConstraint::requiresConcept<MConceptIteratorRemoveForward<T_Class> >();

  Tbool result;

  // Check for the backward remove iterator types.
  typename T_Class::TType item;

  // Check for the backward remove iterator methods.
  result = m_It.removeBackward();
  result = m_It.removeBackward(item);
  result = m_It.removePrev();
  result = m_It.removePrev(item);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
