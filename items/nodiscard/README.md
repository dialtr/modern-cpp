# The [[nodiscard]] Attribute

## About

Applying the **[[nodiscard]]** attribute to a return value informs the compiler
that the result of the function should be used. If not, the compiler is
"encouraged to issue a warning."

Example:

```C++
[[nodiscard]] int AllocateResource) {
  // Pretend to allocate a valuable resource.
  return 1;
}

// Not using result is a warning
AllocateResource();

// Good: using return value.
const int r = AllocateResource();

// Okay: Indicate we "know what we are doing" by casting to void.
(void)AllocateResource();
```

## Commentary

I think that a good use case for **[[nodiscard]]** would be for functions
that allocate an unmanaged or "raw" resource, since in that situation, not
assigning the resturn value would likely result in some kind of a resource
leak.

Imagine a wrapper function that allocates a file handle or socket; unless
the function returns a unique pointer or shared pointer to the object, not
assigning the value would definitely mean the handle was leaked:

```C++
// Function prototype
int OpenFile(const char* filename);

// A leak!
OpenFile("foo.txt");
```

One might also argue that **[[nodiscard]]** could be applied *liberally*
in any case where a function returns an error code. After all, do you want
any programs to be ignoring errors?

Prior to this feature, it was still possible to be informed of unused
return values by providing a compiler flag to issue the warning. But using
this attribute is a more fine-grained approach to the issue that allows
the programmer to be more explicit about when it is of particular concern.


## Version Supported

This feature was added in C++17

## References
https://en.cppreference.com/w/cpp/language/attributes/nodiscard
