#ifndef BASICS_CHILD_CLASS_H
#define BASICS_CHILD_CLASS_H

#include "basics/parent-class.h"

// This access specifier here means that all of ParentClass's public methods will stay
// public in ChildClass.
//
// If this was "protected," all of ParentClass's public methods would become protected
// in ChildClass.
//
// If it was "private," all of ParentClass's public & protected methods would become
// private in ChildClass.
//                V
class ChildClass: public ParentClass {
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

#endif // BASICS_CHILD_CLASS_H
