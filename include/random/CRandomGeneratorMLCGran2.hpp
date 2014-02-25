/*!
 *  \file    CRandomGeneratorMLCGran2.hpp Press's combined MLCG "ran2" random
 *           number generator.
 *  \brief   Press's combined MLCG "ran2" random number generator class.
 *  \author  Berndt M. Gammel (gammel@matpack.de)
 *  \version 1.0
 *  \date    25.02.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Press's combined MLCG "ran2" random number generator class.

    AUTHOR:    Berndt M. Gammel (gammel@matpack.de)
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Random
    VERSION:   1.0
    CREATED:   25.02.2009 03:52:31

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
#ifndef __CRANDOMGENERATORMLCGRAN2_HPP__
#define __CRANDOMGENERATORMLCGRAN2_HPP__
/*==========================================================================*/
#include <Depth/include/concept/types/MConceptDepthType.hpp>
#include <Depth/include/random/IRandomGenerator.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NRandom {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Press's combined MLCG "ran2" random number generator class.
/*!
    Notes:
    - William Press and Saul Teukolsky think that this is a  "perfect"  random
      generator and will pay $1000  for  the  first  one  who  convinces  them
      otherwise.
    - This generator is very slow.

    References:
    - This is the long period ( > 2.3 * 10^18 ) random number generator of
      P. L'Ecuyer, Commun. ACM 31, 743 (1988), but with Bays-Durham shuffle
      and "added safeguards" as proposed by
    - William H. Press and Saul A. Teukolsky,
      "Portable Random Number Generators",
      Computers in Phyics, Vol. 6, No. 5, Sep/Oct 1992, Algorithm "ran2"
    - This generator has been validated also by
      G. Marsaglia and A. Zaman,
      "Some portable very-long-period random number generators",
      Computers in Physics, Vol. 8, No. 1, Jan/Feb 1994.
*/
class RANDOM_API CRandomGeneratorMLCGran2 :
  public IRandomGenerator
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CRandomGeneratorMLCGran2 TDepthCheckType;

  // Check CRandomGeneratorMLCGran2 class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor. Initialize random number generator with the given seed.
  /*!
      \param a_cSeed - Random generator seed value (default is NDepth::NRandom::IRandomGenerator::getSystemSeed()).
  */
  CRandomGeneratorMLCGran2(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran2 class.
  */
  CRandomGeneratorMLCGran2(const CRandomGeneratorMLCGran2& a_crInstance);
  //! Class virtual destructor.
  virtual ~CRandomGeneratorMLCGran2();

  //! Operator: Assign another CRandomGeneratorMLCGran2 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran2 class.
      \return Reference to the current class instance.
  */
  CRandomGeneratorMLCGran2& operator = (const CRandomGeneratorMLCGran2& a_crInstance);

  //! Set another CRandomGeneratorMLCGran2 class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CRandomGeneratorMLCGran2 class.
      \return true  - if another random number generator was successfully set. \n
              false - if another random number generator was not successfully set. \n
  */
  Tbool set(const CRandomGeneratorMLCGran2& a_crInstance);

  // IRandom interface overriding methods.
  virtual Tbool setSeed(const Tuint a_cSeed = IRandomGenerator::getSystemSeed());
  virtual Tuint randomInteger();
  virtual Treal randomReal();

  //! Serialize CRandomGeneratorMLCGran2 class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CRandomGeneratorMLCGran2 class instances.
  /*!
      \param a_rInstance - Reference to another CRandomGeneratorMLCGran2 class instance.
  */
  void swap(CRandomGeneratorMLCGran2& a_rInstance);

private:
  Tsint m_idum1;                        //!< Generator state.
  Tsint m_idum2;                        //!< Generator state.
  Tsint m_iy;                           //!< Generator state.
  Tsint m_iv[32];                       //!< Generator state.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/random/CRandomGeneratorMLCGran2.inl>
/*==========================================================================*/
#endif
