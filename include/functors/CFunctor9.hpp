/*!
 *  \file    CFunctor9.hpp Functor class emulates an object that can be called
 *           as a function with 'operator()'. Version with 9 arguments.
 *  \brief   Functor class with 9 arguments.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    04.05.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Functor class with 9 arguments.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Functors
    VERSION:   1.0
    CREATED:   04.05.2006 22:03:43

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
#ifndef __CFUNCTOR9_HPP__
#define __CFUNCTOR9_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/common/ACast.hpp>
#include <Depth/include/algorithms/common/ASwap.hpp>
#include <Depth/include/concept/functions/MConceptAnyFunction9.hpp>
#include <Depth/include/functors/details/IFunctorX.hpp>
#include <Depth/include/functors/details/CFunctorHelperX.hpp>
#include <Depth/include/traits/functions/MRemoveFunctionPtr9.hpp>
#include <Depth/include/utility/observer/IObserver.hpp>
/*==========================================================================*/
/* CLASS DECLARATIONS                                                       */
/*==========================================================================*/
#define DEF_FUNCTOR_ARITY                        9
#define DEF_FUNCTOR_DECLARATION(name)            JOIN(name, DEF_FUNCTOR_ARITY)
#define DEF_TEMPLATE_DECLARATION                 typename T_Result, typename T_Argument1, typename T_Argument2, typename T_Argument3, typename T_Argument4, typename T_Argument5, typename T_Argument6, typename T_Argument7, typename T_Argument8, typename T_Argument9
#define DEF_TEMPLATE_PARAMETERS                  T_Result, T_Argument1, T_Argument2, T_Argument3, T_Argument4, T_Argument5, T_Argument6, T_Argument7, T_Argument8, T_Argument9
#define DEF_TEMPLATE_OTHER_DECLARATION           typename T_OtherResult, typename T_OtherArgument1, typename T_OtherArgument2, typename T_OtherArgument3, typename T_OtherArgument4, typename T_OtherArgument5, typename T_OtherArgument6, typename T_OtherArgument7, typename T_OtherArgument8, typename T_OtherArgument9
#define DEF_TEMPLATE_OTHER_PARAMETERS            T_OtherResult, T_OtherArgument1, T_OtherArgument2, T_OtherArgument3, T_OtherArgument4, T_OtherArgument5, T_OtherArgument6, T_OtherArgument7, T_OtherArgument8, T_OtherArgument9
#define DEF_CALL_DECLARATION                     T_Argument1 a_Argument1, T_Argument2 a_Argument2, T_Argument3 a_Argument3, T_Argument4 a_Argument4, T_Argument5 a_Argument5, T_Argument6 a_Argument6, T_Argument7 a_Argument7, T_Argument8 a_Argument8, T_Argument9 a_Argument9
#define DEF_CALL_PARAMETERS                      a_Argument1, a_Argument2, a_Argument3, a_Argument4, a_Argument5, a_Argument6, a_Argument7, a_Argument8, a_Argument9
/*--------------------------------------------------------------------------*/
#include <Depth/include/functors/details/templates/IFunctor.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperFunction.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethod.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodConst.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperMethodConstVolatile.hpp.tpl>
#include <Depth/include/functors/details/templates/CFunctorHelperX.hpp.tpl>
/*--------------------------------------------------------------------------*/
#define DEF_TEMPLATE_SPECIALIZATION              T_Result (DEF_CALL_DECLARATION)
#include <Depth/include/functors/details/templates/CFunctorHelper.hpp.tpl>
#undef DEF_TEMPLATE_SPECIALIZATION
/*--------------------------------------------------------------------------*/
#undef DEF_FUNCTOR_ARITY
#undef DEF_FUNCTOR_DECLARATION
#undef DEF_TEMPLATE_DECLARATION
#undef DEF_TEMPLATE_PARAMETERS
#undef DEF_TEMPLATE_OTHER_DECLARATION
#undef DEF_TEMPLATE_OTHER_PARAMETERS
#undef DEF_CALL_DECLARATION
#undef DEF_CALL_PARAMETERS
/*==========================================================================*/
#include <Depth/include/functors/CFunctorX.hpp>
/*==========================================================================*/
#endif
