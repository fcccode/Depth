/*!
 *  \file    CHashTorek.hpp Chris Torek's hash function algorithm.
 *  \brief   Chris Torek's hash function algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Chris Torek's hash function algorithm.

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
#ifndef __CHASHTOREK_HPP__
#define __CHASHTOREK_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/hash/IHash.hpp>
#include <Depth/include/concept/types/MConceptDepthType.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NHash {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Chris Torek's hash function algorithm.
/*!
    Chris Torek's hash function.

    \see NDepth::NAlgorithms::NHash::CHashTorekEx
*/
class BASE_API CHashTorek :
  public IHash
{
  //! Type for the MConceptDepthType constraint checking.
  typedef CHashTorek TDepthCheckType;

  // Check CHashTorek class constraint to be a real Depth type.
  REQUIRES_CONCEPT1(NConcept::NTypes, MConceptDepthType, TDepthCheckType);

public:
  //! Default class constructor.
  CHashTorek();
  //! Class copy constructor.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTorek class.
  */
  CHashTorek(const CHashTorek& a_crInstance);
  //! Class virtual destructor.
  virtual ~CHashTorek();

  //! Operator: Assign another CHashTorek class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTorek class.
      \return Reference to the current class instance.
  */
  CHashTorek& operator = (const CHashTorek& a_crInstance);

  //! Set another CHashTorek class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CHashTorek class.
  */
  void set(const CHashTorek& a_crInstance);

  // IHash interface overriding methods.
  virtual Tuint getHash() const;
  virtual Tbool initialize(const Tuint a_cSeed = 0);
  virtual Tuint hash(Tcbuffer a_cpBuffer, const Tuint a_cSize);
  virtual Tbool close();

  //! Serialize CHashTorek class instance.
  /*!
      \param a_rArchive - Reference to the serialization archive.
      \return true  - if serialization has been successfully done. \n
              false - if serialization has not been successfully done. \n
  */
  template <class T_Archive>
  Tbool serialize(T_Archive& a_rArchive);

  //! Swap two CHashTorek class instances.
  /*!
      \param a_rInstance - Reference to another CHashTorek class instance.
  */
  void swap(CHashTorek& a_rInstance);

private:
  Tuint m_Hash;                         //!< Current hash value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/hash/CHashTorek.inl>
/*==========================================================================*/
#endif
