/*!
 *  \file    AReverseCopy.hpp Contains general template implementation of the
 *           container reverse and copy all items algorithm.
 *  \brief   Container reverse and copy all items algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    29.05.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container reverse and copy all items algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   29.05.2007 20:11:52

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
#ifndef __AREVERSECOPY_HPP__
#define __AREVERSECOPY_HPP__
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AGetItFirst.hpp>
#include <Depth/include/algorithms/containers/AGetItLast.hpp>
#include <Depth/include/algorithms/iterators/AItReverseCopy.hpp>
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* ALGORITHM DECLARATIONS                                                   */
/*==========================================================================*/
//! Algorithm: Container reverse and copy all items.
/*!
    Important: All copied items will be appended  into  the  copy  container's
    end.

    \param a_rContainer - Reference to the container.
    \param a_rContainerCopy - Reference to the copy container.
    \return Count of reversed copied items.
    \see NDepth::NAlgorithms::NIterators::reverseCopyNext()
    \see NDepth::NAlgorithms::NIterators::reverseCopyPrev()
*/
template <class T_Container, class T_ContainerCopy>
Tuint reverseCopy(T_Container& a_rContainer, T_ContainerCopy& a_rContainerCopy);
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#include <Depth/include/algorithms/containers/AReverseCopy.inl>
/*==========================================================================*/
#endif
