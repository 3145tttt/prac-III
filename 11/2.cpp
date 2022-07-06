#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    std::set<char> N;
    std::map<char, std::vector<int>> ch_to_right_id;
    std::vector<std::string> P_l, P_r;

    std::string rule_l, rule_r;
    for(int i = 0; std::cin >> rule_l >> rule_r; ++i){
        P_l.push_back(rule_l);
        P_r.push_back(rule_r);
        char c = rule_l[0];
        ch_to_right_id[c].push_back(i);
        N.insert(c);
    }

    std::set<char> V = {'S'}, prev = V;
    for(size_t i = 0; i < N.size(); ++i){
        std::set<char> dif;
        for(char c: prev){
            const auto &ids = ch_to_right_id[c];
            for(int id: ids){
                std::string rule_r = P_r[id];
                for(char ch: rule_r){
                    if(ch >= 'A' && ch <= 'Z'){
                        dif.insert(ch);
                    }
                }
            }
        }
        
        size_t size = V.size();
        for(char c: dif){
            V.insert(c);
        }
        if(V.size() == (size_t)size){
            break;
        }
        prev = dif;
    }
    
    for(char ch: V){
        const auto &ids = ch_to_right_id[ch];
        for(int id: ids){
            std::cout << P_l[id] << ' ' << P_r[id] << std::endl;
        }
    }
    return 0;
}
