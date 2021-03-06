/*!
 *  \file    example-common-IClonable.cpp Example of using the IClonable
 *           interface.
 *  \brief   Example of using the IClonable interface.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    03.01.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the IClonable interface.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth common examples
    VERSION:   1.0
    CREATED:   03.01.2007 00:26:42

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
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/common/IClonable.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NCommon;
/*==========================================================================*/
class CBase :
  public IClonable<CBase>
{

};
/*--------------------------------------------------------------------------*/
class CDerived1 :
  public CBase
{
  CBase* clone() const
  { CALL
    return newex CDerived1();
  }
};
/*--------------------------------------------------------------------------*/
class CDerived2 :
  public CBase
{
  CBase* clone() const
  { CALL
    return newex CDerived2();
  }
};
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

    CBase* base_ptr = newex CDerived2();
    CBase* base_clon_ptr = base_ptr->clone();

    if (NAlgorithms::NCommon::dynamicCast<CDerived1*>(base_clon_ptr) != NULL)
      stdoutput << STR("CDerived1 clone!") << ln;
    else if (NAlgorithms::NCommon::dynamicCast<CDerived2*>(base_clon_ptr) != NULL)
      stdoutput << STR("CDerived2 clone!") << ln;
    else
      stdoutput << STR("Unknown clone!") << ln;

    delete base_ptr;
    delete base_clon_ptr;

    return IApplication::EXIT_WITH_SUCCESS;
  }
} the_Application;
/*==========================================================================*/
