#ifndef BASICS_BASE_CLASS_H
#define BASICS_BASE_CLASS_H

class BaseClass {
public:
  virtual int getPublicNumber() = 0;
  virtual int getProtectedNumber() = 0;
  virtual int getPrivateNumber() = 0;
};

#endif
