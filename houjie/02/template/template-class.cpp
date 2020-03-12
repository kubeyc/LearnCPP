// class 使用模板

#include <iostream>

template<typename T>
class complex
{
private:
    T re, im;
public:
    complex(T r = 0, T i = 0) :re(r), im(i) {};
    T real() const { return re; };
    T imga() const { return im; };
};

template <typename T>
inline
std::ostream& operator<< (std::ostream& os, const complex<T>& c) 
{
    return os << "complex real: " << c.real() << ", imga: " << c.imga();
}

int main()
{
    complex<int> c1(1, 2);
    complex<double> c2(3.0, 4.1);
    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
}