#include "mystring.h"

int main() {
    // 默认构造函数
    mystring s1("hello");

    // 拷贝构造函数
    mystring s2(s1);

    // 赋值构造函数
    mystring s3 = s1;

    std::cout << "s1 = " << s1 << ", s2 = " << s2 << ", s3 = " << s3 << std::endl;
}
