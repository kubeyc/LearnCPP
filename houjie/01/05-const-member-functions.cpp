// const成员函数:
// 如果class声明为const, 则只能调用成员函数为const的函数
// 如果class没声明为const, 则两者都可以调用
#include <iostream>

class complex {
private:
    double re, im;
public:
    complex(double re, double im): re(re), im(im) {}
    double real() const {return re;}
    double imga() const {return im;}
};

int main() {
    complex c(3, 4);
    c.real();
    c.imga();

    // 如果此时real或者imga没有声明为const成员函数则会报错
    const complex c2 (1, 2);
    c2.real();
    c2.imga();
}
