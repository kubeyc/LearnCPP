// cpp 构造函数列表初始化特性和构造函数重载

#include <iostream>

class MyArray {
public:
    MyArray() = default;
    // constructor initiization list
    MyArray(int *arr, size_t size = 10):__arr(arr), __size(size){}
    MyArray(size_t size): __size(size), __arr(new int[size]) {}

    // constructor copy array
    MyArray(int *arr, size_t arr_size, size_t size);

    ~MyArray() {free(__arr);}

    void printArray();
private:
    int* __arr;
    size_t __size;
};


// 对array进行拷贝构造
MyArray::MyArray(int *arr, size_t arr_size, size_t size) {
    assert(size > arr_size);

    __size = size;
    __arr = new int[__size];
    for (int i = 0; i < arr_size; i++) {
        __arr[i] = arr[i];
    }
}

void MyArray::printArray() {
    for (int i = 0; i < __size; i++) {
        std::cout << *(__arr + i);
        if (i != __size - 1) std::cout <<", ";
    }
    std::cout << std::endl;
}


int main() {
    int *arr = new int[5]{1,2,3,4,5};
    MyArray myArray(arr, 5, 10);
    myArray.printArray();
    free(arr);
}
