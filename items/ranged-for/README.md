# Ranged-based for loops

## About

With C++11, C++ joined the ranks of languages that had a reasonable way to
iterator over containers that didn't involve so much typing. Here's what
the situation was before, and after:

```C++
// In the dark days, before ranged-based iteration
vector<int> vec;
for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
  cout << *i;
}

// After the enlightenment!
for (auto elem : vec) {
  cout << elem;
}
```

The accompanying example shows how this is accomplished: by providing classes
with a minimum of functionality required to perform iteration. The requirements
are as follows:

1. The container must provide **begin()** and **end()** functions that return
   an "iterator" class (the iterator's requirements are described below.)
  a. **begin()** Must return an instance representing the start of the sequence.
  b. **end()** Must return an instance representing one past the end of the sequence.
2. The iterator must support the preincrement operator.
3. The iterator must support deferencing with the star operator '\*'.
4. The iterator must support equality comparison

## Commentary

As the examples show, this is most often used in conjunction with another C++11
feature, **auto**.  As with other uses of **auto** attention should be paid to
understand what the actual type of the variable is. You might be tempted, for
example, to think it is an iterator, but it is not!

The second example in the accompanying code that uses the **LessSimple**
container demonstrates this by using the typeid(class).name() facility to
print a type string for 'elem', and it is in fact 'c', which
is a char.

## Version Supported
C++11

## References
https://en.cppreference.com/w/cpp/language/range-for
