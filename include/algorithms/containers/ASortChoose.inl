/*!
 *  \file    ASortChoose.inl Contains general template implementation of the
 *           container minimal choose sort algorithm.
 *  \brief   Container minimal choose sort algorithm (inline).
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    20.08.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Container minimal choose sort algorithm (inline).

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Template common containers algorithms
    VERSION:   1.0
    CREATED:   20.08.2007 21:12:06

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
#ifndef __ASORTCHOOSE_INL__
#define __ASORTCHOOSE_INL__
/*==========================================================================*/
/* NAMESPACE DECLARATIONS                                                   */
/*==========================================================================*/
namespace NDepth {
/*--------------------------------------------------------------------------*/
namespace NAlgorithms {
/*--------------------------------------------------------------------------*/
namespace NContainers {
/*==========================================================================*/
/* INLINE ALGORITHM IMPLEMENTATIONS                                         */
/*==========================================================================*/
template <class T_Container>
inline Tbool sortChoose(T_Container& a_rContainer)
{ CALL
  return NIterators::sortChooseNext(getItFirst(a_rContainer));
}
/*--------------------------------------------------------------------------*/
template <class T_Container, typename T_BinaryPredicate>
inline Tbool sortChoose(T_Container& a_rContainer, T_BinaryPredicate a_fLessThan)
{ CALL
  return NIterators::sortChooseNext(getItFirst(a_rContainer), a_fLessThan);
}
/*==========================================================================*/
}
/*--------------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------------*/
}
/*==========================================================================*/
#endif
