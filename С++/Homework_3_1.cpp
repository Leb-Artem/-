#include <iostream>
#include <list>
#include <map>
#include <vector>

template <typename T> void reverse(std::vector<T>& p_collection) {
    int size = p_collection.size();
    for (int i = 0; i < size / 2; ++i) {
        T tmp = p_collection[i];
        p_collection[i] = p_collection[size - 1 - i];
        p_collection[size - 1 - i] = tmp;
    }
}

template <typename T> void reverse(std::list<T>& p_collection) {
    for (auto it = p_collection.begin(); it != p_collection.end();) {
        p_collection.push_front(*it);
        p_collection.erase(it++);
    }
}

int main() {

    std::vector<double> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };   // {} - список инициализации, заполняющий требуемыми вектор
    std::list<double> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("list b: "); for (auto i : l) printf("%2.0f", i);
    reverse(l);
    printf("\nvector b: "); for (auto i : v) printf("%2.0f", i);
    reverse(v);
    printf("\nlist a: "); for (auto i : l) printf("%2.0f", i);
    printf("\nvector a: "); for (auto i : v) printf("%2.0f", i);
    return 0;
}
