/*!
 *  \file    IApplication-console-Windows.cpp Application interface provides
 *           OS independent functionality to handle console application
 *           startup.
 *  \brief   Application interface - console - Windows OS (source).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    12.01.2009
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Application interface - console - Windows OS (source).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      System
    VERSION:   1.0
    CREATED:   12.01.2009 02:12:16

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
#include <Depth/include/application.hpp>
/*--------------------------------------------------------------------------*/
#include <Depth/include/application/IApplication.hpp>
/*--------------------------------------------------------------------------*/
#include "../Windows.hpp"
/*==========================================================================*/
#ifndef __IAPPLICATION_CONSOLE_WINDOWS_CPP__
#define __IAPPLICATION_CONSOLE_WINDOWS_CPP__
/*==========================================================================*/
#if (defined(__WINDOWS__) && !defined(__WINDOWS_MOBILE__))
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NApplication {
/*==========================================================================*/
/* SYSTEM FUNCTION DECLARATIONS                                             */
/*==========================================================================*/
//! Depth application system entry point function.
/*!
    Depth application entry point function checks for  the  Depth  application
    instance and delegates them to the Depth application wrapper.

    \param a_crArguments - Constant reference to the string buffer with program arguments.
    \param a_crEnvironment - Constant reference to the string buffer with environment variables.
    \return Result of the execution which is provided to the system.
*/
Tsint systemApplicationEntryPoint(const NContainers::CStringBuffer<NString::CString>& a_crArguments, const NContainers::CStringBuffer<NString::CString>& a_crEnvironment)
{ CALL
  // Verify that application instance is created.
  VERIFY(IApplication::isCreated(), STR("Application instance must be created statically in the code."));
  // Verify that application is not already running.
  VERIFY(!IApplication::isRunning(), STR("Another application instance is already running. Cannot run application twice."));

  // Run the application instance.
  return IApplication::ms_pInstance->run(a_crArguments, a_crEnvironment);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
/* SYSTEM APPLICATION ENTRY POINT                                           */
/*==========================================================================*/
//! Windows system layer console application entry point function.
/*!
    This function will be automatically called under Windows platform when the
    console application is started. System application  entry  point  function
    collects program arguments and environment variables and delegates them to
    the Depth application wrapper.

    \param argc - Count of program arguments.
    \param argv - Pointer to an buffer of pointers to null-terminated strings that represent the program arguments.
    \param envp - Pointer to an buffer of pointers to null-terminated strings that represent the values set in the user's environment variables.
    \return Result of the execution which is provided to the system.
*/
#if defined(_UNICODE)
int wmain(int argc, wchar_t *argv[], wchar_t *envp[])
#else
int main(int argc, char *argv[], char *envp[])
#endif
{ CALL
  // Parse program arguments.
  NDepth::NContainers::CStringBuffer<NDepth::NString::CString> arguments;
  NDepth::NApplication::NDetails::CApplicationHelper::parseProgramArguments(arguments, argc, argv);

  // Parse environment variables.
  NDepth::NContainers::CStringBuffer<NDepth::NString::CString> environment;
  NDepth::NApplication::NDetails::CApplicationHelper::parseEnvironmentVariables(environment, envp);

  // Run the application.
  return (int)NDepth::NApplication::systemApplicationEntryPoint(arguments, environment);
}
/*==========================================================================*/
#else
//! Unused public function to defeat "Warning LNK4221: no public symbols found; archive member will be inaccessible".
void unused_IApplication_console_Windows() { }
#endif
#endif
