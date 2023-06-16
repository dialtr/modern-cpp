#include <cstring>
#include <iostream>
#include <vector>

using ::std::cout;
using ::std::endl;
using ::std::vector;

// A simple class that wraps a C-style string for iteration by character.
class Simple {
 public:
  Simple(const char* str) : str_(str), len_(strlen(str)) {}

  // Provide a 'begin' function that returns something that acts like
  // an iterator. Here, we return a pointer. The requirements of the
  // type are that it must support comparison, preincrement, and
  // dereferencing.
  const char* begin() const { return str_; }

  const char* end() const { return (str_ + len_); }

 private:
  const char* str_;
  size_t len_;
};

// A less simple implementation of a class that makes the iterator
// requirements explicit.
class LessSimple {
 public:
  // Iterator class.
  class Iterator {
   public:
    Iterator(const char* data, size_t index) : data_(data), index_(index) {}

    // Preincrement operator
    const Iterator operator++() {
      Iterator copy(data_, index_);
      ++index_;
      return copy;
    }

    // Dereferencing
    char operator*() const { return data_[index_]; }

    // Equality test (See below for non-member)
    bool operator==(const Iterator& other) const {
      return (index_ == other.index_);
    }

   private:
    const char* data_;
    size_t index_;
  };

  LessSimple(const char* data) : data_(data), len_(strlen(data)) {}

  // Return Iterator to start of sequence.
  Iterator begin() const { return Iterator(data_, 0); }

  // Return Iterator to one past end of sequence.
  Iterator end() const { return Iterator(data_, len_); }

 private:
  const char* data_;
  size_t len_;
};

int main(int argc, char* argv[]) {
  vector<int> numbers{1, 2, 3, 4, 5};

  // As of C++11, C++ now has a "ranged for" loop, similar to other languages.
  // When combined with the 'auto' keyword, looping over collections becomes
  // terse and more readable.
  for (auto n : numbers) {
    cout << n << endl;
  }

  // Any class can be extended to support ranged-based for loop integration.
  // The 'Simple' class above implements a simple container that accepts a
  // reference to a C string so that it can be iterated letter by letter.
  Simple simple("Hello, Simple!");
  for (auto ch : simple) {
    cout << ch;
  }
  cout << endl;

  // A less simple example that actually uses custom iteration.
  LessSimple less_simple("Hello, Less Simple!");
  for (auto elem : less_simple) {
    cout << elem << ", " << typeid(elem).name() << endl;
  }
  cout << endl;

  return 0;
}
