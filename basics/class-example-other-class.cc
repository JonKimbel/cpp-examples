#include <iostream>
#include "class-example-other-class.h"

ClassExampleOtherClass::ClassExampleOtherClass(int times_to_loop) {
  _times_to_loop = times_to_loop;
}

void ClassExampleOtherClass::do_stuff() {
  for (int i = 0; i < _times_to_loop; i++) {
    std::cout << "loop";
  }
  std::cout << std::endl;
}
