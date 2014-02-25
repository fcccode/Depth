/*!
 *  \file    FAssume.hpp Helper function that invokes assume handler.
 *  \brief   Assume helper function.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.12.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Assume helper function.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Errors handling details
    VERSION:   1.0
    CREATED:   29.12.2006 02:24:53

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
#ifndef __FASSUME_HPP__
#define __FASSUME_HPP__
/*==========================================================================*/
#include <Depth/include/base.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NErrors {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION DECLARATIONS                                                    */
/*==========================================================================*/
//! Assume helper function.
/*!
    Assume helper function checks given condition to be 'true'.  Otherwise  it
    shows assume message for the given function signature, file name and  line
    in file. This function uses common Depth argument formatting algorithm.

    \param a_cpFunctionSignature - Function signature name, which rises the assumption.
    \param a_cpFileName - File name, from where the assumption has been risen.
    \param a_cLine - Line in file, from where the assumption has been risen.
    \param a_cCondition - Assumption condition.
    \param a_cpAssumption - Assumption expression string.
    \param a_cpMessage - Assumption message to be shown.
    \return true  - if assumption condition is valid. \n
            false - if assumption condition fails. \n
*/
BASE_API Tbool assume(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, const Tbool a_cCondition, Tcstr a_cpAssumption, Tcstr a_cpMessage, ...);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
