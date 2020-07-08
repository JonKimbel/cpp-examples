#include <iostream>
#include "fmt/format.h"

int main() {
  std::cout <<
      "the standard preprocessing directives are:\n"
      "\n"
      "\t#define (something) - defines macros\n"
      "\t#undef (something) - un-defines macros\n"
      "\t#include \"\"/<> - includes a source file\n"
      "\t__has_include(\"\"/<>) - evaluates to 0 or 1 in conditional directives\n"
      "\n"
      "\t#if (something) - starts a conditional\n"
      "\t#ifdef (macro name) - starts a conditional based on a macro being defined\n"
      "\t#ifndef (macro name)\n"
      "\t#else\n"
      "\t#elif (something) - else if\n"
      "\t#endif - ends a conditional\n"
      "\n"
      "\t#line (some number) - sets the preproccessor line number, changing what __LINE__\n"
      "\t                      outputs (takes effect on the next line)\n"
      "\t#error (some message) - stops compilation and displays a message\n"
      "\tmodule, export, import - these help divide large amounts of code (C++20)\n"
      "\n"
      "\t#pragma (params) - controls implementation-specific (\"pragmatic\") compiler behavior,\n"
      "\t\t#pragma STDC FENV_ACCESS (ON/OFF) - informs the compiler that the program will\n"
      "\t\t                                    modify the floating-point environment\n"
      "\t\t                                    (default OFF)\n"
      "\t\t#pragma STDC FP_CONTRACT (ON/OFF) - allows combining floating point operations to\n"
      "\t\t                                    reduce error (default ON)\n"
      "\t\t#pragma STDC CX_LIMITED_RANGE (ON/OFF) - informs the compiler that complex number\n"
      "\t\t                                         math can use overflow-prone formulas\n"
      "\t\t                                         (default OFF)\n"
      "\t\t#pragma once - indicates that the header file should only be parsed once. can\n"
      "\t\t               replace include guards, but include guards are the standard so\n"
      "\t\t               use them\n"
      "\t\t#pragma pack - set of commands that instruct the compiler how to align variables in\n"
      "\t\t               memory, can incur a performance penalty or errors but might be useful\n"
      "\t\t               to save memory in embedded devices\n"
      "\n"
      "preprocessing directives won't work if they result from macro expansions.\n"
      "\n";

  std::cout << fmt::format("__LINE__ = {}, __FILE__ = {}\n", __LINE__, __FILE__);
  #line 42
  std::cout << fmt::format("__LINE__ a line after \"#line 42\" = {}\n", __LINE__);
  #line 42 "lol.cc"
  std::cout << fmt::format("__FILE__ after \"#line 42 \"lol.cc\"\"= {}\n\n", __FILE__);

  #define LMAO 525600

  #ifdef LOL
  #error "LOL is defined!"
  #elif LMAO > 3
  std::cout << fmt::format("LMAO is defined, and is {}\n\n", LMAO);
  #undef LMAO
  #endif

  return 0;
}
