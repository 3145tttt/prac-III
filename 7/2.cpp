#include <iostream>
// #include <list>

template < typename T_arr, typename T_f>
T_arr myfilter(const T_arr &arr, T_f pred){
    T_arr cont;
    for(const auto &x: arr){
        if(pred(x)){
            cont.insert(cont.cend(), x);
        }
    }
    return cont;
}

// bool pred(int x){
//     return x > 2;
// }

// int main(){
//     std::list<int> a = {1, 2, 3, 4, 6, 0};
//     auto t = myfilter(a, pred);
//     for(auto x: t){
//         std::cout << x << std::endl;
//     }
// }