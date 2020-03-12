#include <iostream>

template <class T>
class shared_ptr {
public:
    shared_ptr(T* p) :px(p) {};
    inline T* operator-> () { return px; };
    inline T& operator*() { return *px; }
private:
    T* px;
    long* pn;
};

class Foo{
public:
    inline void print() {
        std::cout << "Foo" << std::endl;
    }
};

int main() {
    shared_ptr<Foo> sp(new Foo);
    sp->print();
}
