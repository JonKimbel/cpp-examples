#ifndef BASICS_DERIVED_CLASS_H
#define BASICS_DERIVED_CLASS_H

#include "basics/base-class.h"

// This access specifier here means that all of BaseClass's public methods will stay
// public in DerivedClass.
//
// If this was "protected," all of BaseClass's public methods would become protected
// in DerivedClass.
//
// If it was "private," all of BaseClass's public & protected methods would become
// private in DerivedClass.
//                   V
class DerivedClass: public BaseClass {
public:
  // Note that the default constructor will implicitly call the default BaseClass constructor.
  // If we had defined a constructor, even that would implicitly call the default BaseClass
  // constructor.

  void setSomeNumber(int number) {
    this->public_number = number;
  }

  int getFourPublic() {
    return this->getFourProtected();
  }
};

#endif // BASICS_DERIVED_CLASS_H
