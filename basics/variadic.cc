#include <iostream>
#include <cstdarg>

// Templated recursive method (C++11).

template <typename T>
void print_recursive(T t) {
  std::cout << t << std::endl;
}

template <typename T, typename... Args>
void print_recursive(T t, Args... args) {
  std::cout << t << "\n";
  print_recursive(args...);
}

// Initializer list method (C++11).

void print_initializer_list(std::initializer_list<const char*> list) {
  for (const char* elem : list) {
    std::cout << elem << "\n";
  }
}

// C-style (type-unsafe! ugly! don't do this!).

void print_c_style(const char* first, ...) {
  va_list args;
  va_start(args, first);

  std::cout << first << "\n";

  while (const char* arg = va_arg(args, const char*)) {
    std::cout << arg << "\n";
  }

  va_end(args);
}

int main() {
  std::cout <<
      "variadic functions - functions with a variable number of arguments - are kind of a\n"
      "nightmare in C++. that's the entire reason that stream manipulation is done with the\n"
      "bitwise left shift operator. consider a different approach before committing to a\n"
      "variadic interface - C++ is not Java.\n\n";

  std::cout << "~~~ the templated recursive way (C++11) ~~~\n\n";

  print_recursive(
      "this C++11 approach uses templates and recursion in a tricky way to repeatedly \"peel\"",
      "off the first arg until none are left.",
      "",
      "create two templated functions, one that takes a \"T\" and one that takes a \"T\" and",
      "an \"Args...\". have the variadic function consume the \"T\" and call itself with the",
      "\"args...\".",
      "");

  std::cout << "~~~ the std::initializer_list way (C++11) ~~~\n\n";

  print_initializer_list({
      "this C++11 approach uses \"std::initializer_list\", which is a lightweight wrapper",
      "around arrays of constant objects. these wrappers are auto-constructed around:",
      "",
      "\tarray literals passed to constructors that take a std::initializer_list arg",
      "\tarray literals passed to methods that take a std::initializer_list arg",
      "\tarray literals assigned to \"auto\", including in a for (x : y) loop",
      ""});

  std::cout << "~~~ the C way (<cstdarg>) ~~~\n\n";

  print_c_style(
      "this way lies danger - the type un-safety and confusion offered by this setup is the",
      "reason why streams are done with bitwise shift operators in C++.",
      "",
      "the function declaration syntax is simple. Note that the following declares a single",
      "const char* arg (named fmt) followed by a multitude of untyped args:",
      "\tvoid simple_printf(const char* fmt...)",
      "",
      "the <cstdarg> library offers several functions for parsing the variadic args:",
      "",
      "\tva_list  - declare one of these, then pass it to the following methods",
      "\tva_start - pass this a va_list and the parameter *before* the variadic args to prepare",
      "\t           to parse variadic args",
      "\tva_arg   - pass this a va_list and an expected type to access the next variadic arg,",
      "\tva_end   - end traversal of variadic args",
      "",
      nullptr);

  return 0;
}
