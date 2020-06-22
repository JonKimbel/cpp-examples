#include <iostream>
#include <string>
#include "fmt/format.h"

struct Cat {
  std::string name;
  char hunger_level = 0;
  char excitement_level = 0;
  char sleepiness_level = 0;
};

enum Action {
  PLAY = 1,
  FEED = 2,
  AVOID = 3,
  STOP_PLAYING = 4,
};

void clamp10(char& number);

int main() {
  Cat cat;

  std::cout << "Enter name for cat: ";
  std::getline(std::cin, cat.name);
  std::cout << std::endl;

  bool simulation_running = true;

  while (simulation_running) {
    std::cout <<
        "What would you like to do?\n"
        "  1. Play with cat\n"
        "  2. Feed cat\n"
        "  3. Leave cat alone\n"
        "  4. Stop playing"
        << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == PLAY) {
      std::cout << fmt::format("You played with {}.", cat.name) << std::endl;
      cat.excitement_level -= 3;
    } else if (choice == FEED) {
      std::cout << fmt::format("You fed {}.", cat.name) << std::endl;
      cat.hunger_level -= 3;
    } else if (choice == AVOID) {
      std::cout << fmt::format("{} took a nap.", cat.name) << std::endl;
      cat.sleepiness_level -= 3;
    } else if (choice == STOP_PLAYING) {
      simulation_running = false;
    } else {
      std::cout << fmt::format("You confused {}!", cat.name) << std::endl;
      cat.excitement_level += 6;
    }

    cat.hunger_level++;
    cat.excitement_level++;
    cat.sleepiness_level++;

    clamp10(cat.hunger_level);
    clamp10(cat.excitement_level);
    clamp10(cat.sleepiness_level);

    if (cat.hunger_level > 5 || cat.excitement_level > 5 || cat.sleepiness_level > 5) {
      std::cout << fmt::format("{} bit you!", cat.name) << std::endl;
    }
  }

  return 0;
}

void clamp10(char& number) {
  if (number > 10) {
    number = 10;
  }
  if (number < 0) {
    number = 0;
  }
}
