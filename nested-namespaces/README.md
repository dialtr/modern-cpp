# Nested Namespace

## About

It is now possible to declare namespaces in a nested way, to save typing.

Example:

```C++
// Before C++17
namespace org {
namespace dial {
namespace demo {

  // ...stuff

}  // namespace demo
}  // namespace dial
}  // namespace org

// After C++17
namespace org::dial::demo {

// ...stuff

}  // namespace org::dial::demo
```

## Version Supported

This feature was added in C++17
