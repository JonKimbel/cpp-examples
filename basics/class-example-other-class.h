#ifndef BASICS_CLASS_EXAMPLE_OTHER_CLASS
#define BASICS_CLASS_EXAMPLE_OTHER_CLASS

class ClassExampleOtherClass {

private:
  int _times_to_loop;

public:
  ClassExampleOtherClass() : ClassExampleOtherClass(420) {};
  ClassExampleOtherClass(int times_to_loop);

  void do_stuff();
};

#endif  // BASICS_CLASS_EXAMPLE_OTHER_CLASS
