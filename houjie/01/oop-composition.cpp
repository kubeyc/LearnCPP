#include <deque>
#include <iostream>
template <class T, class sequence = std::deque<T>>

class queue
{
typedef T& ref;
public:
    ref front() { return seq.front(); }
    ref back() {return seq.back(); }
    void push(const T& x) {seq.push_back(x);}
    void pop(){seq.pop_front();}
protected:
    sequence seq;
};


int main () {
  queue<int, std::deque<int>> *q = new queue<int, std::deque<int>>;

  q->push(1);
  q->push(2);
  std::cout << "front:" << q->front() << ", back: " << q->back() << std::endl;
  q->pop();
  std::cout << q->front() << std::endl;
  delete q;
}
