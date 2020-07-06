#include <iostream>
#include "fmt/format.h"

void exampleMethod(bool throw_int) throw (const int, const char*) {
  if (throw_int) {
    throw 4;
  } else {
    throw "a";
  }
}

int main() {
  std::cout <<
      "exception handling in C++ looks a lot like exception handling in Java or C#:\n"
      "\n"
      "\ttry {\n"
      "\t  throw new SomeExceptionType();\n"
      "\t} catch (SomeExceptionType& e) {\n"
      "\t  ...\n"
      "\t}\n"
      "\n"
      "if you want to catch all exceptions, use:\n"
      "\n"
      "\tcatch (...)\n"
      "\n"
      "if you want to re-throw an exception, just do \"throw;\".\n"
      "\n";

  try {
    exampleMethod(/* throw_int = */ true);
  } catch (int e) {
    std::cout << fmt::format("caught int ({})!\n\n", e);
  } catch (const char* e) {
    std::cout << fmt::format("caught char* ({})!\n\n", e);
  }

  std::cout <<
      "you *should* declare the exceptions your method throws, but you don't have to. the syntax\n"
      "is:\n"
      "\n"
      "\tvoid myMethod() throw (SomeExceptionType, SomeOtherExceptionType, Etc) { ...\n"
      "\n";

  std::cout <<
      "the pro-exceptions argument is fairly weak, not offering much that can't be done with\n"
      "return codes. I would argue that one supposed benefit (separating error handling) is\n"
      "actually a downside if a code block mixes exceptions you want to handle with others\n"
      "you don't want to handle.\n"
      "\n"
      "and then when you're refactoring you might forget to update all the places that catch\n"
      "your exceptions and then-" << std::endl;

  throw "RIP";
}
