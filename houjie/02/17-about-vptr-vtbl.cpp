#include <iostream>

using std::cout;
using std::endl;

class A {
public:
  virtual void vfunc1();
  virtual void vfunc2();
  void func1();
  void func2();
private:
  int m_data1, m_data2;
};

void A::vfunc1() {
  cout << "A::vfunc1()"<< endl;
}

void A::vfunc2() {
  cout << "A::vfunc2()"<< endl;
}

class B :public A {
public:
  virtual void vfunc1() override;
  void func2();
private:
  int m_data3;
};

void B::vfunc1() {
  cout << "B::vfunc1()"<< endl;
}

void B::func2() {
  cout << "B::func2()" << endl;
}

class C :public B {
public:
  virtual void vfunc1() override;
  void func2();
private:
  int m_data1, m_data4;
};

void C::vfunc1() {
  cout << "C::vfunc1()"  << endl;
}

void C::func2() {
  cout << "C::func2() " << endl;
}

int main()
{
    C c;
    c.vfunc1(); // override
    c.vfunc2(); // class A vfunc2()
    c.func2(); // C private
    return 0;
}
