#include <iostream>
#include <vector>
#include <map>
#include <list>


template <typename T> void reverse(std::vector<T>& p_collection){
    int size = p_collection.size();
    for(int i = 0; i < size/2; ++i){
        T temp = p_collection[i];
        p_collection[i] = p_collection[size - 1 - i];
        p_collection[size - 1 - i] = temp;
    }
}
template <typename T> void reverse(std::list<T>& p_collection){
    for(auto it = p_collection.begin(); it != p_collection.end();){
        p_collection.push_front(*it);
        p_collection.erase(it++);
    }
}

int main(){
    std::vector<double> v{1, 2, 3, 4, 5, 6, 7, 8, 9};   // {} - список инициализации, заполняющий требуемыми вектор
    std::list<double> l{1,2,3,4,5};
    printf(" vector before: "); for (auto i : v) printf("%2.0f", i);
    reverse(v);
    printf("\n vecotr after: "); for (auto i : v) printf("%2.0f", i);

    printf("\n lis tbefore: "); for (auto i : l) printf("%2.0f", i);
    reverse(l);
    printf("\n list after: \n"); for (auto i : l) printf("%2.0f", i);
    return 0;
}


