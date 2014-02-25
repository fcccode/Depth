/*!
 *  \file    CBooleanMaker.hpp Utility class that helps to make CBoolean
 *           instances from specified values.
 *  \brief   Boolean maker class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.03.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Boolean maker class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Base
    VERSION:   1.0
    CREATED:   03.03.2006 03:14:26

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
#ifndef __CBOOLEANMAKER_HPP__
#define __CBOOLEANMAKER_HPP__
/*==========================================================================*/
#include <Depth/include/base/CBoolean.hpp>
#include <Depth/include/common/IStatic.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NBase {
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
//! Boolean maker class.
/*!
    With this utility class template CBoolean instances can  be  made  without
    specifying template arguments.
*/
class BASE_API CBooleanMaker :
  public NDepth::NCommon::IStatic
{
public:
  //! Make CBoolean instance from specified boolean value.
  /*!
      \param a_cValue - Boolean value.
      \return CBoolean class instance.
  */
  template <typename T_Type>
  static CBoolean<T_Type> make(const T_Type a_cValue);
  //! Make CBoolean instance from specified CBoolean class instance.
  /*!
      \param a_crInstance - Constant reference to another instance of the CBoolean class.
      \return CBoolean class instance.
  */
  template <typename T_Type>
  static CBoolean<T_Type> make(const CBoolean<T_Type>& a_crInstance);
};
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/base/CBooleanMaker.inl>
/*==========================================================================*/
#endif
