/*!
 *  \file    example-containers-CBitArray.cpp Example of using the CBitArray 
 *           class.
 *  \brief   Example of using the CBitArray class.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    14.02.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the CBitArray class.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth containers examples
    VERSION:   1.0
    CREATED:   14.02.2007 20:44:22

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
#include <Depth/include/containers/CBitArray.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*==========================================================================*/
// Write instance of the CArray<Tbool> class into the given writer.
IWriter& operator << (IWriter& writer, const CArray<Tbool>& a_crArray)
{ CALL
  writer << STR("CArray<Tbool>(") << STR("size = ") << a_crArray.getSize() << STR(")") << ln;
  CArray<Tbool>::TIteratorConst it = a_crArray.getItFirst();
  if (it.isValid())
  {
    writer << STR("{") << ln;
    do
    {
      writer << STR(" item = ") << *it << ln;
    } while (it.stepForward() == 1);
    writer << STR("}") << ln;
  }
  return writer;
}
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

    CArray<Tbool> a;

    // Fill the array.
    a.insertFirst(false);
    a.insertFirst(true);
    a.insertLast(false);
    a.insertLast(true);
    a.insertIndex(2, true);

    // Show the array.
    stdoutput << a;

    // Copy the array.
    CArray<Tbool> b(a);

    // Reverse the array.
    b.reverse();

    // Show the reversed array.
    stdoutput << b;

    // Remove items from arrays.
    remove(stdoutput, a, true);
    remove(stdoutput, b, false);

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Remove all items from the instance of the CArray<Tbool> class.
  static void remove(IWriter& writer, CArray<Tbool>& a_rArray, const Tbool a_cDirectOrder)
  { CALL
    writer << STR("CArray<Tbool>(") << STR("size = ") << a_rArray.getSize() << STR(")") << ln;
    CArray<Tbool>::TIterator it = (a_cDirectOrder ? a_rArray.getItFirst() : a_rArray.getItLast());
    writer << STR("{") << ln;
    while (it.isValid())
    {
      writer << STR(" removed item = ") << *it << ln;
      a_cDirectOrder ? it.removeForward() : it.removeBackward();
    }
    writer << STR("}") << ln;
  }
} the_Application;
/*==========================================================================*/
