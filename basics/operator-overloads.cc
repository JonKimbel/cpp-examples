#include <iostream>

std::ostream& operator,(std::ostream& ostream, const char* rhs) {
  return ostream << rhs;
}

int main() {
  std::cout <<
      "C++ lets you override operators in your class definitions:\n"
      "\n"
      "Arithmetic:\n"
      "  - '+'   - addition\n"
      "  - '-'   - subtraction OR minus sign (can be overridden separately)\n"
      "  - '*'   - multiplication\n"
      "  - '/'   - division\n"
      "  - '%'   - modulus\n"
      "\n"
      "Bitwise arithmetic:\n"
      "  - '^'   - bitwise XOR\n"
      "  - '&'   - bitwise AND\n"
      "  - '|'   - bitwise OR\n"
      "  - '~'   - bitwise NOT\n"
      "  - '<<'  - bitwise left shift aka stream insertion\n"
      "            (it was used for IO because it looks like UNIX redirection)\n"
      "  - '>>'  - bitwise right shift aka stream extraction\n"
      "            (it was used for IO because it looks like UNIX redirection)\n"
      "\n"
      "Comparison:\n"
      "  - '<'   - less than\n"
      "  - '>'   - greater than\n"
      "  - '=='  - equals\n"
      "  - '!='  - not equals\n"
      "  - '<='  - less than or equals\n"
      "  - '>='  - greater than or equals\n"
      "  - '<=>' - three-way comparison (returns a negative number if less than,\n"
      "            0 if equal, a postive number if greater than)\n"
      "\n"
      "Logical:\n"
      "  - '!'   - logical NOT\n"
      "  - '&&'  - logical AND (note that overloads will lose their rigorous order-of-evaluation\n"
      "            before C++17 and short-circuit evaluation in all C++ versions)\n"
      "  - '||'  - logical OR (note that overloads will lose their rigorous order-of-evaluation\n"
      "            before C++17 and short-circuit evaluation in all C++ versions)\n"
      "\n"
      "Assignment:\n"
      "  - '='   - assigment\n"
      "  - '+='  - addition assignment\n"
      "  - '-='  - subtraction assignment\n"
      "  - '*='  - multiplication assignment\n"
      "  - '/='  - division assignment\n"
      "  - '%='  - modulus assignment\n"
      "  - '^='  - bitwise XOR assignment\n"
      "  - '&='  - bitwise AND assignment\n"
      "  - '|='  - bitwise OR assignment\n"
      "  - '<<=' - bitwise left shift assignment\n"
      "  - '>>=' - bitwise right shift assignment\n"
      "\n"
      "Increment/decrement:\n"
      "  - '++'  - increment (prefix and postfix version can be overloaded separately)\n"
      "  - '--'  - decrement (prefix and postfix version can be overloaded separately)\n"
      "\n"
      "Misc:\n"
      "  - ','   - evaluate left, then right, then return right\n"
      "    (overloads do not sequence the left operand before the right until C++17)\n"
      "  - '->*' - call right member_function_pointer on left class\n"
      "  - '->'  - call right function on left class\n"
      "    (note that overloads will lose their rigorous order-of-evaluation before C++17)\n"
      "  - '( )' - can be passed an arbitrary number of parameters.\n"
      "  - '[ ]' - access the contents of an array or list\n\n";

  std::cout <<
    "you can also overload operators outside class definitions (functions outside classes are\n"
    "called \"free functions\"). this doesn't work for every operator, but it works for a lot\n"
    "of them. this text was output using an overridden comma operator.\n\n";

  return 0;
}
