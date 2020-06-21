#include <iostream>
#include "fmt/format.h"

int main() {
  bool boolean = true;  // 1 byte (only one bit is usable).

  char character = 127;  // 1 byte.

  short int short_integer = 32767;                        // 2 bytes.
  int integer = 2147483647;                               // 4 bytes (64 bit machines).
  long int long_integer = 2147483647;                     // 4 bytes.
  long long int long_long_integer = 9223372036854775807;  // 8 bytes.

  float floating_point =        // 4 bytes.
      3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058L;
  double double_precision =     // 8 bytes.
      3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058L;
  long double quad_precision =  // 16 bytes.
        3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058L;

  std::cout
      << fmt::format(
          "boolean: {}\n"
          "character: {:d}\n"
          "short integer: {}\n"
          "integer: {}\n"
          "long integer: {}\n"
          "long long integer: {}\n"
          "floating point (accurate to 6 digits): {:.20f}\n"
          "double precision floating point (accurate to 15 digits): {:.20f}\n"
          "quadruple precision floating point (accurate to 18 digits): {:.20f}",
          boolean, character, short_integer, integer, long_integer, long_long_integer,
          floating_point, double_precision, quad_precision)
      << std::endl;

  return 0;
}
