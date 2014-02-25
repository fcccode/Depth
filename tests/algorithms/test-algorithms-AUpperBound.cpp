/*!
 *  \file    test-algorithms-AUpperBound.cpp Testing of the upper bound 
 *           algorithm.
 *  \brief   Testing of the upper bound algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    16.03.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the upper bound algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   16.03.2007 03:14:24

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
#include "unit-test.hpp"
/*--------------------------------------------------------------------------*/
// Specific headers.
#include <Depth/include/algorithms/containers/AUpperBound.hpp>
#include <Depth/include/containers/CArray.hpp>
#include <Depth/include/containers/CListDC.hpp>
#include <Depth/include/containers/CListDL.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NUnitTest;
/*--------------------------------------------------------------------------*/
// Specific namespaces.
using namespace NDepth::NAlgorithms::NContainers;
using namespace NDepth::NAlgorithms::NIterators;
using namespace NDepth::NContainers;
/*==========================================================================*/
class CTest :
  public CUnitTest
{
  // Launch unit test.
  EUnitTestResult test()
  { CALL
    CArray<Tsint> array;
    CListDC<Tsint> circle;
    CListDL<Tsint> list;

    // Fill the array.
    UT_ASSERT(array.insertLast(1));
    UT_ASSERT(array.insertLast(2));
    UT_ASSERT(array.insertLast(3));
    UT_ASSERT(array.insertLast(4));
    UT_ASSERT(array.insertLast(5));
    UT_ASSERT(array.insertLast(6));

    // Fill the double circled list.
    UT_ASSERT(circle.insertCurrentForward(1));
    UT_ASSERT(circle.insertNext(6));
    UT_ASSERT(circle.insertNext(5));
    UT_ASSERT(circle.insertNext(4));
    UT_ASSERT(circle.insertNext(3));
    UT_ASSERT(circle.insertNext(2));

    // Fill the double linked list.
    UT_ASSERT(list.insertLast(1));
    UT_ASSERT(list.insertLast(2));
    UT_ASSERT(list.insertLast(3));
    UT_ASSERT(list.insertLast(4));
    UT_ASSERT(list.insertLast(5));
    UT_ASSERT(list.insertLast(6));

    // Check upper bounds.
    UT_ASSERT(!upperBound(array, CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBound(array, CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBound(array, CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBound(array, CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBound(array, CONSTS(8)).getValueRef(), 6);
    UT_ASSERT(!upperBoundPrev(array.getItLast(), CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBoundPrev(array.getItLast(), CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBoundPrev(array.getItLast(), CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBoundPrev(array.getItLast(), CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBoundPrev(array.getItLast(), CONSTS(8)).getValueRef(), 6);
    UT_ASSERT(!upperBound(circle, CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBound(circle, CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBound(circle, CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBound(circle, CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBound(circle, CONSTS(8)).getValueRef(), 6);
    UT_ASSERT(!upperBoundPrev(circle.getItCurrent().getBackward(), CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBoundPrev(circle.getItCurrent().getBackward(), CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBoundPrev(circle.getItCurrent().getBackward(), CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBoundPrev(circle.getItCurrent().getBackward(), CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBoundPrev(circle.getItCurrent().getBackward(), CONSTS(8)).getValueRef(), 6);
    UT_ASSERT(!upperBound(list, CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBound(list, CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBound(list, CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBound(list, CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBound(list, CONSTS(8)).getValueRef(), 6);
    UT_ASSERT(!upperBoundPrev(list.getItLast(), CONSTS(0)).isValid());
    UT_ASSERT_EQUAL(upperBoundPrev(list.getItLast(), CONSTS(1)).getValueRef(), 1);
    UT_ASSERT_EQUAL(upperBoundPrev(list.getItLast(), CONSTS(4)).getValueRef(), 4);
    UT_ASSERT_EQUAL(upperBoundPrev(list.getItLast(), CONSTS(6)).getValueRef(), 6);
    UT_ASSERT_EQUAL(upperBoundPrev(list.getItLast(), CONSTS(8)).getValueRef(), 6);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
