// #include is technically a macro.
#include <iostream>
#include "fmt/format.h"

#define SIMPLE_MACRO 4
#define SIMPLE_MULTILINE_MACRO 1, \
                               2, \
                               3

#define function_like_macro() std::cout << "function-like macro\n";
#define function_like_macro_args(x,y) \
    std::cout << fmt::format("function-like macro with args: {} {}\n", x, y);
#define function_like_macro_args_quotes(x) \
    std::cout << fmt::format("the arg isn't replaced when it's in quotes: x (vs {})\n", x);
#define function_like_macro_stringizing(x) \
    std::cout << fmt::format("macros aren't expanded when stringized: " #x " (vs {})\n", x);

int main() {
  std::cout << std::endl << "~~~ macros replace their names with their contents ~~~" << std::endl;


  std::cout << SIMPLE_MACRO << std::endl;
  std::cout << fmt::format("macro number: {}\n", SIMPLE_MACRO);
  std::cout << fmt::format("macro multiline: {} {} {}\n", SIMPLE_MULTILINE_MACRO);

  std::cout << std::endl << "~~~ macros take effect when defined ~~~" << std::endl;

  #define MACROS_TAKE_EFFECT_WHEN_DEFINED 1
  std::cout << fmt::format("macro def 1: {}\n", MACROS_TAKE_EFFECT_WHEN_DEFINED);
  #define MACROS_TAKE_EFFECT_WHEN_DEFINED 2
  std::cout << fmt::format("macro def 1: {}\n", MACROS_TAKE_EFFECT_WHEN_DEFINED);

  std::cout << std::endl << "~~~ macros can reference other other macros ~~~" << std::endl;

  #define MACROS_CAN_CALL_OTHER_MACROS_1 MACROS_CAN_CALL_OTHER_MACROS_2
  #define MACROS_CAN_CALL_OTHER_MACROS_2 3
  std::cout << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);
  #define MACROS_CAN_CALL_OTHER_MACROS_2 4
  std::cout << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);
  #define MACROS_CAN_CALL_OTHER_MACROS_1 5
  std::cout << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);

  std::cout << std::endl << "~~ macros can be used like functions ~~~" << std::endl;

  function_like_macro();
  function_like_macro_args("hello", 42);
  function_like_macro_args_quotes("y");
  function_like_macro_stringizing(SIMPLE_MACRO);

  std::cout << std::endl << "~~ failing to \"swallow\" the semicolon can cause trouble ~~~"
      << std::endl;

  #define plus_five(x) x+5;
  #define plus_five_no_semi(x) x+5
  int with_semicolon = plus_five(10) + 2;
  std::cout << fmt::format("with trailing semicolon (\"+ 2\" is ignored): {}\n",
      with_semicolon);
  int without_semicolon = plus_five_no_semi(10) + 2;
  std::cout << fmt::format("without trailing semicolon (\"+ 2\" is respected): {}\n",
      without_semicolon);
  std::cout << "wrapping macro contents in \"do { ... } while(0)\" can sometimes help\n";

  // TODO: wrap up these topics:
  //   https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html#Concatenation
  //   https://gcc.gnu.org/onlinedocs/cpp/Variadic-Macros.html#Variadic-Macros
  //   https://gcc.gnu.org/onlinedocs/cpp/Predefined-Macros.html#Predefined-Macros
  //   https://gcc.gnu.org/onlinedocs/cpp/Operator-Precedence-Problems.html#Operator-Precedence-Problems
  //   https://gcc.gnu.org/onlinedocs/cpp/Duplication-of-Side-Effects.html#Duplication-of-Side-Effects
  //   https://gcc.gnu.org/onlinedocs/cpp/Argument-Prescan.html#Argument-Prescan
  //   https://gcc.gnu.org/onlinedocs/cpp/Newlines-in-Arguments.html#Newlines-in-Arguments


  return 0;
}
