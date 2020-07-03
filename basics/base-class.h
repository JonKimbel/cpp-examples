#ifndef BASICS_BASE_CLASS_H
#define BASICS_BASE_CLASS_H

class BaseClass {
private:
  int private_number;

protected:
  int protected_number;

  int getFourProtected() {
    return 4;
  }

public:
  BaseClass() {
    private_number = 0;
    protected_number = 0;
    public_number = 0;
  }

  int public_number;

  void setPublicNumber(int number) {
    public_number = number;
  }

  void setSomeNumber(int number) {
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

#endif // BASICS_BASE_CLASS_H
