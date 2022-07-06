#include <iostream>
#include <algorithm>
#include <vector>

int count_ones(unsigned a){
    int count = 0;
    while(a){
        count += a & 1;
        a >>= 1;
    }
    return count;
}

bool my_cmp(unsigned a, unsigned b){
    return count_ones(a) < count_ones(b);
}

int main(){
    std::vector<unsigned> arr;
    unsigned tmp;
    while(std::cin >> tmp){
        arr.push_back(tmp);
    }

    std::stable_sort(arr.begin(), arr.end(), my_cmp);
    for(auto x: arr){
        std::cout << x << std::endl;
    }
}