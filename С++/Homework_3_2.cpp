#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>

class T {
public:
    int row, number;
};

bool operator<(const T& left, const T& right) {
    if (left.row > right.row)
        return false;
    if (left.row == right.row) {
        if (left.number < right.number)
            return true;
        return false;
    }
    return true;
}
bool operator==(const T& left, const T& right) {
    if ((left.row == right.row) && (left.number < right.number))
        return true;
    return false;
}

namespace std {
    template<> struct hash <T> {
        std::size_t operator()(const T& k) const {
            return (std::size_t)(k.row * 10 + k.number);
        }
    };
}

int main() {
    T a, p, n;

    //rows
    a.row = 4;
    p.row = 4;
    n.row = 3;
    //numbers
    a.number = 10;
    p.number = 15;
    n.number = 10;

    std::map<T, std::string> dic;
    std::unordered_map<T, std::string> finder;

    //dics
    dic[a] = "Artem";
    dic[p] = "Petya";
    dic[n] = "Nastya";

    //finders
    finder[a] = "Alisa";
    finder[p] = "Kolya";
    finder[n] = "Artem";

    //out
    std::cout << finder[a] << std::endl;
    std::cout << finder[p] << std::endl;
    std::cout << finder[n] << std::endl;
    std::cout << dic[a] << std::endl;
    std::cout << dic[p] << std::endl;
    std::cout << dic[n] << std::endl;
}
