#include <iostream>
#include <map>

int main(){
    using std::map;
    enum {MOD = 4294967161};

    map<std::pair<unsigned, unsigned>, long long> matrix1;
    map<std::pair<unsigned, unsigned>, long long> matrix2;

    unsigned id1, id2;
    long long value;
    while(std::cin >> id1 >> id2 >> value) {
        if(id1 == 0 && id2 == 0 && value == MOD){
            break;
        }

        matrix1[std::make_pair(id1, id2)] = value;
    }

    while(std::cin >> id1 >> id2 >> value) {
        matrix2[std::make_pair(id1, id2)] = value;
    }

    for (const auto& [key, value] : matrix2) {
        long long t = matrix1[key] + value;
        t %= MOD;
        if(t == 0){
            auto it = matrix1.find(key);
            matrix1.erase(it);
        } else {
            matrix1[key] = t;
        }
    }

    for (const auto& [key, value] : matrix1) {
        std::cout << key.first << " " << key.second 
            << " " << value << std::endl;
    }


}