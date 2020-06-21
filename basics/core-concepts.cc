#include <iostream>
#include "fmt/format.h"

int main() {
  int number = 1;
  std::cout << fmt::format("integer number: {}", number) << std::endl;
  return 0;
}
