#include <iostream>
#include <vector>

void process(const std::vector<uint64_t>& vec1, std::vector<uint64_t>& vec2,
            size_t step){
    size_t skip = 0;
    for(auto iter2 = vec2.rbegin(); iter2 != vec2.rend() && skip < vec1.size(); ++iter2){
        auto iter1 = vec1.begin() + skip;
        *iter2 += *iter1;
        skip += step;
    }
}

// int main(){
//     std::vector<uint64_t> vec1;
//     vec1.push_back(1);
//     vec1.push_back(2);
//     vec1.push_back(3);
//     vec1.push_back(4);
    

//     std::vector<uint64_t> vec2;
//     vec2.push_back(1);
//     vec2.push_back(2);
//     vec2.push_back(3);
//     vec2.push_back(5);
//     vec2.push_back(5);
//     vec2.push_back(5);
//     vec2.push_back(5);
//     process(vec1, vec2, 5);

//     for(auto x : vec2){
//         std::cout << x << std::endl;
//     }

//     return 0;
// }