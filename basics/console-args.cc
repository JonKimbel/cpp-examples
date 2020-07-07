#include <iostream>
#include "fmt/format.h"

int main(int arg_count, char *args[]) {
  if (arg_count <= 1) {
    std::cout <<
        "to pass in arguments when running via bazel, do \"-- your args\" after specifying the\n"
        "target name.\n\n";
  } else {
    std::cout <<
        "args:\n\n";
    for (int i = 1; i < arg_count; i++) {
      std::cout <<
        fmt::format("\t{}\n", args[i]);
    }
    std::cout << "\n";
  }

  std::cout <<
      "the first arg passed in is always the full path of the binary, e.g.\n\n" <<
      fmt::format("\t{}\n\n", args[0]);

  std::cout <<
      "the syntax for accepting command line args is:\n\n"
      "\tint main(int arg_count, char *args[]) { ...\n\n";

  std::cout <<
      "note that the asterisk goes on \"args\" because *declaration mimics use* in C++ -\n"
      "when you dereference a pointer you do it with \"*args\", so when you declare it you\n"
      "should do it with \"*args\" as well.\n\n";

  return 0;
}
