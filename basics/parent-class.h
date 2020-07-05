#ifndef BASICS_PARENT_CLASS_H
#define BASICS_PARENT_CLASS_H

#include "basics/base-class.h"

class ParentClass : public BaseClass {
private:
  int private_number;

protected:
  int protected_number;

  int getFourProtected() {
    return 4;
  }

public:
  ParentClass() {
    private_number = 0;
    protected_number = 0;
    public_number = 0;
  }

  int public_number;

  void setPublicNumber(int number) {
    public_number = number;
  }

  virtual void setSomeNumber(int number) {
    protected_number = number;
  }

  int getPublicNumber() {
    return public_number;
  }

  int getProtectedNumber() {
    return protected_number;
  }

  int getPrivateNumber() {
    return private_number;
  }
};

#endif // BASICS_PARENT_CLASS_H
