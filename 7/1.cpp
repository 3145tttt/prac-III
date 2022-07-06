#include <iostream>
// #include <vector>

template<typename T_Container>
auto process(T_Container cont) -> decltype(cont)::value_type {
    enum { MAX = 6 };
    typename T_Container::value_type s{};
    int count = 1;
    for(auto it = cont.rbegin(); count < MAX && it != cont.rend(); ++it){
        if(count & 1){
            s += *it;
        }
        ++count;
    }
    return s;
}

// int main(){
//     std::vector<int> a = {1, 3, 3, 4, 6, 0};
//     std::cout << process(a);
// }