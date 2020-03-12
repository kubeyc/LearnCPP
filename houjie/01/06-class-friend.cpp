#include <iostream>

class complex
{
private:
    double _re, _im;
public:
    complex(double re, double im): _re(re), _im(im) {}
    complex& operator +=(const complex&);

    // 友元函数声明, 即使不是class的成员函数, 也可以访问class的private变量
    inline friend complex& __doapl(complex *, const complex&);
};

inline
complex& __doapl(complex *ths, const complex& rhs) {
  ths->_re += rhs._re;
  ths->_im += rhs._im;
  return *ths;
}


complex& complex::operator+=(const complex& rhs) {
  return __doapl(this, rhs);
  // class 之间互为友元, 因此也可以这样写
  //  this->_re += rhs._re;
  //  this->_im += rhs._im;
}


int main() {
  complex c1(1, 3);
  complex c2(2, 4);
  c1+=c2;
}
