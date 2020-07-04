#include <iostream>
#include "fmt/format.h"
#include "basics/parent-class.h"
#include "basics/child-class.h"

int main() {
  ParentClass parent_class;
  ChildClass child_class;

  std::cout << "~~~ inheritance ~~~\n\n";

  std::cout <<
      "multiple inheritance is possible in C++, but it's usually not a good idea.\n"
      "single inheritance can already be confusing at times, it's better to use a\n"
      "controller or something similar than to create a wobbly inheritance graph.\n\n";

  std::cout <<
      "in this example, ChildClass inherits from ParentClass using the 'public'\n"
      "keyword. this means all of ParentClass' protected & public fields keep their\n"
      "original access.\n\n";

  parent_class.setPublicNumber(420);
  child_class.setPublicNumber(420);
  parent_class.setSomeNumber(42);
  child_class.setSomeNumber(42);

  std::cout <<
      "\"setSomeNumber(42)\" has now been called on both classes, in addition to \n"
      "\"setPublicNumber(420)\". let's see what the state of things is:\n\n";


  std::cout << "parent_class.\n" <<
      fmt::format("\tgetPublicNumber() = {}\n", parent_class.getPublicNumber()) <<
      fmt::format("\tgetProtectedNumber() = {}\n", parent_class.getProtectedNumber()) <<
      fmt::format("\tgetPrivateNumber() = {}\n", parent_class.getPrivateNumber()) <<
      "\t(can't call getFourProtected()... it's protected)\n\n";

  std::cout << "child_class.\n" <<
      fmt::format("\tgetPublicNumber() = {}\n", child_class.getPublicNumber()) <<
      fmt::format("\tgetProtectedNumber() = {}\n", child_class.getProtectedNumber()) <<
      fmt::format("\tgetPrivateNumber() = {}\n", child_class.getPrivateNumber()) <<
      fmt::format("\tgetFourPublic() = {}\n", child_class.getFourPublic()) <<
      "\t(can't call getFourProtected()... it's protected)\n\n";

  std::cout <<
      "a couple things to know about C++ inheritance syntax:\n\n"
      "\t\"virtual\" means derived classes can override a method.\n"
      "\t\"virtual\" AND \" = 0;\" together mean the class is abstract.\n\n";

  return 0;
}
