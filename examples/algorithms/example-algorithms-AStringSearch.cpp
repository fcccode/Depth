/*!
 *  \file    example-algorithms-AStringSearch.cpp Example of using the string
 *           searching algorithms.
 *  \brief   Example of using the string searching algorithms.
 *  \author  Ivan Shynkarenka aka 4ekucT
 *  \version 1.0
 *  \date    06.01.2010
 */
/*==========================================================================*/
/*
    FILE DESCRIPTION: Example of using the string searching algorithms.

    AUTHOR:    Ivan Shynkarenka aka 4ekucT
    GROUP:     The NULL workgroup
    PROJECT:   The Depth
    PART:      Depth algorithms examples
    VERSION:   1.0
    CREATED:   06.01.2010 02:04:42

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
#include <Depth/include/algorithms/string/AStringSearch.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBruteForce.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchKarpRabin.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchMorrisPratt.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchKnuthMorrisPratt.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoCrochemore.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchNotSoNaive.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchBoyerMoore.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchTunedBM.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchTurboBM.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchApostolicoGiancarlo.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchHorspool.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchQuickSearch.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchSmith.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchRaita.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchDFA.hpp>
#include <Depth/include/algorithms/string/search/CStringSearchOneOf.hpp>
/*==========================================================================*/
// Common namespaces.
using namespace NDepth;
using namespace NDepth::NApplication;
using namespace NDepth::NContainers;
using namespace NDepth::NStream;
using namespace NDepth::NString;
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

    // Example of the usage of the string searching algorithms.
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(false), CString(STR("Brute Force algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchBruteForce<CString>(true), CString(STR("Brute Force algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(false), CString(STR("Karp-Rabin algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchKarpRabin<CString>(true), CString(STR("Karp-Rabin algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(false), CString(STR("Morris-Pratt algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchMorrisPratt<CString>(true), CString(STR("Morris-Pratt algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(false), CString(STR("Knuth-Morris-Pratt algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchKnuthMorrisPratt<CString>(true), CString(STR("Knuth-Morris-Pratt algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(false), CString(STR("Apostolico-Crochemore algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchApostolicoCrochemore<CString>(true), CString(STR("Apostolico-Crochemore algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(false), CString(STR("Not So Naive algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchNotSoNaive<CString>(true), CString(STR("Not So Naive algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(false), CString(STR("Boyer-Moore algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchBoyerMoore<CString>(true), CString(STR("Boyer-Moore algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(false), CString(STR("Tuned Boyer-Moore algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchTunedBM<CString>(true), CString(STR("Tuned Boyer-Moore algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(false), CString(STR("Turbo Boyer-Moore algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchTurboBM<CString>(true), CString(STR("Turbo Boyer-Moore algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(false), CString(STR("Apostolico-Giancarlo algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchApostolicoGiancarlo<CString>(true), CString(STR("Apostolico-Giancarlo algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(false), CString(STR("Horspool algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchHorspool<CString>(true), CString(STR("Horspool algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(false), CString(STR("Quick Search algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchQuickSearch<CString>(true), CString(STR("Quick Search algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(false), CString(STR("Smith algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchSmith<CString>(true), CString(STR("Smith algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(false), CString(STR("Raita algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchRaita<CString>(true), CString(STR("Raita algorithm - ignore case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(false), CString(STR("Deterministic Finite Automaton algorithm - regard case")));
    search(stdoutput, NAlgorithms::NString::NSearch::CStringSearchDFA<CString>(true), CString(STR("Deterministic Finite Automaton algorithm - ignore case")));

    return IApplication::EXIT_WITH_SUCCESS;
  }

  // Perform string searching with the given algorithm.
  template <typename T_StringSearchAlgorithm>
  static void search(IWriter& writer, T_StringSearchAlgorithm a_StringSearchAlgorithm, const CString& a_crAlgorithmName)
  { CALL
    writer << STR("Search with ") << a_crAlgorithmName << STR("...") << ln;

    Tbool result;
    Tuint start, end;
    CString source, pattern;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("11"));
    writer << STR("Try to forward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sz"));
    writer << STR("Try to forward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sZ"));
    writer << STR("Try to forward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchNext(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("11"));
    writer << STR("Try to backward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sz"));
    writer << STR("Try to backward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    start = end = 0;
    source = CString(STR("adszdsa"));
    pattern = CString(STR("sZ"));
    writer << STR("Try to backward find \"") << pattern << STR("\" in \"") << source << STR('"');
    result = NAlgorithms::NString::stringSearchPrev(start, end, source, pattern, a_StringSearchAlgorithm);
    writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;

    // Perform search one of...
    searchOneOf(writer, a_StringSearchAlgorithm, a_crAlgorithmName);
  }

  // Perform string searching with the given one of algorithm.
  template <typename T_StringSearchAlgorithm>
  static void searchOneOf(IWriter& writer, T_StringSearchAlgorithm a_StringSearchAlgorithm, const CString& a_crAlgorithmName)
  { CALL
    IGNORE_UNUSED(a_StringSearchAlgorithm);

    writer << STR("One Of Search with ") << a_crAlgorithmName << STR("...") << ln;

    NAlgorithms::NString::NSearch::CStringSearchOneOf<CString, CString, T_StringSearchAlgorithm> algorithm;

    algorithm.getPatterns().insertLast(STR("abc"));
    algorithm.getPatterns().insertLast(STR("ab"));
    algorithm.getPatterns().insertLast(STR("a"));

    Tbool result;
    Tuint start, end;
    CString source, pattern;

    source = STR("_abcxyzaxyzabxyz_abc_xyzabxyzaxyzabc_");
    pattern = STR("_");

    writer << STR("Try to forward find patterns (\"abc\", \"ab\", \"a\", \"_\") in \"") << source << STR('"') << ln;
    start = end = 0;
    while (end + 1 < source.getSize())
    {
      result = NAlgorithms::NString::stringSearchNext(start, end, source, end, source.getSize() - end, pattern, 0, pattern.getSize(), algorithm);
      writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;
      ++start;
      ++end;
    }

    writer << STR("Try to backward find patterns (\"abc\", \"ab\", \"a\", \"_\") in \"") << source << STR('"') << ln;
    start = end = source.getSize();
    while (end > 0)
    {
      --start;
      --end;
      result = NAlgorithms::NString::stringSearchPrev(start, end, source, end, end + 1, pattern, 0, pattern.getSize(), algorithm);
      writer << STR(" ===> ") << (result ? STR("Success") : STR("Failed")) << STR(" - ") << start << STR(", ") << end << ln;
    }
  }
} the_Application;
/*==========================================================================*/
