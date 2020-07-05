#include <iostream>
#include "fmt/format.h"

class Integer {
  public:
  int number;
  Integer(int number) {
    this->number = number;
  }
};

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
      "static casts are checked at compile-time only, meaning you can shoot yourself in the foot\n"
      "with them when downcasting from base to derived classes.\n"
      "syntax:\n\n"
      "\tstatic_cast<TypeToCastTo>(object_to_cast)\n\n";

  std::cout << "calling \"hello()\" on an Human casted to an Animal and then back to a Human:\n\t";
  Animal* human_animal = static_cast<Animal*>(&jon);
  static_cast<Human*>(human_animal)->hello();

  // This does not compile:
  // static_cast<Cat*>(&jon);

  // This compiles! Be careful when downcasting:
  std::cout <<
      "calling \"pet()\" on a human casted to a pet through a void pointer\n"
      "(a dangerous downcast!):\n\t";
  void* void_jon = static_cast<void*>(&jon);
  static_cast<Cat*>(void_jon)->pet();

  // Now setNumberOfSegments is doing the static cast. No issues in this example.
  std::cout <<
      "calling \"getNumberOfLegs()\" on a Centipede casted to an Animal and then back to a\n"
      "centipede:\n\t";
  Animal* centipede_animal = static_cast<Animal*>(&freddy);
  setNumberOfSegments(centipede_animal, 50);
  std::cout << fmt::format("freddy has {} legs.\n\n", freddy.getNumberOfLegs());

  // This compiles! Be careful when downcasting:
  setNumberOfSegments(human_animal, 50);

  std::cout <<
      "static casts can call conversion functions and constructors.\n\n";

  // These result in identical numbers.
  Integer ten_casted = static_cast<Integer>(10);
  Integer ten_created(10);
  if (ten_casted.number != ten_created.number) {
    return 1;
  }


  std::cout << "~~~ Dynamic casts ~~~\n\n";

  std::cout <<
      "dynamic casts are checked at run-time in addition to at compile time, so it's a safer way\n"
      "to downcast than static casts.\n"
      "syntax:\n\n"
      "\tdynamic_cast<TypeToCastTo>(object_to_cast)\n\n";

  std::cout <<
      "dynamic casts handle polymorphism better - if you dynamic cast a Human* stored in an\n"
      "Animal* to a Cat*, it'll output nullptr.\n\n";
  if (dynamic_cast<Cat*>(human_animal) != nullptr) {
    return 1;
  }

  std::cout <<
      "if you dynamic cast a Human* stored in an Animal* down to a Human*, it will of course\n"
      "work:\n\t";
  Human* human = dynamic_cast<Human*>(human_animal);
  if (human) {
    human->hello();
  }

  std::cout <<
      "you can also dynamic cast references. Because there is no 'nullreference', it just throws\n"
      "std::bad_cast when it fails:\n";
  Animal& human_animal_ref = jon;
  try {
    Cat& cat = dynamic_cast<Cat&>(human_animal_ref);
    cat.pet();
  } catch (std::bad_cast &e) {
    std::cout << "\tstd::bad_cast caught!\n\n";
  }

  std::cout <<
      "dynamic casts require RTTI (run-time type information) to be enabled for the build.\n"
      "this is usually not a problem for computer-targeted apps, but you'll have to do extra\n"
      "work to get RTTI enabled for e.g. Arduino builds.\n\n";


  std::cout << "~~~ Const casts ~~~\n\n";

  std::cout <<
      "const casts can add and remove the 'const' and 'volatile' keywords from variables. if you\n"
      "end up using it to remove 'const', please rethink your design choices.\n"
      "syntax:\n\n"
      "\tconst_cast<TypeToCastTo>(object_to_cast)\n\n";

  const Centipede* freddy_const = const_cast<const Centipede*>(&freddy);
  // Neither of these will compile because freddy_const points to a constant Centipede:
  // freddy_const->setNumberOfSegments(2);
  // freddy_const->getNumberOfLegs();


  std::cout << "~~~ Reinterpret casts ~~~\n\n";

  std::cout <<
      "reinterpret casts are brute-force \"make the computer do what I want\" casts. these casts\n"
      "are not checked at run-time or compile-time, and are the least-safe option. they can be\n"
      "useful for converting to/from uintptr_t in embedded systems, or for printing out pointers\n"       "for debugging purposes.\n"
      "syntax:\n\n"
      "\treinterpret_cast<TypeToCastTo>(object_to_cast)\n\n";


  std::cout << "when printing out pointers, reinterpret_cast to void*:\n\n";

  std::cout <<
      fmt::format("\taddress of 'jon': {}\n", reinterpret_cast<void*>(&jon)) <<
      fmt::format("\taddress of 'junebug': {}\n", reinterpret_cast<void*>(&junebug)) <<
      fmt::format("\taddress of 'freddy': {}\n\n", reinterpret_cast<void*>(&freddy));


  std::cout << "~~~ C-style casts ~~~\n\n";

  std::cout <<
      "C-style casts are present in C++ for backwards compatibility, they can't do anything new\n"
      "that other casts can't already do. avoid them.\n"
      "syntax:\n\n"
      "\t(TypeToCastTo) object_to_cast\n\n";

  std::cout <<
      "C-style casts try these operations in order:\n\n"
      " 1. const_cast\n"
      " 2. static_cast\n"
      " 3. static_cast then const_cast\n"
      " 4. reinterpret_cast\n"
      " 5. reinterpret_cast then const_cast\n\n";

  // Don't copy this example! Use reinterpret_cast instead.
  std::cout <<
      fmt::format("\taddress of 'jon': {}\n\n", (void*)&jon);



  std::cout << "~~~ TL;DR ~~~\n\n";

  std::cout <<
      "  - up-casting is implicit and safe - e.g. \"Base* base = new Derived();\".\n"
      "  - if you have to cast, prefer static_cast.\n"
      "  - use dynamic_cast when downcasting - but think about whether you really *need*\n"
      "    the derived type.\n"
      "  - use reinterpret_cast if you have to do something hacky.\n"
      "  - use const_cast if you have to add/remove const/volatile keywords - but try hard to\n"
      "    avoid needing this functionality.\n"
      "  - don't use C-style casts.\n\n";

  return 0;
}
