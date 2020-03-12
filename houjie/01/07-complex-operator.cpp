#include <iostream>

class complex;

inline
complex& __doapl(complex* ths, const complex& rhs);

class complex {
private:
    double _re, _im;
public:
    complex() = default;
    complex(double re, double im): _re(re), _im(im){}

    // complex class 类内部重载
    complex& operator+= (const complex& rhs) {
        return __doapl(this, rhs);
    }

    double real() const;
    double imga() const;

    friend inline complex& __doapl(complex* ths, const complex& rhs);
};

inline
complex& __doapl(complex* ths, const complex& rhs) {
    ths->_re + rhs._re;
    ths->_im + rhs._im;
    return *ths;
}

inline
double complex::real() const { return _re;}

inline
double complex::imga() const { return _im;}

// complex class 外部的操作符重载, complex + complex
inline
complex operator+ (const complex& x, const complex& y) {
    return complex(x.real()+y.real(), x.imga()+y.imga());
}

// complex class 外部操作符重载, complex虚部 + double
inline
complex operator+ (const complex& x, double im) {
    return complex(x.real(), x.imga() + im);
}

// complex class 外部操作符重载, complex实部 + double
inline
complex operator+ (double re, const complex& x) {
    return complex(re+x.real(), x.imga());
}


// complex class 外部操作符重载, complex取反
inline
complex operator- (const complex& x) {
    return complex(-x.real(), -x.imga());
}

// complex class 外部操作符重载, complex相减
inline
complex operator- (const complex& x, const complex& y) {
    return complex(x.real()-y.real(), x.imga()-y.imga());
}


// complex class 外部操作符重载, 比较complex是否相等
inline
bool operator== (const complex& x, const complex& y) {
    return x.real() == y.real() && x.imga() == y.imga();
}

// complex class 外部操作符重载, 重载输出complex


int main() {
    complex c1(1, 3);
    complex c2(4, 9);
    c2 = c1 + c2;
    c2 = c2 + 8;
    c2 = 9 + c2;
    c2 = -c2;
    c2 = c2 -c1;
}
