// inheritance 和 virtual函数
// non-virtual 函數: 你不希望派生 class 重新定义 (override, 复写) 它.
// virtual 函數: 你希望派生 class 重新定义 (override, 复写) 它，且本身对这个函数有定义
// pure virtual 函數:你希望派生 class 必须要重新定义 (override, 复写) 它，你对它沒有默认定义
#include <string>
#include <iostream>

class Shape {
public:
    Shape() {_objectID = new std::string("shape");};
    virtual ~Shape();
    virtual void draw() = 0; // pure virtual
    virtual void error(const std::string& s); // virtual
    std::string& objectID() const; // non-virtual;
private:
    std::string* _objectID;
};

Shape::~Shape() {
    delete _objectID;
}

// virtual 函数, 父类实现, 子类可以继承也可以重写
void Shape::error(const std::string &s) {
   std::cout << "Shape error: " << s << std::endl;
}

// virtual 函数, 子类不可以重写
std::string& Shape::objectID() const {
    return *_objectID;
}

// Rectangle 继承 Shape
class Rectangle :public Shape {
public:
    Rectangle() {_objectID = new std::string("rectangle");}
    ~Rectangle();
     void draw() override; // 实现父类pure virtual函数
     void error(const std::string& s) override; // 重写父类virtual函数
private:
     std::string* _objectID;
};

Rectangle::~Rectangle() {
    std::cout << "call Rectangle destrucotr" << std::endl;
    delete _objectID;
}

void Rectangle::draw() {
    std::cout << "Rectangle draw" << std::endl;
}

void Rectangle::error(const std::string& s) {
    // 调用父类对virtual函数, 父类virtual已经实现
    Shape::error(s);
    std::cout << "Rectangle error: " << s << std::endl;
}


int main() {
    Shape* shape = new Rectangle;
    shape->draw();
    shape->error("some error");
    shape->objectID();

    // 这里应该调用Rectangle对析构函数, 因此Shape类对析构函数要声明成virtual的
    // 当然也可以声明为pure virtual, 但是这样的情况下一定要保证Shape类没有对内存的使用
    delete shape;
}
