// 操作符重载: 类型转换
#include <iostream>

class Fraction {
public:
  Fraction(int num, int deno)
    :_numerator(num), _denominator(deno)
  {}

  // 类型转换重载, 可以用于class转换为double时
  operator double() const {
     return (double)(_numerator/_denominator);
  }
private:
    int _numerator; // 分子
    int _denominator; // 分母
};

int main()
{
  Fraction *fraction = new Fraction(3, 5);

  // 此时*fraction执行操作符重载, 重载的是double类型转换
  // 调用operator double() 将fraction转换为0.6
  double d = 4 + *fraction;

  std::cout << d << std::endl;

  delete fraction;

  return 0;
}

