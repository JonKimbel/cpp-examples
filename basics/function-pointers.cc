#include <iostream>
#include "fmt/format.h"

int random_number() {
  return 4;
}

std::string stringify(int (*number_supplier)()) {
  return fmt::format("{}", number_supplier());
}

int main() {
  std::cout << "~~~ function pointers ~~~\n\n";

  std::cout <<
      "if you leave off the parentheses, a method's name is just a pointer to where the function\n"
      "resides in memory. e.g.\n" <<
      fmt::format("\trandom_number = {}\n", reinterpret_cast<void*>(random_number)) <<
      fmt::format("\t&&random_number = {}\n\n", reinterpret_cast<void*>(&random_number));

  std::cout <<
      "you can capture these pointers in function pointer types. function pointers look like\n"
      "\"<return type> (*<name>)(<arg types>)\". there are a variety of ways to set function\n"
      "pointers, e.g.:\n"
      "\tint (*func)() = &random_number;\n"
      "\tint (*func)() = random_number;\n"
      "\tint (*func)() { &random_number };\n"
      "\tint (*func)() { random_number };\n\n";

  int (*func)() = &random_number;

  std::cout <<
      "then you can execute the functions referenced by the pointers, e.g.\n" <<
      fmt::format("func() = {}\n\n", func());

  std::cout << "~~~ example function pointer declarations ~~~\n\n";

  std::cout <<
      "\tint (*const func)(); \/\/ constant pointer to a function that returns an int.\n"
      "\tconst int (*func)(); \/\/ pointer to a function that returns an constant int.\n"
      "\tvoid (*func)(int, int); \/\/ pointer to a function that takes two ints.\n\n";

  int (*const const_func)() = &random_number;

  std::cout <<
      "function pointers can be used like any pointer - you can use them as arguments for\n"
      "functions, and can set default values. for example:\n"
      "\tvoid no_op(bool success) {}\n"
      "\tvoid func(void (*finished_callback)(bool) = no_op);\n\n";

  stringify(const_func);

  std::cout << "~~~ typedef & aliasing function pointer types ~~~\n\n";

  std::cout <<
      "you can make function pointer types easier to read using typedef or C++11 aliases:\n"
      "\ttypedef int (*numberGenerator)(); \/\/ numberGenerator is now a type referring to\n"
      "\t                                  \/\/ zero-arg function pointers that return ints.\n"
      "\tusing numberGenerator = int(*)(); \/\/ same as above, just easier to read.\n\n";

  typedef int (*numberSupplierTypedef)();
  numberSupplierTypedef ns_1 = &random_number;
  ns_1();

  using numberSupplierAlias = int(*)();
  numberSupplierAlias ns_2 = &random_number;
  ns_2();

  std::cout <<
      "C++11 also brings std::function, which keeps the types obvious without the potentially\n"
      "confusing function pointer syntax:\n"
      "\t#include <functional>\n"
      "\tstd::function<int()> numberGenerator; \/\/ same as above, just easier to read.\n\n";

  std::function<int()> ns_3 = &random_number;
  ns_3();

  return 0;
}
