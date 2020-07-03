#include <iostream>
#include "fmt/format.h"
#include "basics/base-class.h"
#include "basics/derived-class.h"

int main() {
  BaseClass base_class;
  DerivedClass derived_class;

  std::cout << "~~~ inheritance ~~~\n\n";

  std::cout <<
      "multiple inheritance is possible in C++, but it's usually not a good idea.\n"
      "single inheritance can already be confusing at times, it's better to use a\n"
      "controller or something similar than to create a wobbly inheritance graph.\n\n";

  std::cout <<
      "in this example, DerivedClass inherits from BaseClass using the 'public'\n"
      "keyword. this means all of BaseClass' protected & public fields keep their\n"
      "original access.\n\n";

  base_class.setPublicNumber(420);
  derived_class.setPublicNumber(420);
  base_class.setSomeNumber(42);
  derived_class.setSomeNumber(42);

  std::cout <<
      "\"setSomeNumber(42)\" has now been called on both classes, in addition to \n"
      "\"setPublicNumber(420)\". let's see what the state of things is:\n\n";


  std::cout << "base_class.\n" <<
      fmt::format("\tgetPublicNumber() = {}\n", base_class.getPublicNumber()) <<
      fmt::format("\tgetProtectedNumber() = {}\n", base_class.getProtectedNumber()) <<
      fmt::format("\tgetPrivateNumber() = {}\n", base_class.getPrivateNumber()) <<
      "\t(can't call getFourProtected()... it's protected)\n\n";

  std::cout << "derived_class.\n" <<
      fmt::format("\tgetPublicNumber() = {}\n", derived_class.getPublicNumber()) <<
      fmt::format("\tgetProtectedNumber() = {}\n", derived_class.getProtectedNumber()) <<
      fmt::format("\tgetPrivateNumber() = {}\n", derived_class.getPrivateNumber()) <<
      fmt::format("\tgetFourPublic() = {}\n", derived_class.getFourPublic()) <<
      "\t(can't call getFourProtected()... it's protected)\n\n";

  return 0;
}
