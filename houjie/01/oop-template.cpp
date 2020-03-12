// 使用继承来实现template模式
// 父类定义来公共的行为, 同时为继承自身的类声明pure virtual function,
// 子类继承后实现父类要求的特有的行为的pure virtual
#include <iostream>
#include <string>

using namespace std;

class Document {
public:
    // 公共行为: 打开文件
    virtual void onFileOpen(const string& file);

    // 特定行为: 不同文件的序列化格式不同
    virtual void serialize() = 0; // 子类实现序列化方法
};

void Document::onFileOpen(const string &file) {
    cout << "open file: " << file << "...." << endl;
    serialize();
    cout << "cloe file: " << file << "..." << endl;
}

class TxtDocument :public Document {
    // 重写父类的pure virtual, 实现特定行为
    void serialize() override;
};

void TxtDocument::serialize() {
    cout << "txt file format serialize" << endl;
}

int main() {
    TxtDocument txt;
    txt.onFileOpen("test.txt");
}
