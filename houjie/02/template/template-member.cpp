template <class T1, class T2>
struct pair {
    T1 first;
    T2 second;
    pair() :first(T1()), second(T2()) {};

    // 类成员可以有自己的模板
    template <class U1, class U2>
    pair(const pair<U1, U2>& p): first(p.first), second(p.second) {}; 
};

class Base1{};
class Derived1 :public Base1 {};

class Base2{};
class Derived2 :public Base2 {};


int main() 
{   
    // 使用子类覆盖父类
    pair<Base1, Base2> pair (pair<Derived1, Derived2>());
    return 0;
}