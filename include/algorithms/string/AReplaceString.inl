/*!
 *  \file    AReplaceString.inl Contains general template implementation of
 *           the algorithm to find and replace (sub)string in the given string
 *           object using Brute Force searching algorithm.
 *  \brief   Algorithm to find and replace (sub)string in the given string using Brute Force searching algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Algorithm to find and replace (sub)string in the given string using Brute Force searching algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String algorithms
    VERSION:   1.0
    CREATED:   11.01.2010 20:42:42

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
#ifndef __AREPLACESTRING_INL__
#define __AREPLACESTRING_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const T_PatternStringType& a_crPattern, const T_ReplacePatternStringType& a_crReplacePattern)
{ CALL
  if (a_cReverseSearch)
    return replaceString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_rSource, NConstants::CConstants::uintMax, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax);
  else
    return replaceString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_rSource, 0, NConstants::CConstants::uintMax, a_crPattern, 0, NConstants::CConstants::uintMax, a_crReplacePattern, 0, NConstants::CConstants::uintMax);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternLength)
{ CALL
  if (a_cReverseSearch)
    return replaceString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_rSource, NConstants::CConstants::uintMax, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength);
  else
    return replaceString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_rSource, 0, a_cSourceLength, a_crPattern, 0, a_cPatternLength, a_crReplacePattern, 0, a_cReplacePatternLength);
}
/*--------------------------------------------------------------------------*/
template <class T_SourceStringClass, typename T_PatternStringType, typename T_ReplacePatternStringType>
inline Tbool replaceString(const Tbool a_cReverseSearch, const Tbool a_cIgnoreCase, Tuint& a_rFoundStart, Tuint& a_rFoundEnd, T_SourceStringClass& a_rSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength, const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength, const T_ReplacePatternStringType& a_crReplacePattern, const Tuint a_cReplacePatternIndex, const Tuint a_cReplacePatternLength)
{ CALL
  // Check T_SourceStringClass template argument constraint to be a non constant string class.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIString<T_SourceStringClass> >();

  // Prepare replace pattern.
  T_SourceStringClass replace_pattern;
  if (!NDetails::CStringSearchHelper::copyPattern(replace_pattern, a_crReplacePattern, a_cReplacePatternIndex, a_cReplacePatternLength))
    return false;

  // Try to find and replace the given pattern string.
  if (findString(a_cReverseSearch, a_cIgnoreCase, a_rFoundStart, a_rFoundEnd, a_rSource, a_cSourceIndex, a_cSourceLength, a_crPattern, a_cPatternIndex, a_cPatternLength))
    return a_rSource.replace(a_rFoundStart, a_rFoundEnd - a_rFoundStart + 1, replace_pattern);
  else
    return false;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
