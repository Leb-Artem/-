#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>

class cinema{
public:
    int row, number;
//лучше конечно писать гетеры и сетеры
};

bool operator<(const cinema& left, const cinema& right) {
    if(left.row > right.row)
        return false;
    if(left.row == right.row){
        if(left.number < right.number)
            return true;
        return false;
    }
    return true;
}
bool operator==(const cinema& left, const cinema& right) {
    if((left.row == right.row) && (left.number < right.number))
        return true;
    return false;
}

namespace std {
        template<> struct hash <cinema> {
          std::size_t operator()(const cinema& k) const {
            return (std::size_t)(k.row * 10 + k.number); 
        }
     };
}


int main(){
    cinema s1, s2, s3;
    s1.row = 4;
    s1.number = 10;
    s2.row = 4;
    s2.number = 15;
    s3.row = 3;
    s3.number = 10;
    std::map<cinema, std::string> dic;
    std::unordered_map<cinema, std::string> finder;
    finder[s1] = "Vasya";
    finder[s2] = "Masha";
    finder[s3] = "Olya";
    dic[s1] = "Nikita";
    dic[s2] = "Petya";
    dic[s3] = "Vasya";
    std::cout << finder[s1];
    std::cout << std::endl;
    std::cout << finder[s2];
    std::cout << std::endl;
    std::cout << finder[s3];
    std::cout << std::endl;
    std::cout << dic[s1];
    std::cout << std::endl;
    std::cout << dic[s2];
    std::cout << std::endl;
    std::cout << dic[s3];
    std::cout << std::endl;

}