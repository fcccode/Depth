/*!
 *  \file    CDistributionUniform.inl Uniform distribution class.
 *  \brief   Uniform distribution class (inline).
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    05.03.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Uniform distribution class (inline).

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Statistic
    VERSION:   1.0
    CREATED:   05.03.2009 03:20:37

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
#ifndef __CDISTRIBUTIONUNIFORM_INL__
#define __CDISTRIBUTIONUNIFORM_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStatistic {
/*==========================================================================*/
/* INLINE CLASS IMPLEMENTATIONS                                             */
/*==========================================================================*/
inline CDistributionUniform::CDistributionUniform(const Treal a_cA/* = CONSTR(0.0) */, const Treal a_cB/* = CONSTR(1.0) */, NRandom::IRandomGenerator* a_pIRandomGenerator/* = NULL */) :
  IDistribution(a_pIRandomGenerator)
{ CALL
  setParameters(a_cA, a_cB);
}
/*--------------------------------------------------------------------------*/
inline CDistributionUniform::CDistributionUniform(const CDistributionUniform& a_crInstance) :
  IDistribution(a_crInstance)
{ CALL
  set(a_crInstance);
}
/*--------------------------------------------------------------------------*/
inline CDistributionUniform::~CDistributionUniform()
{ CALL

}
/*--------------------------------------------------------------------------*/
inline CDistributionUniform& CDistributionUniform::operator = (const CDistributionUniform& a_crInstance)
{ CALL
  set(a_crInstance);
  return *this;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionUniform::getA() const
{ CALL
  return m_A;
}
/*--------------------------------------------------------------------------*/
inline Treal CDistributionUniform::getB() const
{ CALL
  return m_B;
}
/*--------------------------------------------------------------------------*/
template <class T_Archive>
inline Tbool CDistributionUniform::serialize(T_Archive& a_rArchive)
{ CALL
  // Check T_Archive template template argument constraint to be a serialization archive.
  NConcept::MConstraint::requiresConcept<NConcept::NTypes::MConceptIArchive<T_Archive> >();

  Tuint version = 1;
  CHECK(a_rArchive.begin(version, STR("NDepth::NStatistic::CDistributionUniform")));
  CHECK(a_rArchive.body());
    CHECK(a_rArchive.doValue((IDistribution&)(*this), STR("base")));
    CHECK(a_rArchive.doValue(m_A, STR("m_A")));
    CHECK(a_rArchive.doValue(m_B, STR("m_B")));
  CHECK(a_rArchive.end());
  return true;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
