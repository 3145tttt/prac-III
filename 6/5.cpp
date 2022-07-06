#include <iostream>
#include <map>

int main(){
    using std::map;
    enum {MOD = 4294967161};

    map<std::pair<unsigned, unsigned>, unsigned long long> matrix1;
    map<unsigned, map<unsigned, unsigned long long>> matrix2;

    unsigned id1, id2;
    unsigned long long value;
    while(std::cin >> id1 >> id2 >> value) {
        if(id1 == 0 && id2 == 0 && value == MOD){
            break;
        }

        matrix1[std::make_pair(id1, id2)] = value;
    }
    while(std::cin >> id1 >> id2 >> value) {
        matrix2[id1][id2] = value;
    }
    map<std::pair<unsigned, unsigned>, unsigned long long> matrix3;
    for(const auto &[key, val1]: matrix1){
        auto row_i = matrix2[key.second];
        for(auto [j, val2]: row_i){
            matrix3[std::make_pair(key.first, j)] += (val1*val2) % MOD;
            matrix3[std::make_pair(key.first, j)] %= MOD;
        }
    }

    for (const auto &[key, val] : matrix3) {
        if(val != 0){
            std::cout << key.first << " " << key.second 
                << " " << val << std::endl;
        }
    }


}