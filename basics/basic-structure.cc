#include <iostream>

void function();

int main() {
  int n;
  std::cout << "Please enter a number of times to execute the loop: ";
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cout << "Loop executed." << std::endl;
  }

  if (n == 420) {
    std::cout <<
        "          W           \n"
        "         WWW          \n"
        "         WWW          \n"
        "        WWWWW         \n"
        "  W     WWWWW     W   \n"
        "  WWW   WWWWW   WWW   \n"
        "   WWW  WWWWW  WWW    \n"
        "    WWW  WWW  WWW     \n"
        "     WWW WWW WWW      \n"
        "       WWWWWWW        \n"
        "    WWWW  |  WWWW     \n"
        "          |           \n"
        "          |           \n";
  }

  function();

  return 0;
}

void function() {
  std::cout << "I'm a function." << std::endl;
}
