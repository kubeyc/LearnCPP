// function like classes - 类向函数一样使用
// 通过 operator() 实现

#include <iostream>
template <class T>
class plus {
public:
  T operator() (const T& x, const T& y) const { return x + y; };
};


int main() {
  plus<int> p;
  std::cout << p(1,2) << std::endl;
}
