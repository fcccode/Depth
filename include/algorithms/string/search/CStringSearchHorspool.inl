/*!
 *  \file    CStringSearchHorspool.inl Horspool (sub)string searching
 *           algorithm.
 *  \brief   Horspool (sub)string searching algorithm class (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    09.02.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Horspool (sub)string searching algorithm class (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String searching algorithms
    VERSION:   1.0
    CREATED:   09.02.2010 02:15:45

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
#ifndef __CSTRINGSEARCHHORSPOOL_INL__
#define __CSTRINGSEARCHHORSPOOL_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NSearch {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::CStringSearchHorspool(const Tbool a_cIgnoreCaseFlag/* = false */) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_cIgnoreCaseFlag)
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::CStringSearchHorspool(const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance) :
  CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::~CStringSearchHorspool()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::operator = (const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::set(const CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_crInstance)
{ CALL
  return CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::onInitialize(const T_PatternStringType& a_crPattern, const Tuint a_cPatternIndex, const Tuint a_cPatternLength)
{ CALL
  if (NDetails::CStringSearchHelper::copyPattern(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern, a_crPattern, a_cPatternIndex, a_cPatternLength))
    return calculateBadCharacterShift(IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag(), CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF, CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB);
  else
    return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::onFindNext(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint c, i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    while (j <= n - m)
    {
      c = (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + j + m - 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex + j + m - 1]);
      if (c == (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - 1]))
      {
        for (i = 0; i < m - 1; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex + i + j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex + i + j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[i])))
            break;

        if (i >= (m - 1))
        {
          a_rFoundStart = a_cSourceIndex + j;
          a_rFoundEnd = a_cSourceIndex + j + i;
          return true;
        }
      }

      typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcF.find(c);
      j += (it_const.isValid() ? it_const.getValueRef() : m);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::onFindPrev(Tuint& a_rFoundStart, Tuint& a_rFoundEnd, const T_SourceStringType& a_crSource, const Tuint a_cSourceIndex, const Tuint a_cSourceLength)
{ CALL
  if (a_cSourceLength >= CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize())
  {
    Tuint c, i, j = 0;
    Tuint n = a_cSourceLength;
    Tuint m = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern.getSize();

    while (j <= n - m)
    {
      c = (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - j - m + 1]).toLowerCase().getUnsigned() : (Tuint)a_crSource[a_cSourceIndex - j - m + 1]);
      if (c == (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)]).toLowerCase().getUnsigned() : (Tuint)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[CONSTU(0)]))
      {
        for (i = 0; i < m - 1; ++i)
          if (IStringSearch<T_SourceStringType, T_PatternStringType>::getIgnoreCaseFlag() ? (NDepth::NString::CCharacter(a_crSource[a_cSourceIndex - i - j]).toLowerCase() != NDepth::NString::CCharacter(CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1]).toLowerCase()) : (((typename NTraits::MTraitsString<T_SourceStringType>::ucharacter)a_crSource[a_cSourceIndex - i - j]) != ((typename NTraits::MTraitsString<NDepth::NString::CString>::ucharacter)CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_Pattern[m - i - 1])))
            break;

        if (i >= (m - 1))
        {
          a_rFoundStart = a_cSourceIndex - j - i;
          a_rFoundEnd = a_cSourceIndex - j;
          return true;
        }
      }

      typename CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::TCharacterTable::TIteratorConst it_const = CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::m_BMBcB.find(c);
      j += (it_const.isValid() ? it_const.getValueRef() : m);
    }
  }
  return false;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::onClose()
{ CALL
  return CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>::onClose();
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
template <class T_Archive>
inline Tbool CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NString::NSearch::CStringSearchHorspool")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), STR("base")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
template <typename T_SourceStringType, typename T_PatternStringType>
inline void CStringSearchHorspool<T_SourceStringType, T_PatternStringType>::swap(CStringSearchHorspool<T_SourceStringType, T_PatternStringType>& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap((CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)(*this), (CStringSearchBoyerMoore<T_SourceStringType, T_PatternStringType>&)a_rInstance);
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
