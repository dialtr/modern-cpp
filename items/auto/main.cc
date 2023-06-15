#include <iostream>
#include <vector>

using ::std::cout;
using ::std::endl;
using ::std::vector;

// A function that returns an integer type.
int returns_int() { return 1; }

struct Foo {};

// A function that returns a 'Foo' type.
Foo returns_foo() { return Foo(); }

int main(int argc, char* argv[]) {
  // Declare a vector of three integers. Note that we are also using another
  // post C++98 feature here (initializing the vector with the bracket syntax.)
  vector<int> a{1, 2, 3};

  // The 'auto' keyword has been repurposed. Prior to C++11, it was really the
  // default storage class for variables and was rarely used. Today, it is used
  // to declare a variable with a type that is deduced from the initializer
  // expression. In the example below, the variable 'it' is declared with auto,
  // and the type deduced is "iterator".
  //
  // Note also, there is yet another C++ feature (see: ranged-for-loops) that
  // exists as of C++11 that would be more canonical for writing the loop.
  for (auto it = a.begin(); it != a.end(); ++it) {
    cout << *it << endl;
  }

  // The type of a variable declared with auto is still strong and deduced at
  // compile time. It's *not* a variant type...
  auto some_val = returns_int();
  (void)some_val;

  // ...Which is why this is a compiler error: 'some_val' has already been
  // determined to be an integer. Because Foo has no conversion to int
  // defined, this is an error.
  // some_val = returns_foo();

  return 0;
}
