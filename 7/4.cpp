#include <iostream>
#include <algorithm>

template <typename Iter1, typename Iter2>
Iter2 myremove(Iter1 pos_begin, Iter1 pos_end, Iter2 nums_begin, Iter2 nums_end){
    std::vector<int> local_v1(pos_begin, pos_end);
    std::sort(local_v1.begin(), local_v1.end());
    auto last = std::unique(local_v1.begin(), local_v1.end());
    auto res = nums_begin;
    int pos = 0;
    auto it_check = local_v1.begin();
    while(it_check != last && *it_check < 0){
        ++it_check;
    }
    for(auto tmp = nums_begin; tmp != nums_end; ++tmp, ++pos){
        if(it_check < last){
            if(*it_check != pos){
                std::iter_swap(res, tmp);
                ++res;
            } else if(*it_check <= pos){
                ++it_check;
            }
        } else {
            std::iter_swap(res, tmp);
            ++res;
        }
    }
    return res;
}