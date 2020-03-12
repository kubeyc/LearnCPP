#include <iostream>
#include <cstring>

class string;
class stringRep;

class stringRep {
    friend string;
public:
    stringRep(const char* cstr=0);
    stringRep& operator= (const stringRep& rep);
    ~stringRep();
    inline char* get_c_str() const { return _c_str_meta; }
private:
    char* _c_str_meta;

};

stringRep::stringRep(const char* cstr) {
    if (cstr) {
        _c_str_meta = new char[strlen(cstr)+1];
        strcpy(_c_str_meta, cstr);
    } else {
        _c_str_meta = new char[1];
    }
}

stringRep& stringRep::operator= (const stringRep& rep) {
  if (this == &rep) {
      return *this;
  }

  delete[] _c_str_meta;
  _c_str_meta = new char[strlen(rep._c_str_meta)+1];
  strcpy(_c_str_meta, rep._c_str_meta);
  return *this;
}

stringRep::~stringRep() {
    delete[] _c_str_meta;
}

inline
std::ostream& operator<< (std::ostream& os, const stringRep& rep) {
    return os << rep.get_c_str();
}

class string {
public:
    string(const stringRep&);
    string(const char* cstr=0);
    string(const string&);
    string& operator= (const string&);
    string& operator= (const char*cstr);
    ~string();
    inline char* get_c_str() const { return _rep->_c_str_meta; }
private:
    friend inline std::ostream& operator<<(std::ostream& os, const string& s);
    stringRep* _rep;
};

string::string(const stringRep& rep) {
    _rep = new stringRep();
    *_rep = rep;
}

string::string(const char* cstr) {
    _rep = new stringRep(cstr);
}

string::string(const string& s) {
    _rep = new stringRep(s._rep->_c_str_meta);
}

string& string::operator= (const string& s) {
    if(s._rep == _rep) {
        return *this;;
    }

    delete _rep;
    _rep = new stringRep(s._rep->_c_str_meta);
    return *this;
}

string& string::operator= (const char*cstr) {
    delete _rep;
    _rep = new stringRep(cstr);
    return *this;
}

inline
std::ostream& operator<< (std::ostream& os, const string& s) {
    return os << *s._rep;
}

string::~string() {
  delete _rep;
}

int main() {
    stringRep rep("hello world");
    string s1(rep);
    std::cout << s1 << std::endl;

    string s2("s2");
    std::cout << s2 << std::endl;

    // 拷贝构造
    string s3(s2);
    std::cout << s3 << std::endl;

    // 操作符重载拷贝赋值
    string s4 = s3;
    std::cout << s4 << std::endl;

    // 操作符重载拷贝赋值
    string s5 = "s5";
    std::cout << s5 << std::endl;
}
