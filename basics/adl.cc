#include <iostream>
#include "fmt/format.h"

namespace A {
  class B {};
  void c(B b) {
    std::cout << "Called A::c even though the call was in a different namespace and looked like\n"
                 "\"c(b);\"\n\n";
  }
}

int main() {
  std::cout <<
      "ADL (Argument-Dependent name Lookup) allows you to call functions in different namespaces\n"
      "without qualifying those namespaces.\n"
      "\n"
      "when you make an unqualified function call, it is looked for:\n"
      "\n"
      "\twithin the current namespace\n"
      "\twithin the namespaces associated with the *types* of the function arguments\n"
      "\n";

  A::B b;
  c(b);

  std::operator<<(std::cout,
      "without ADL you'd have to do things like \"std::operator<<(std::cout, \"blah\");\"\n\n");

  std::cout <<
      "ADL can let you shoot yourself in the foot - if you do the following:\n"
      "\n"
      "\tusing std::swap;\n"
      "\tswap(a, b);\n"
      "\n"
      "your \"swap\" call might actually call a method outside of std (namely, wherever a & b's\n"
      "classes are defined). even though there's a \"using std::swap;\" statement, the call to\n"
      "swap(a, b) is unqualified.\n\n";

  std::cout <<
      "functions that can be found with ADL should be considered to be part of the related\n"
      "class's interface.\n\n";

  return 0;
}
