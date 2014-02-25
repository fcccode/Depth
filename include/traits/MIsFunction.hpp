/*!
 *  \file    MIsFunction.hpp Traits meta-class that helps to check if given
 *           type is a function.
 *  \brief   Traits meta-class: function type checking trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: function type checking trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   12.03.2006 01:28:43

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
#ifndef __MISFUNCTION_HPP__
#define __MISFUNCTION_HPP__
/*==========================================================================*/
#include <Depth/include/traits/MIfThenElse.hpp>
#include <Depth/include/traits/MTraitsFunction.hpp>
#include <Depth/include/traits/MTypeTrue.hpp>
#include <Depth/include/traits/MTypeFalse.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NTraits {
/*==========================================================================*/
/* META-CLASS DECLARATIONS                                                  */
/*==========================================================================*/
//! Traits meta-class: function type checking trait.
/*!
    Traits meta-class checks if template arguments is a  function  type.  Here
    comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsFunction<int>::yes                                         false
    MIsFunction<int (const int)>::yes                             true
    MIsFunction<int (*)(const int)>::yes                          true
*/
template <typename T_Type>
class MIsFunction :
  public MIfThenElse<MTraitsFunction<T_Type>::isFunction, MTypeTrue, MTypeFalse>::type
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
