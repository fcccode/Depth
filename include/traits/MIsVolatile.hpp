/*!
 *  \file    MIsVolatile.hpp Traits meta-class that helps to check if given
 *           type has 'volatile' qualifier.
 *  \brief   Traits meta-class: 'volatile' qualifier appearance trait.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    10.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Traits meta-class: 'volatile' qualifier appearance trait.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Type traits
    VERSION:   1.0
    CREATED:   10.03.2006 22:36:18

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
#ifndef __MISVOLATILE_HPP__
#define __MISVOLATILE_HPP__
/*==========================================================================*/
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
//! Traits meta-class: 'volatile' qualifier appearance trait.
/*!
    Traits meta-class checks for appearance of 'volatile' qualifier  in  given
    type. Here comes some examples of using this trait:

    Expression:                                                   Result type:
    MIsVolatile<int>::yes                                         false
    MIsVolatile<volatile int>::yes                                true
    MIsVolatile<const volatile int&>::yes                         false
    MIsVolatile<const int* volatile>::yes                         true
*/
template <typename T_Type>
class MIsVolatile :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (volatile specialization).
template <typename T_Type>
class MIsVolatile<volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile specialization).
template <typename T_Type>
class MIsVolatile<const volatile T_Type> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (volatile array specialization).
template <typename T_Type>
class MIsVolatile<volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile array specialization).
template <typename T_Type>
class MIsVolatile<const volatile T_Type[]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (indexed volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsVolatile<volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (indexed constant volatile array specialization).
template <typename T_Type, Tuint t_N>
class MIsVolatile<const volatile T_Type[t_N]> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (reference specialization).
template <typename T_Type>
class MIsVolatile<T_Type&> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (pointer specialization).
template <typename T_Type>
class MIsVolatile<T_Type*> :
  public MTypeFalse
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (volatile pointer specialization).
template <typename T_Type>
class MIsVolatile<T_Type* volatile> :
  public MTypeTrue
{

};
/*--------------------------------------------------------------------------*/
//! Traits meta-class: 'volatile' qualifier appearance trait (constant volatile pointer specialization).
template <typename T_Type>
class MIsVolatile<T_Type* const volatile> :
  public MTypeTrue
{

};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
