// explicit 用于显示声明不允许隐式转换
#include <iostream>

class MyInt {
public:
  explicit MyInt(int i) :_data(i){}
private:
  int _data;
};


int main() {
  // 由于声明了explicit, 因此int不能隐式转换为MyInt class
//  MyInt i = 1; // error
}
