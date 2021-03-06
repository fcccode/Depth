/*!
 *  \file    AStrCat.inl Contains general template implementation of the
 *           append one string to another one.
 *  \brief   Concatenate two strings algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.04.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Concatenate two strings algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   01.04.2008 03:50:07

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
#ifndef __ASTRCAT_INL__
#define __ASTRCAT_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_StringType1, typename T_StringType2>
inline Tuint strCat(T_StringType1& a_rDstString, const T_StringType2& a_crSrcString)
{ CALL
  // Check T_StringType1 template argument constraint to be a mutable string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptString<T_StringType1> >();
  // Check T_StringType2 template argument constraint to be a constant string.
  NConcept::MConstraint::requiresConcept<NConcept::NBase::MConceptStringConst<T_StringType2> >();

  // Check the given destination string not to be NULL.
  ASSERT(((Tcptr)a_rDstString != NULL), STR("Algorithm 'strcat()' cannot work with a NULL destination string."))
  {
    return 0;
  }
  // Check the given source string not to be NULL.
  ASSERT(((Tcptr)a_crSrcString != NULL), STR("Algorithm 'strcat()' cannot work with a NULL source string."))
  {
    return 0;
  }

  Tuint indexDst = 0;
  Tuint indexSrc = 0;

  while (a_rDstString[indexDst] != 0)
    ++indexDst;
  while ((a_rDstString[indexDst] = (typename NTraits::MTraitsString<T_StringType1>::character)((typename NTraits::MTraitsString<T_StringType2>::ucharacter)a_crSrcString[indexSrc])) != 0)
  {
    ++indexDst;
    ++indexSrc;
  }
  return indexSrc;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
