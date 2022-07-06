#include <iostream>
#include <vector>

void process(std::vector<int64_t>& vec, int64_t max_val){
    auto it = vec.rbegin();
    for(ssize_t count = 0; it != vec.rend(); ++count, it = vec.rbegin() + count){
        if(*it >= max_val){
            vec.push_back(*it);
            ++count;
        }
    }
}

int main(){
    std::vector<int64_t> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    process(vec, 3);

    for(auto x : vec){
        std::cout << x << std::endl;
    }

    return 0;
}