/*!
 *  \file    MConceptContainer.inl Template checking conception. Checks if
 *           template argument is a non constant container type.
 *  \brief   Non constant container template checking conception (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant container template checking conception (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   20.09.2006 02:56:36

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
#ifndef __MCONCEPTCONTAINER_INL__
#define __MCONCEPTCONTAINER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE META-CLASS IMPLEMENTATIONS                                        */
/*==========================================================================*/
template <class T_Class>
inline MConceptContainer<T_Class>::MConceptContainer() :
  MConcept()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline MConceptContainer<T_Class>::~MConceptContainer()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Class>
inline void MConceptContainer<T_Class>::constraints()
{ CALL
  Tbool result;

  // Check for the non constant container's operators.
  m_Container = m_Container;

  // Check for the non constant associative container's methods.
  result = m_Container.clear();
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
