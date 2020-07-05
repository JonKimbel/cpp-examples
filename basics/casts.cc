#include <iostream>
#include "fmt/format.h"

class Animal {
  public:
  virtual int getNumberOfLegs() = 0;
};

class Human : public Animal {
  public:
  void hello() {
    std::cout << "hello to you too.\n\n";
  }
  int getNumberOfLegs() { // Overrides Animal.
    return 2;
  }
};

class Cat : public Animal {
  public:
  void pet() {
    std::cout << "prrr\n\n";
  }
  int getNumberOfLegs() { // Overrides Animal.
    return 4;
  }
};

class Centipede : public Animal {
  private:
  int num_segments = 10;

  public:
  void setNumberOfSegments(int num_segments) {
    this->num_segments = num_segments;
  }
  int getNumberOfLegs() { // Overrides Animal.
    return num_segments * 2;
  }
};

void setNumberOfSegments(Animal* suspected_centipede, int num) {
  static_cast<Centipede*>(suspected_centipede)->setNumberOfSegments(num);
}

int main() {
  Human jon;
  Cat junebug;
  Centipede freddy;

  std::cout <<
    "there are four types of casts in C++:\n\n"
    "\tStatic cast\n"
    "\tDynamic cast\n"
    "\tConst cast\n"
    "\tReinterpret cast\n"
    "\tC-style casts\n\n";


  std::cout << "~~~ Static casts ~~~\n\n";

  std::cout <<
      "static casts are compile-time, meaning you can't shoot yourself in the foot with them...\n"
      "except when downcasting from base to derived classes. there aren't compile-time checks\n"
      "for that.\n"
      "syntax:\n\n"
      "\tstatic_cast<TypeToCastTo>(object_to_cast)\n\n";

  Animal* human_animal = static_cast<Animal*>(&jon);
  static_cast<Human*>(human_animal)->hello();

  // This does not compile:
  // static_cast<Cat*>(&jon);

  // This compiles! Be careful when downcasting:
  void* void_jon = static_cast<void*>(&jon);
  static_cast<Cat*>(void_jon)->pet();

  // Now setNumberOfSegments is doing the static cast. No issues in this example.
  Animal* centipede_animal = static_cast<Animal*>(&freddy);
  setNumberOfSegments(centipede_animal, 50);
  std::cout << fmt::format("freddy has {} legs.\n\n", freddy.getNumberOfLegs());

  // This compiles! Be careful when downcasting:
  setNumberOfSegments(human_animal, 50);

  std::cout << "~~~ Dynamic casts ~~~\n\n";

  std::cout <<
      "dynamic casts are run-time.\n"
      "syntax:\n\n"
      "\tdynamic_cast<TypeToCastTo>(object_to_cast)\n\n";


  std::cout << "~~~ Const casts ~~~\n\n";




  std::cout << "~~~ Reinterpret casts ~~~\n\n";



  std::cout << "~~~ C-style casts ~~~\n\n";



  return 0;
}
