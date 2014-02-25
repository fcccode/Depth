/*!
 *  \file    CMethodLoadChooser.inl Serialization helper class that wraps
 *           'load()' class method call during the serialization splitting
 *           operation for the 'serialize()' method.
 *  \brief   Serialization 'load()' method chooser helper class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Serialization 'load()' method chooser helper class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Serialization details
    VERSION:   1.0
    CREATED:   05.01.2007 23:50:38

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
#ifndef __CMETHODLOADCHOOSER_INL__
#define __CMETHODLOADCHOOSER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NSerialization {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
template <class T_Archive, class T_Class>
inline Tbool CMethodLoadChooser<T_Archive, T_Class>::invoke(T_Archive& a_rArchive, T_Class& a_rInstance)
{ CALL
  // Check T_Archive template argument to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();
  // Check T_Class template argument to be a serializable type.
  NConcept::MConstraint::requiresConcept<NConcept::NClass::MConceptSerializable<T_Class> >();

  // Invoke 'load()' class method.
  return a_rInstance.load(a_rArchive);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
