#include <iostream>
#include "fmt/format.h"

template <typename T>
T maxFunction(T x, T y)
{
  return (x > y) ? x : y;
}

template <typename T>
class MaxClass {
  private:
    T x;
    T y;

  public:
    MaxClass(T x, T y);
    T max();
    int getFour();
};

template <typename T>
MaxClass<T>::MaxClass(T x, T y) {
  this->x = x;
  this->y = y;
}

template <typename T>
T MaxClass<T>::max() {
  return maxFunction(x, y);
}
template <typename T>
int MaxClass<T>::getFour() {
  return 4;
}


int main() {
  MaxClass<int> int_max(3, 2);
  MaxClass<const char*> c_string_max("b", "a");

  std::cout << fmt::format("maxFn<int>: {}\n", maxFunction(3, 2));
  std::cout << fmt::format("maxFn<char*>: {}\n", maxFunction("b", "a"));

  std::cout << std::endl;

  std::cout << fmt::format("MaxClass<int>::max(): {}\n", int_max.max());
  std::cout << fmt::format("MaxClass<int>::getFour(): {}\n", int_max.getFour());

  std::cout << std::endl;

  std::cout << fmt::format("MaxClass<const char*>::max(): {}\n", c_string_max.max());
  std::cout << fmt::format("MaxClass<const char*>::getFour(): {}\n", c_string_max.getFour());

  return 0;
}
