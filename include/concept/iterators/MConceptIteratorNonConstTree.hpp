/*!
 *  \file    MConceptIteratorNonConstTree.hpp Template checking conception.
 *           Checks if template argument is a non constant tree iterator
 *           type.
 *  \brief   Non constant tree iterator template checking conception.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    23.06.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant tree iterator template checking conception.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Iterators conception checking
    VERSION:   1.0
    CREATED:   23.06.2006 23:07:37

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
#ifndef __MCONCEPTITERATORNONCONSTTREE_HPP__
#define __MCONCEPTITERATORNONCONSTTREE_HPP__
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorNonConst.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorInsertTree.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorMoveTree.hpp>
#include <Depth/include/concept/iterators/MConceptIteratorRemoveTree.hpp>
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
//! Non constant tree iterator template checking conception meta-class.
/*!
    This conception helps to constrain template argument to be a non  constant
    tree iterator.
*/
template <class T_Class>
class MConceptIteratorNonConstTree :
  public MConcept
{
public:
  // MConcept meta-class overriding method.
  virtual void constraints();

protected:
  //! Default template checking conception meta-class protected constructor.
  MConceptIteratorNonConstTree();
  //! Meta-class protected destructor.
  virtual ~MConceptIteratorNonConstTree();
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/concept/iterators/MConceptIteratorNonConstTree.inl>
/*==========================================================================*/
#endif
