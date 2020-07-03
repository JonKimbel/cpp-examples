#include <chrono>
#include <iostream>
#include "fmt/format.h"

int sum(int x, int y) {
  return x + y;
}

inline int sum_inline(int x, int y) {
  return x + y;
}

long benchmark(int (*method)(int, int)) {
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 10000; i++) {
    method(i, i);
  }

  auto stop = std::chrono::high_resolution_clock::now();
  return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
}

int main() {
  std::cout <<
      "inlined functions behave just like normal functions, but the code of the inlined function\n"
      "is substituted for each and every time it's called before the code is compiled.\n";

  std::cout << std::endl <<
      "benefits:\n"
      "\tskips the jmp, ret instructions that normal functions require.\n"
      "\tskips the stack overhead that calling a function normally entails.\n"
      "\tcompiler can perform optimization between callsite and method body.\n";

  std::cout << std::endl <<
      "drawbacks:\n"
      "\tlarger binary due to duplicated code.\n"
      "\tpotentially worse performance due to larger binary.\n"
      "\tlonger compile times when the contents of a well-used inline function are changed.\n";

  std::cout << std::endl;

  std::cout << fmt::format("\tresult of sum(3,2): {}\n", sum(3,2));
  std::cout << fmt::format("\tresult of sum_inline(3,2): {}\n", sum_inline(3,2));

  long sum_nanos = benchmark(&sum);
  long sum_inline_nanos = benchmark(&sum_inline);
  sum_inline_nanos += benchmark(&sum_inline);
  sum_nanos += benchmark(&sum);
  sum_nanos += benchmark(&sum);
  sum_inline_nanos += benchmark(&sum_inline);
  sum_inline_nanos += benchmark(&sum_inline);
  sum_nanos += benchmark(&sum);
  sum_nanos += benchmark(&sum);
  sum_inline_nanos += benchmark(&sum_inline);

  std::cout << fmt::format("\tit takes {}ns to execute sum() 50k times\n", sum_nanos);
  std::cout
      << fmt::format("\tit takes {}ns to execute sum_inline() 50k times\n", sum_inline_nanos);

  std::cout << std::endl <<
      "there's no guarantee the compiler actually *will* inline a method marked 'inline'.\n";

  std::cout << std::endl <<
      "all functions defined inside a class definition are implicitly inline (but member \n"
      "functions defined outside of the class definition aren't).\n";

  std::cout << std::endl <<
      "in general, it's only worth inlining tiny methods.\n";


  return 0;
}
