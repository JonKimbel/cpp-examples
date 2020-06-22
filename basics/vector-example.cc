#include <iostream>
#include <vector>
#include "fmt/format.h"

void print_numbers(const std::vector<int>& numbers);

int main() {
  std::vector<int> numbers;
  numbers.push_back(4);
  numbers.push_back(2);

  print_numbers(numbers);

  std::vector<int>::iterator it = numbers.begin();
  std::cout << fmt::format("Number at index 0: {}", *it) << std::endl;
  it++;
  std::cout << fmt::format("Number at index 1: {}", *it) << std::endl;

  numbers.insert(it, 0);

  print_numbers(numbers);
}

void print_numbers(const std::vector<int>& numbers) {
  std::cout << "Numbers: ";
  for (unsigned int i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i];
    if (i + 1 < numbers.size()) {
      std::cout << ", ";
    }
  }
  std::cout << std::endl;
}
