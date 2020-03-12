// pointer like classes - 类像指针一样使用
// 指针可以有这些操作, 假如p是一个pointer
// *p 取址
// ++p 常见于数组结构, 意为指向下一个元素
// --p
// 用class实现上述的操作使用operator

#include <iostream>
#include <vector>

template <class T>
class List;

template <class T>
struct __list_node {
  __list_node* prev;
  __list_node* next;
  T data;
};

template <class T>
struct __list_iterator {
  __list_iterator(__list_node<T>* p): node(p) {};
  __list_node<T>* node;
  T& operator* () const {return (*node).data; };
  __list_iterator& operator++ () {
    node = node->next;
    return *this;
  };

  __list_iterator& operator-- () {
    node = node->prev;
    return *this;
  }
};

template <class T>
class List {
public:
  List();

  ~List();

  void add_head(const T value);
  __list_iterator<T> iterator() { return __list_iterator<T>(head->next); };
private:
  __list_node<T>* head;
};

template <class T>
List<T>::List() {
  head = new __list_node<T>;
  head->prev = head->next = nullptr;
}

template<class T>
List<T>::~List() {
  delete head;
}

template<class T>
void List<T>::add_head(const T value) {
  __list_node<T> *node = new __list_node<T>;
  node->data = value;
  node->next = head->next;
  head->next = node;
  node->prev = head->next;
}

int main() {
  List<int>* list = new List<int>;
  list->add_head(1);
  list->add_head(2);
  list->add_head(3);
  auto ite = list->iterator();
  std::cout << *ite << std::endl; // 3
  std::cout << *(++ite) << std::endl; // 2
  std::cout << *(++ite) << std::endl; // 1

}
