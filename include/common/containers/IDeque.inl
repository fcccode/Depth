/*!
 *  \file    IDeque.inl Base interface for all non constant deque based
 *           containers. It gives ability to manipulate with the non
 *           constant deque container.
 *  \brief   Non constant deque container interface (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.02.2006
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Non constant deque container interface (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Common containers
    VERSION:   1.0
    CREATED:   20.02.2006 03:55:04

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
#ifndef __IDEQUE_INL__
#define __IDEQUE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NCommon {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE INTERFACE IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
inline IDeque<T_Container, T_Type, T_Iterator, T_IteratorConst>::IDeque() :
  IQueue<T_Container, T_Type, T_Iterator, T_IteratorConst>()
{ CALL

}
/*--------------------------------------------------------------------------*/
template <class T_Container, typename T_Type, class T_Iterator, class T_IteratorConst>
inline IDeque<T_Container, T_Type, T_Iterator, T_IteratorConst>::~IDeque()
{ CALL

}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
