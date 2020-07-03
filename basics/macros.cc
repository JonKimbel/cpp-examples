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

const char* example_command();

int main() {
  std::cout << "~~ quick note ~~~" << std::endl;

  std::cout <<
      "this program is a stylistic mess, just check out the build warnings.\n"
      "it's for demonstration purposes only.\n";

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
  std::cout
      << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);
  #define MACROS_CAN_CALL_OTHER_MACROS_2 4
  std::cout
      << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);
  #define MACROS_CAN_CALL_OTHER_MACROS_1 5
  std::cout
      << fmt::format("macros can call other macros: {}\n", MACROS_CAN_CALL_OTHER_MACROS_1);

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

  std::cout << std::endl << "~~ args and other tokens can be concatenated using \"##\" ~~~"
      << std::endl;

  #define command(name) name ## _command()
  std::cout << fmt::format("output of command(example) - should call example_command(): {}\n",
      command(example));

  std::cout << std::endl
      << "~~ macros can have multiple arguments using ... and __VA_ARGS__ ~~~" << std::endl;

  #define pront(...) std::cout << fmt::format("{} {}{}{}\n", __VA_ARGS__)
  pront("\"...\" = varargs parameter symbol, ", "__VA_ARGS__ = default args name", "!", "!");

  #define pront2(fmt_args...) std::cout << fmt::format("{} {}{}{}\n", fmt_args)
  pront2("name args by putting the variable name ", "before the \"...\"", "!", "!");

  #define pront3(fmt_string, ...) std::cout << \
      fmt::format(fmt_string __VA_OPT__(,) __VA_ARGS__)
  pront3("you can mix required args with ");
  pront3("{}", "varargs, ");
  pront3("{} {} {} ", "as", "long", "as");
  pront3("you put the required args first!\n");
  pront3("use __VA_OPT__(whatever) to only expand \"whatever\" when varargs are supplied!\n");

  std::cout << std::endl << "~~ predefined macros ~~~" << std::endl;

  std::cout << "standard stuff:\n"
      << fmt::format("\t__FILE__: {}\n", __FILE__)
      << fmt::format("\t__LINE__: {}\n", __LINE__)
      << fmt::format("\t__LINE__: {}\n", __LINE__)
      << fmt::format("\t__LINE__: {}\n", __LINE__)
      << fmt::format("\t__DATE__: {}\n", __DATE__)
      << fmt::format("\t__TIME__: {}\n", __TIME__)
      << fmt::format("\t__STDC__: {}\n", __STDC__)
      << fmt::format("\t__STDC_HOSTED__: {}\n", __STDC_HOSTED__)
      << fmt::format("\t__cplusplus: {}\n", __cplusplus)
      << "__STDC_VERSION__, __OBJC__, and __ASSEMBLER__ should all be defined "
      << "when using those languages." << std::endl;

  std::cout << "there are a bunch of predefined macros which simply tell you about the "
            "compiler.\n";

  std::cout << "there are some \"named operators\" for boolean operations:\n"
      << fmt::format("\ttrue and false = {}\n", true and false)
      << fmt::format("\t1 bitand 3 = {}\n", 1 bitand 3)
      << fmt::format("\ttrue xor false = {}\n", true xor false);

  std::cout << std::endl << "~~ operator precedence pitfalls ~~~" << std::endl;

  std::cout << "it's best practice to wrap arg usage and the macro definition as a whole in ().\n";

  #define add(x,y) x + y
  #define add_wrapped(x,y) ((x) + (y))

  std::cout
      << fmt::format("\tresult of calling add(3,2): {}\n", add(3,2) * 2)
      << fmt::format("\tresult of calling add_wrapped(3,2): {}\n", add_wrapped(3,2) * 2);

  std::cout <<
      "if the macro is \"add(x, y) x + y\" and we use it as add(3, 2) * 2, it will expand to\n"
      "\"3 + 2 * 2\".\n";

  std::cout << std::endl << "~~ side-effect pitfalls ~~~" << std::endl;

  std::cout <<
      "if you \"pass\" the result of a method into a macro, the method call may be duplicated.\n"
      "for example, a macro defined like so:\n"
      "\t#define min(X,Y) X < Y ? X : Y\n"
      "would result in \"min(foo(), bar());\" expanding into \"foo() < bar() ? foo() : bar()\".\n"
      "either foo() or bar() is guaranteed to be called twice.\n"
      "this is problematic if foo() or bar() have a side-effect. be careful calling macros.\n";

  std::cout << std::endl << "~~ argument prescan pitfalls ~~~" << std::endl;

  std::cout <<
      "macro arguments are scanned *twice* to expand macro calls - once before substitution into\n"
      "the macro and once afterwards. this mostly causes things to \"just work\" as you'd\n"
      "expect. it's only disabled when the argument is stringized or concatenated, i.e.:\n";
  #define stringize(x) #x
  #define output(x) x
  #define fav_number 4
  std::cout
      << fmt::format("\t stringize(fav_number): {}\n", stringize(fav_number))
      << fmt::format("\t output(fav_number): {}\n", output(fav_number));
  std::cout <<
      "prescan can cause troubles if macros use \"unshielded\" commas\n"
      "(aka commas outside parens). I was unable to get the dangerous case documented in the gcc\n"
      "docs to actually compile, but if you shield your macros with () you can avoid this.\n";

  return 0;
}

const char* example_command() {
  return "hello";
}
