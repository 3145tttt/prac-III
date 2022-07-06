#include <algorithm>
#include <vector>
#include <iostream>

void process(const std::vector<int>& v1, std::vector<int>& v2){
    std::vector<int> local_v1 = v1;
    std::sort(local_v1.begin(), local_v1.end());
    auto last = std::unique(local_v1.begin(), local_v1.end());
    auto res = v2.begin();
    int pos = 0;
    auto it_check = local_v1.begin();
    while(it_check != last && *it_check < 0){
        ++it_check;
    }
    for(auto tmp = v2.begin(); tmp != v2.end(); ++tmp, ++pos){
        if(it_check < last){
            if(*it_check != pos){
                *res = *tmp;
                ++res;
            } else if(*it_check <= pos){
                ++it_check;
            }
        } else {
            *res = *tmp;
            ++res;
        }
    }
    v2.erase(res, v2.end());
}