/*!
 *  \file    FUnitTestLog.cpp Helper function that invokes unit test logging
 *           handler.
 *  \brief   Unit test logging helper function (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    22.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Unit test logging helper function (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Unit test details
    VERSION:   1.0
    CREATED:   22.01.2009 20:21:13

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
#include <Depth/include/unit.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/stream/text/CStreamString.hpp>
#include <Depth/include/unit/CUnitTestLauncher.hpp>
#include <Depth/include/unit/details/FUnitTestLog.hpp>
/*==========================================================================*/
#ifndef __FUNITTESTLOG_CPP__
#define __FUNITTESTLOG_CPP__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NUnitTest {
/*--------------------------------------------------------------------------*/
namespace NDetails {
/*==========================================================================*/
/* FUNCTION IMPLEMENTATIONS                                                 */
/*==========================================================================*/
UNITTEST_API void unitTestLog(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcsstr a_cpMessage, ...)
{ CALL
  // Check if the current unit test launcher is created.
  ASSERT(CUnitTestLauncher::isCreated(), STR("Unit test launcher is not created."))
  {
    return;
  }

  // Prepare string stream for output.
  NStream::NText::CStreamString message;
  if (!message.open(NStream::IStream::e_OPEN_WRITE))
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }

  // Output logging message in the following format:
  //   Log:\n
  //   Function\n
  //   FileName line X\n\n
  //   Message\n\n
  va_list variable_list;
  va_start(variable_list, a_cpMessage);
  if (!message.write(STR("Log:")).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.write(a_cpFunctionSignature).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.write(a_cpFileName).getFirst() ||
      !message.write(STR(" line ")).getFirst() ||
      !message.write(a_cLine).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeFormatVarList(a_cpMessage, variable_list).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeLineEnd().getFirst())
  {
    va_end(variable_list);
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }
  else
    va_end(variable_list);

  // Close string stream.
  if (!message.close())
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }

  // Call log message notification of the current unit test launcher.
  if (!CUnitTestLauncher::ms_pInstance->onLog(message))
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }
}
/*--------------------------------------------------------------------------*/
UNITTEST_API void unitTestLog(Tcsstr a_cpFunctionSignature, Tcstr a_cpFileName, const Tuint a_cLine, Tcwstr a_cpMessage, ...)
{ CALL
  // Check if the current unit test launcher is created.
  ASSERT(CUnitTestLauncher::isCreated(), STR("Unit test launcher is not created."))
  {
    return;
  }

  // Prepare string stream for output.
  NStream::NText::CStreamString message;
  if (!message.open(NStream::IStream::e_OPEN_WRITE))
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }

  // Output logging message in the following format:
  //   Log:\n
  //   Function\n
  //   FileName line X\n\n
  //   Message\n\n
  va_list variable_list;
  va_start(variable_list, a_cpMessage);
  if (!message.write(STR("Log:")).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.write(a_cpFunctionSignature).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.write(a_cpFileName).getFirst() ||
      !message.write(STR(" line ")).getFirst() ||
      !message.write(a_cLine).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeFormatVarList(a_cpMessage, variable_list).getFirst() ||
      !message.writeLineEnd().getFirst() ||
      !message.writeLineEnd().getFirst())
  {
    va_end(variable_list);
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }
  else
    va_end(variable_list);

  // Close string stream.
  if (!message.close())
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }

  // Call log message notification of the current unit test launcher.
  if (!CUnitTestLauncher::ms_pInstance->onLog(message))
  {
    CUnitTestLauncher::ms_pInstance->setUnitTestResult(e_TEST_STOPPED);
    return;
  }
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
