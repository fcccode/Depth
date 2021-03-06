/*!
 *  \file    OFlush.inl Flush stream control operator. It is used to flush
 *           stream through stream operators.
 *  \brief   Flush stream control operator (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    02.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Flush stream control operator (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   02.10.2008 01:39:54

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
#ifndef __OFLUSH_INL__
#define __OFLUSH_INL__
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
inline BASE_API IReader& operator >> (IReader& a_rReader, const flushStream& a_crFlush)
{ CALL
  IGNORE_UNUSED(a_crFlush);

  a_rReader.flush();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator > (IReader& a_rReader, const flushStream& a_crFlush)
{ CALL
  IGNORE_UNUSED(a_crFlush);

  a_rReader.flush();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IReader& operator < (IReader& a_rReader, const flushStream& a_crFlush)
{ CALL
  IGNORE_UNUSED(a_crFlush);

  a_rReader.flush();
  return a_rReader;
}
/*--------------------------------------------------------------------------*/
inline BASE_API IWriter& operator << (IWriter& a_rWriter, const flushStream& a_crFlush)
{ CALL
  IGNORE_UNUSED(a_crFlush);

  a_rWriter.flush();
  return a_rWriter;
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
