/*!
 *  \file    test-algorithms-AReplace.cpp Testing of the iterator replace
 *           algorithm.
 *  \brief   Testing of the iterator replace algorithm.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    11.06.2007
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Testing of the iterator replace algorithm.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms tests
    VERSION:   1.0
    CREATED:   11.06.2007 00:35:23

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
#include <Depth/include/algorithms/containers/AReplace.hpp>
#include <Depth/include/algorithms/containers/AReplaceIf.hpp>
#include <Depth/include/algorithms/iterators/ABoundIt.hpp>
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
  // Even number check static method.
  static Tbool isEven(const Tsint& a_crValue)
  { CALL
    return ((a_crValue & 1) == 0);
  }

  // Odd number check static method.
  static Tbool isOdd(const Tsint& a_crValue)
  { CALL
    return ((a_crValue & 1) != 0);
  }

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

    // Check replaces.
    UT_ASSERT_EQUAL(replace(array, CONSTS(2), CONSTS(200)), 1);
    UT_ASSERT_EQUAL(replacePrev(array.getItLast(), CONSTS(4), CONSTS(400)), 1);
    UT_ASSERT_EQUAL(replaceNext(boundItForward(array.getItIndex(1), array.getItIndex(4)), CONSTS(3), CONSTS(300)), 1);
    UT_ASSERT_EQUAL(replacePrev(boundItBackward(array.getItIndex(3), array.getItIndex(2)), CONSTS(300), CONSTS(3)), 1);
    UT_ASSERT_EQUAL(replace(circle, CONSTS(2), CONSTS(200)), 1);
    UT_ASSERT_EQUAL(replacePrev(circle.getItCurrent().getBackward(), CONSTS(4), CONSTS(400)), 1);
    UT_ASSERT_EQUAL(replace(list, CONSTS(2), CONSTS(200)), 1);
    UT_ASSERT_EQUAL(replacePrev(list.getItLast(), CONSTS(4), CONSTS(400)), 1);

    // Check conditional replaces.
    UT_ASSERT_EQUAL(replaceIf(array, CONSTS(1), isOdd), 3);
    UT_ASSERT_EQUAL(replaceIfPrev(array.getItLast(), CONSTS(2), isEven), 3);
    UT_ASSERT_EQUAL(replaceIfNext(boundItForward(array.getItIndex(1), array.getItIndex(4)), CONSTS(1), isOdd), 2);
    UT_ASSERT_EQUAL(replaceIfPrev(boundItBackward(array.getItIndex(3), array.getItIndex(2)), CONSTS(2), isEven), 1);
    UT_ASSERT_EQUAL(replaceIf(circle, CONSTS(1), isOdd), 3);
    UT_ASSERT_EQUAL(replaceIfPrev(circle.getItCurrent().getBackward(), CONSTS(2), isEven), 3);
    UT_ASSERT_EQUAL(replaceIf(list, CONSTS(1), isOdd), 3);
    UT_ASSERT_EQUAL(replaceIfPrev(list.getItLast(), CONSTS(2), isEven), 3);

    UT_ACCEPT;
  }
} the_Test;
/*==========================================================================*/
