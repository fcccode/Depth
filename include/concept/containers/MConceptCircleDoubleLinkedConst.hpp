/*!
 *  \file    MConceptCircleDoubleLinkedConst.hpp Template checking conception.
 *           Checks if template argument is a constant double linked circle
 *           container type.
 *  \brief   Constant double linked circle container template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.10.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Constant double linked circle container template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Containers conception checking
    VERSION:   1.0
    CREATED:   04.10.2006 20:51:23

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
#ifndef __MCONCEPTCONSTCIRCLEDOUBLELINKED_HPP__
#define __MCONCEPTCONSTCIRCLEDOUBLELINKED_HPP__
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptContainerConst.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Constant double linked circle container template checking conception meta-class.
/*!
    This conception helps to constrain template  argument  to  be  a  constant
    double linked circle container.
*/
template <class T_Class>
class MConceptCircleDoubleLinkedConst :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptCircleDoubleLinkedConst();
  //! Meta-class protected destructor.
  virtual ~MConceptCircleDoubleLinkedConst();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute       m_Container;  //!< Constant double linked circle container value.
  typename NTraits::MTraitsConcept<const T_Class>::attribute m_cContainer; //!< Constant double linked circle container constant value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/containers/MConceptCircleDoubleLinkedConst.inl>
/*==========================================================================*/
#endif
