/*!
 *  \file    example-string-CStringUnicode.cpp Example of using the
 *           CStringUnicode class.
 *  \brief   Example of using the CStringUnicode class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    05.08.2008
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CStringUnicode class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth string examples
    VERSION:   1.0
    CREATED:   05.08.2008 00:21:57

    EMAIL:     chronoxor@gmail.com
    WWW:       http://code.google.com/p/depth

    COPYRIGHT: (C) 2005-2010 The NULL workgroup. All Rights Reserved.
*/
/*--------------------------------------------------------------------------*/
/*
    Copyright (C) 2005-2010 The NULL workgroup.

    This program is free software; you can redistribute it  and/or  modify  it
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

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
// Common headers.
#include <Depth/include/application/IApplication.hpp>
#include <Depth/include/stream/CStreamStdOutput.hpp>
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/string/CStringUnicode.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
class CExample :
  public NApplication::IApplication
{
  Tsint main(const CStringBuffer<CString>& a_crArguments, const CStringBuffer<CString>& a_crEnvironment)
  { CALL
    IGNORE_UNUSED(a_crArguments);
    IGNORE_UNUSED(a_crEnvironment);

    // Use standard output stream of the current process.
    CStreamStdOutput stdoutput(true);

    CStringUnicode a;
    CStringUnicode b(UNC('a'));
    CStringUnicode c(UNC("abc"));
    CStringUnicode d(c);
    CStringUnicode e(CStringUnicode::EMPTY);

    a = b;
    a = UNC('a');
    a = UNC("abc");

    stdoutput << STR("CStringUnicode(UNC('a')).getSize() = ") << b.getSize() << ln;
    stdoutput << STR("CStringUnicode(UNC(\"abc\")).getSize() = ") << c.getSize() << ln;

    b.insertCEnd();
    c.insertCEnd();

    CSystemString f = b;
    CSystemString g = c;

    stdoutput << STR("CSystemString(UNC('a')).getSize() = ") << f.getSize() << ln;
    stdoutput << STR("CSystemString(UNC(\"abc\")).getSize() = ") << g.getSize() << ln;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
