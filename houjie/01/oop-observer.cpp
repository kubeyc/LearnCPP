// observer模式: 是继承+委托的一种组合
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Observer {
private:
    string _name;
    int _height, _width;
public:
    inline Observer(string name): _name(name) {};
    void updateView(const int h, const int w);
    void printView();
};

void Observer::updateView(const int h, const int w) {
    _height = h;
    _width = w;
}

void Observer::printView()  {
    std::cout << "objser " << _name << ": height = " << _height <<
                 ", width = " << _width << ";" << std::endl;
}

class Subject {
private:
    int _height, _width;
    vector<Observer*>* _views;
    void updateViews();
public:
    Subject();
    ~Subject();
    void push (Observer* ob);
    void setViewPosition(const int h, const int w);
    void showViews();
};

Subject::Subject() {
    _views = new vector<Observer*>;
}

Subject::~Subject() {
    delete _views;
}

void Subject::push(Observer *ob) {
    _views->push_back(ob);
}

void Subject::setViewPosition(const int h, const int w) {
    _height = h;
    _width = w;
    updateViews();
}

void Subject::updateViews() {
    for(auto iter = _views->begin(); iter != _views->end(); iter++) {
        static_cast<Observer*>(*iter)->updateView(_height, _width);
    }
}

void Subject::showViews() {
    for(auto iter = _views->begin(); iter != _views->end(); iter++) {
        static_cast<Observer*>(*iter)->printView();
    }
}


int main() {
    Subject subject;
    Observer ob1("ob1");
    Observer ob2("ob2");
    subject.push(&ob1);
    subject.push(&ob2);
    subject.setViewPosition(100, 100);
    subject.showViews();
}
