# cpp-examples

Example C++ code for my reference.

## Setup

1.  Install bazel following [these docs](https://docs.bazel.build/versions/master/install-ubuntu.html).
2.  From this directory, run e.g. `bazel run //basics:basic-structure`

## TODO

*   Finish adding basic code examples to `//basics/`
    *   ADL (https://en.wikipedia.org/wiki/Argument-dependent_name_lookup)
    *   Multithreading (volatile)
    *   auto
    *   extern
    *   sizeof
    *   register
    *   union
    *   using
    *   operator (give examples for all possible operator overloads)
    *   explicit
    *   mutable
    *   typeid
    *   asm
    *   Signal handling
    *   Namespaces
    *   Common types
    *   Forward declares vs. includes
*   Look through [C++11](https://en.cppreference.com/w/cpp/11) and add example usage to `//cpp11/`.
*   Look through [C++14](https://en.cppreference.com/w/cpp/14) and add example usage to `//cpp14/`.
*   Look through [C++17](https://en.cppreference.com/w/cpp/17) and add example usage to `//cpp17/`.
*   Look through [C++20](https://en.cppreference.com/w/cpp/20) and add example usage to `//cpp20/`.
*   Look through `std` library and add example usage to `//std/`.
*   Look through `absl` library and add example usage to `//absl/`.
*   Check out the [Google style guide](https://google.github.io/styleguide/cppguide.html).
*   Look for the nastiest C++ hacks I can find, figure out how they work.
