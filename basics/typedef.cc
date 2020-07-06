#include <iostream>
#include "fmt/format.h"

// Template metaprogramming.

template<typename T>
struct strip_pointer_from;

template<typename T>
struct strip_pointer_from<T*> {
  typedef T type;
};

int main() {
  std::cout <<
      "typedef lets you create named aliases for types.\n"
      "\n"
      "\ttypedef unsigned long ulong;\n"
      "\n"
      "you can define an alias for an object and for a pointer to an object on the same line.\n"
      "in the following example, \"pS\" is the same type as \"S*\".\n"
      "\n"
      "\ttypedef struct {int a; int b;} S, *pS;\n"
      "\n"
      "when it comes to keyword ordering, it's outback steakhouse - no rules just right\n"
      "(but if you order things like this you're a monster).\n"
      "\n"
      "\tlong unsigned typedef int long ullong;\n"
      "\n"
      "its most common use in this way is for providing handy aliases for function pointers,\n"
      "although \"using\" (C++11) is more readable:\n"
      "\n"
      "\ttypedef boolean (*predicate)(int);\n"
      "\tusing predicate = boolean (*)(int);\n"
      "\n"
      "typedef can also be used for template metaprogramming, i.e. for a metafunction that\n"
      "strips pointers off of types:\n"
      "\n";

  strip_pointer_from<char*>::type letter = 'a';

  std::cout << fmt::format("strip_pointer_from<char*>::type = char (e.g. '{}')\n\n", letter);

  return 0;
}
