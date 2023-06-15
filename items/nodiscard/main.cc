#include <iostream>

using ::std::cout;
using ::std::endl;

// Example: allocate a resource.
[[nodiscard]] int AllocateResource() { return 1; }

int main(int argc, char* argv[]) {
  // Calling without using would cause a warning.
  // AllocateHandle();

  // Resolve by ensuring the result is assigned to a variable.
  const int handle = AllocateHandle();

  // Note: this cast to void avoids an unused variable warning...
  (void)handle;

  // ...And so you could avoid the warning "if you know what you're doing" by
  // casting to void like this:
  (void)AllocateHandle();

  return 0;
}
