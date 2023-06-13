#include <iostream>

using ::std::cout;
using ::std::endl;

// You may now declare nested namespaces more conveniently, like this:
namespace org::dial::demo {

void hello() { cout << "Hello, World!" << endl; }

}  // namespace org::dial::demo

using ::org::dial::demo::hello;

int main(int argc, char* argv[]) {
  hello();
  return 0;
}
