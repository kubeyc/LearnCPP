#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Foo {
public:
  Foo() = default;
  Foo(int n, double d)
    :data(n), d_data(d)
  {}

    void* operator new(size_t size) {
        cout << "operator new(size_t size)" << endl;
        return malloc(size);
    }

    // operator new placement arguments
    void* operator new(size_t size, int n, double d) {
      cout << "operator new(size_t size, int n, double d), n = " << n <<", d = " << d << endl;
      return malloc(size);
    }



    void operator delete(void* ptr, size_t size) {
      cout << "operator delete(void* ptr, size_t size)" << endl;
      free(ptr);
    }

    void operator delete(void* ptr, size_t size, int n, double d) {
      cout << "operator delete(void* ptr, size_t size, int n, double d), n = "<<n <<", d = " << d<< endl;
      free(ptr);
    }

    int get_data() const {return data;};

private:
    int data;
    double d_data;
};

int main() {
  // non-use placement arguments
  Foo *fooPtr = new Foo(10, 1.1);
  delete fooPtr;

  // use placement arguments
  Foo *fooPtr2 = new(10, 1.1) Foo(100, 11.1);
  delete fooPtr2;
}
