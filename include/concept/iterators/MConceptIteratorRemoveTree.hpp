/*!
 *  \file    MConceptIteratorRemoveTree.hpp Template checking conception.
 *           Checks if template argument is a tree remove iterator type.
 *  \brief   Tree remove iterator template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    25.07.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Tree remove iterator template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   25.07.2006 02:46:27

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
#ifndef __MCONCEPTITERATORREMOVETREE_HPP__
#define __MCONCEPTITERATORREMOVETREE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorRemoveBackward.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NConcept {
/*--------------------------------------------------------------------------*/
namespace NIterators {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Tree remove iterator template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a  tree  remove
    iterator.
*/
template <class T_Class>
class MConceptIteratorRemoveTree :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptIteratorRemoveTree();
  //! Meta-class protected destructor.
  virtual ~MConceptIteratorRemoveTree();

private:
  typename NTraits::MTraitsConcept<T_Class>::attribute m_It; //!< Tree remove iterator value.
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorRemoveTree.inl>
/*==========================================================================*/
#endif
