#include <iostream>

class Cat {
  private:
  int excitement_level = 0;
  int hunger_level = 0;

  public:
  int getExcitementLevel() {
    hunger_level++;
    return excitement_level;
  }
  friend void setExcitementLevel(Cat& cat, int new_level);
  friend class CatUtil;
};

class CatUtil {
  public:
  int getHungerLevel(const Cat& cat) {
    // Accessing private field of 'Cat'.
    return cat.hunger_level;
  }
};

void setExcitementLevel(Cat& cat, int new_level) {
  // Accessing private field of 'Cat'.
  cat.excitement_level = new_level;
}

int main() {
  Cat cat;
  CatUtil cat_util;

  std::cout <<
      "friend functions allow for functions defined outside a class to access protected or\n"
      "private class members. you can declare a friend function prototype like so:\n"
      "\tclass Cat {\n"
      "\t  ...\n"
      "\t  friend void setSomeVariable(const Cat& cat, int new_value);\n"
      "\t}\n\n"
      "then you can define a function that matches that prototype and call it.\n\n";

  setExcitementLevel(cat, 5);

  std::cout <<
      "friend classes let *all methods* in another class access protected or private class\n"
      "members. here's an example:\n"
      "\tclass Cat {\n"
      "\t  ...\n"
      "\t  friend class CatUtil;\n"
      "\t}\n\n"
      "now any class you create named CatUtil will be able to access private and protected\n"
      "members of any Cat objects that it is given access to.\n\n";

  cat_util.getHungerLevel(cat);

  return 0;
}
