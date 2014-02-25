/*!
 *  \file    FMapComparator.inl Map comparator function class.
 *  \brief   Map comparator function class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    27.09.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Map comparator function class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Function object algorithms
    VERSION:   1.0
    CREATED:   27.09.2006 20:51:42

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
#ifndef __FMAPCOMPARATOR_INL__
#define __FMAPCOMPARATOR_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NFunctions {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate>
inline FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>::FMapComparator(T_LessThanBinaryPredicate a_fLessThan/* = T_LessThanBinaryPredicate() */) :
  m_fLessThan(a_fLessThan)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate>
inline FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>::FMapComparator(const FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>& a_crInstance) :
  m_fLessThan(a_crInstance.m_fLessThan)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate>
inline Tbool FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>::operator () (const NUtility::CPair<T_Key, T_Value>& a_crArgument1, const NUtility::CPair<T_Key, T_Value>& a_crArgument2) const
{ CALL
  return m_fLessThan(a_crArgument1.getFirst(), a_crArgument2.getFirst());
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate>
template <class T_Archive>
inline Tbool FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NFunctions::FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_fLessThan, STR("m_fLessThan")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_Key, typename T_Value, typename T_LessThanBinaryPredicate>
inline void FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>::swap(FMapComparator<T_Key, T_Value, T_LessThanBinaryPredicate>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_fLessThan, a_rInstance.m_fLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
