/*!
 *  \file    AToASCIILower.inl Contains implementation of the fast ASCII to
 *           lower case converting string algorithm.
 *  \brief   Fast ASCII to lower case converting string algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.11.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Fast ASCII to lower case converting string algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      String buffer algorithms
    VERSION:   1.0
    CREATED:   20.11.2009 02:33:06

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
#ifndef __ATOASCIILOWER_INL__
#define __ATOASCIILOWER_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NString {
/*--------------------------------------------------------------------------*/
namespace NBuffer {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
inline BASE_API void toASCIILower(Tsstr a_pString)
{ CALL
  toASCIILower(a_pString, a_pString, strLen(a_pString));
}
/*--------------------------------------------------------------------------*/
inline BASE_API void toASCIILower(Tsstr a_pString, const Tuint a_cSize)
{ CALL
  toASCIILower(a_pString, a_pString, a_cSize);
}
/*--------------------------------------------------------------------------*/
inline BASE_API void toASCIILower(Tsstr a_pDestination, Tcsstr a_cpSource)
{ CALL
  toASCIILower(a_pDestination, a_cpSource, strLen(a_cpSource));
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
