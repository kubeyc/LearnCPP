#include <iostream>

class Foo {
public:
    // constructor
    Foo(int data = 0)
        :_data(data)
    {}

    void* operator new(size_t size) {
        std::cout << "operator new to Foo object, malloc: " << size << " size." << std::endl;
        return malloc(size);
    }

    void operator delete(void *ptr, size_t size) {
        std::cout << "operator delete to Foo object, free: "<< size << " size." << std::endl;
        free(ptr);
    }

    void * operator new[](size_t size) {
      std::cout << "operator new[] to Foo object, malloc: " << size << " size." << std::endl;
      return malloc(size);
    }

    void operator delete[](void *ptr, size_t size) {
        std::cout << "operator delete[] to Foo object, free: "<< size << " size." << std::endl;
        free(ptr);
    }

    int get_data() const {return _data;}

private:
    int _data;
};

int main() {
    // use operator new, delete
    Foo *foo = new Foo;
    delete foo;

    // use operator new[], delete[]
    Foo *foo_array = new Foo[3];
    delete []foo_array;

}
