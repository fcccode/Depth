/*!
 *  \file    OFormat.inl Format stream control operator. It is used to
 *           format output or unformat input through stream operators.
 *  \brief   Format stream control operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Format stream control operator (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 23:08:59

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
#ifndef __OFORMAT_INL__
#define __OFORMAT_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* INLINE OPERATOR IMPLEMENTATIONS                                          */
/*==========================================================================*/
inline format::format(const Tcsstr a_cpFormatString, ...) :
  m_Type(0),
  m_FormatBufferASCII(a_cpFormatString),
  m_FormatBufferUnicode(NULL),
  m_FormatStringASCII(),
  m_FormatStringUnicode(),
  m_VariableList()
{ CALL
  va_start(m_VariableList, a_cpFormatString);
}
/*--------------------------------------------------------------------------*/
inline format::format(const Tcwstr a_cpFormatString, ...) :
  m_Type(1),
  m_FormatBufferASCII(NULL),
  m_FormatBufferUnicode(a_cpFormatString),
  m_FormatStringASCII(),
  m_FormatStringUnicode(),
  m_VariableList()
{ CALL
  va_start(m_VariableList, a_cpFormatString);
}
/*--------------------------------------------------------------------------*/
inline format::format(const NString::CStringASCII* a_cpFormatString, ...) :
  m_Type(2),
  m_FormatBufferASCII(NULL),
  m_FormatBufferUnicode(NULL),
  m_FormatStringASCII(*a_cpFormatString),
  m_FormatStringUnicode(),
  m_VariableList()
{ CALL
  va_start(m_VariableList, a_cpFormatString);
}
/*--------------------------------------------------------------------------*/
inline format::format(const NString::CStringUnicode* a_cpFormatString, ...) :
  m_Type(3),
  m_FormatBufferASCII(NULL),
  m_FormatBufferUnicode(NULL),
  m_FormatStringASCII(),
  m_FormatStringUnicode(*a_cpFormatString),
  m_VariableList()
{ CALL
  va_start(m_VariableList, a_cpFormatString);
}
/*--------------------------------------------------------------------------*/
inline format::~format()
{ CALL
  va_end(m_VariableList);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
