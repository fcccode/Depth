/*!
 *  \file    CHashTorek.inl Chris Torek's hash function algorithm.
 *  \brief   Chris Torek's hash function algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Chris Torek's hash function algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Hash functions algorithms
    VERSION:   1.0
    CREATED:   10.03.2007 23:41:52

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
#ifndef __CHASHTOREK_INL__
#define __CHASHTOREK_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline CHashTorek::CHashTorek() :
  IHash(),
  m_Hash(0)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashTorek::CHashTorek(const CHashTorek& a_crInstance) :
  IHash(),
  m_Hash(a_crInstance.m_Hash)
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashTorek::~CHashTorek()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CHashTorek& CHashTorek::operator = (const CHashTorek& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline void CHashTorek::set(const CHashTorek& a_crInstance)
{ CALL
  m_Hash = a_crInstance.m_Hash;
}
/*--------------------------------------------------------------------------*/
inline Tuint CHashTorek::getHash() const
{ CALL
  return m_Hash;
}
/*--------------------------------------------------------------------------*/
inline Tbool CHashTorek::initialize(const Tuint a_cSeed/* = 0 */)
{ CALL
  m_Hash = a_cSeed;
  return true;
}
/*--------------------------------------------------------------------------*/
inline Tbool CHashTorek::close()
{ CALL
  return true;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CHashTorek::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NAlgorithms::NHash::CHashTorek")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue(m_Hash, STR("m_Hash")));
  CHECK(a_rArchive.end());
  return true;
}
/*--------------------------------------------------------------------------*/
inline void CHashTorek::swap(CHashTorek& a_rInstance)
{ CALL
  NAlgorithms::NCommon::swap(m_Hash, a_rInstance.m_Hash);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
