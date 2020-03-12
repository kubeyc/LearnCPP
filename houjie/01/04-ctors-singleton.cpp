#include <iostream>

class Singleton
{
private:
    static Singleton* m_instance;
    Singleton();
public:
    static Singleton* getInstance()
    {
      if (m_instance == NULL) {
           m_instance = new Singleton;
      }
      return m_instance;
    }
};


int main(){
    Singleton *v1 = Singleton::getInstance();
    Singleton *v2 = v1->getInstance();
    std::cout << "v1 addr: " << v1 << std::endl;
    std::cout << "v2 addr: " << v2 << std::endl;
    delete v1;
    return 0;
}
