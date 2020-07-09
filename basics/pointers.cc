#include <iostream>
#include "fmt/format.h"

int** make_matrix_with_pointers();
void print_matrix_with_pointers(int** matrix);
void unmake_matrix(int** matrix);
void pass_by_reference(int& number);
void pass_by_value(int number);
void pass_by_pointer(int* number);

int main() {
  int** matrix = make_matrix_with_pointers();
  print_matrix_with_pointers(matrix);
  unmake_matrix(matrix);

  int number = 0;
  pass_by_value(number);
  std::cout << fmt::format("Passed by value: {}\n", number);

  pass_by_reference(number);
  std::cout << fmt::format("Passed by reference: {}\n", number);

  pass_by_pointer(&number);
  std::cout << fmt::format("Passed by pointer: {}\n\n", number);

  std::cout <<
      "void pointers (void*) are just raw pointers with no associated type. you can cast it\n"
      "to other types, although it's risky. if you see a function declaration like this, it\n"
      "*returns* a void pointer:\n"
      "\n"
      "\tvoid *func(int whatever);\n";

  return 0;
}

int** make_matrix_with_pointers() {
  int** matrix;

  matrix = new int*[10];

  for (int x = 0; x < 10; x++) {
    matrix[x] = new int[10];
    for (int y = 0; y < 10; y++) {
      matrix[x][y] = x*10+y;
    }
  }

  return matrix;
}

void print_matrix_with_pointers(int** matrix) {
  for (int x = 0; x < 10; x++) {
    for (int y = 0; y < 10; y++) {
      std::cout << matrix[x][y] << "\t";
    }
    std::cout << std::endl;
  }
}

void unmake_matrix(int** matrix) {
  // Need to use 'delete[]' instead of 'delete' when de-allocating arrays.
  for (int x = 0; x < 10; x++) {
    delete[] matrix[x];
  }
  delete[] matrix;
}


void  pass_by_value(int number) {
  number = 42;
}

void pass_by_reference(int& number) {
  number = 42;
}

void pass_by_pointer(int* number) {
  *number = 24;
}
