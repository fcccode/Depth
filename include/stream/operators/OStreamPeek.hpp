/*!
 *  \file    OStreamPeek.hpp Set of the stream peek operators are used to
 *           peek common values (character, string, boolean, integer, real,
 *           pointer) from the stream.
 *  \brief   Stream peek operators.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    01.10.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Stream peek operators.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Stream operators
    VERSION:   1.0
    CREATED:   01.10.2008 03:51:47

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
#ifndef __OSTREAMPEEK_HPP__
#define __OSTREAMPEEK_HPP__
/*==========================================================================*/
#include <Depth/include/stream/IReader.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NStream {
/*--------------------------------------------------------------------------*/
namespace NOperators {
/*==========================================================================*/
/* OPERATOR DECLARATIONS                                                    */
/*==========================================================================*/
//! Operator: Peek ASCII character from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rCharacter - Reference to the ASCII character.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tschar& a_rCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Peek Unicode character from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rCharacter - Reference to the Unicode character.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Twchar& a_rCharacter);
/*--------------------------------------------------------------------------*/
//! Operator: Peek ASCII zero terminated C string from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rpString - Reference to the ASCII zero terminated C string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tsstr& a_rpString);
/*--------------------------------------------------------------------------*/
//! Operator: Peek Unicode zero terminated C string from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rpString - Reference to the Unicode zero terminated C string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Twstr& a_rpString);
/*--------------------------------------------------------------------------*/
//! Operator: Peek ASCII string from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rString - Reference to the ASCII string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, NString::CStringASCII& a_rString);
/*--------------------------------------------------------------------------*/
//! Operator: Peek Unicode string from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rString - Reference to the Unicode string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, NString::CStringUnicode& a_rString);
/*--------------------------------------------------------------------------*/
//! Operator: Peek system string from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rString - Reference to the system string.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, NString::CSystemString& a_rString);
/*--------------------------------------------------------------------------*/
//! Operator: Peek boolean number value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rBoolean - Reference to the boolean number.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tbool& a_rBoolean);
/*--------------------------------------------------------------------------*/
//! Operator: Peek signed 1 byte integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the signed 1 byte integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tsint08& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek unsigned 1 byte integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the unsigned 1 byte integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tuint08& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek signed 2 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the signed 2 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tsint16& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek unsigned 2 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the unsigned 2 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tuint16& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek signed 4 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the signed 4 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tsint32& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek unsigned 4 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the unsigned 4 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tuint32& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek signed 8 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the signed 8 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tsint64& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek unsigned 8 bytes integer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rInteger - Reference to the unsigned 8 bytes integer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tuint64& a_rInteger);
/*--------------------------------------------------------------------------*/
//! Operator: Peek single accuracy real value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rReal - Reference to the single accuracy real value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tfloat& a_rReal);
/*--------------------------------------------------------------------------*/
//! Operator: Peek double accuracy real value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rReal - Reference to the double accuracy real value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tdouble& a_rReal);
/*--------------------------------------------------------------------------*/
//! Operator: Peek pointer value from the given reader.
/*!
    \param a_rReader - Reference to the instance of the IReader interface.
    \param a_rpPointer - Reference to the pointer value.
    \return Reference to the instance of the IReader interface.
    \see NDepth::NStream::IReader::peek()
*/
IReader& operator > (IReader& a_rReader, Tptr& a_rpPointer);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/stream/operators/OStreamPeek.inl>
/*==========================================================================*/
#endif
