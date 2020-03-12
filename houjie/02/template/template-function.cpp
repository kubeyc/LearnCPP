// function 使用模板

template <typename T>
class stone
{
public:
    stone(T h, T w, T weight) :height(h), width(w), weight(weight) {};
    bool operator < (const stone& other) const {
        return height < other.height && width < other.height && weight < other.weight;
    }

    T get_height() const { return height; };
    T get_width() const { return width; };
    T get_weight() const { return weight; };
private:
    T height; T width; T weight;
};


template <typename T>
inline 
const T& min(const T& x, const T& y) {
    return x < y? x : y;
}

#include <iostream>

template <typename T>
inline
std::ostream& operator<< (std::ostream& os, const stone<T>& stone) {
    return os << "stone " 
    << "height: " << stone.get_height()
    << ", width: " << stone.get_width()
    << ", weight: " << stone.get_width();
}

int main()
{
    stone<int> stone1(10, 20, 30);
    stone<int> stone2(30, 40, 50);
    auto minStone = min(stone1, stone2);
    std::cout << "minimum " << minStone << std::endl;
}