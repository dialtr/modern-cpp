# The auto keyword

## About

Prior to C++11, the **auto** keyword was a "storage class" specifier in the
family of (auto, extern, static, register.) The **auto** storage class was
the default, and indicated a variable declared at local scope on the stack.

For C++11, **auto** was repurposed to make declaring variables of complex
types less tedious. For example:

```C++
// Prior to C++11, programmers would be required to type out the full
// type name of complex types, which was tedious:
std::vector<int> vec;
std::vector<int>::iterator vec_iter = vec.begin();

// Starting with C++11, this became possible:
auto vec_iter = vec.begin();

```

The compiler deduces the type of **auto** variables from the initializing
expression.

## Commentary

It is not *always* obvious what the deduced type is. (Note: this may not
be true for someone who is more experienced with modern C++ than I am.)

Meyers' book, "Effective Modern C++" covers this topic in detail and is an
excellent reference.

## Version Supported
C++11

## References
https://en.cppreference.com/w/cpp/language/auto

"Effective Modern C++: 42 Specifcs Ways to Improve Your Use of C++11 and C++14" by Scott Meyers
