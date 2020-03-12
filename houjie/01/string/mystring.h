#ifndef _MYSTRING_
#define _MYSTRING_


#include <iostream>
#include<cstring>
using namespace std;

class mystring;

class mystring {
private:
    char* s_meta;
public:
    mystring(const char* cstr = 0); // 普通构造函数
    mystring(const mystring& s); // 拷贝构造函数
    mystring& operator= (const mystring& s); // 拷贝赋值函数
    ~mystring(); // 析构函数

    char* get_c_str() const {return s_meta;};
};


mystring::mystring(const char* cstr) {

    if (!cstr) {
        s_meta = new char[1];
    } else {
        s_meta = new char[strlen(cstr) + 1];
        strcpy(s_meta, cstr);
    }
}

// 拷贝构造函数, 客户端这样使用: string(s1)
mystring::mystring(const mystring& s) {
    s_meta = new char[strlen(s.s_meta)+1];
    strcpy(s_meta, s.s_meta);
}

// 拷贝赋值重载构造函数, 客户端这样使用: string s1 = s2;
mystring& mystring::operator= (const mystring& s) {
    if(this == &s) {
        return *this;
    }

    delete []s_meta;
    s_meta = new char[strlen(s.s_meta)+1];
    strcpy(s_meta, s.s_meta);
    return *this;
}

mystring::~mystring() {
  delete []s_meta;
}


// 重载 << 输出
std::ostream& operator<< (std::ostream& os, const mystring& s) {
    return os << s.get_c_str();
}


#endif // STRING_H
