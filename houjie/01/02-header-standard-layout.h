// cpp header头文件比较标准的布局格式
// 下面以complex为例

#ifndef COMPLEX_H
#define COMPLEX_H
#include <cmath>

// 第一部分: 前置声明
// 用于为后续声明提供使用, 前置声明意味着可以先声明, 后实现
class complex;
complex& __doapl(complex* ths, const complex& r);

// 第二部分: class声明
// 其中class内部声明又分为: header body
// class body内部声明访问级别, 访问级别可以多次声明, 没有声明访问级别对成员为private
class complex // class header
{ // class body
public:
    double get_real(); // 如果在class body只声明, 在外部定义实现, 编译器可能优化为内联函数, 最好显式的加上 inline
    double get_im() { return _im; }; // class body内的简单成员函数,如对外提供get和set的可以被编译器优化为内联函数
private:
    double _re, _im;
    friend complex& __doapl(complex* ths, const complex& r);
};

// 第三部分: class类内部定义实现
inline
double complex::get_real() {
    return this->_re;
}

#endif // COMPLEX_H
