#include <iostream>
// #include <vector>
// #include <algorithm>

template< typename T>
void selection_sort(T begin, T end){
    for (T it = begin; it < end; it++){
        T min_it = it;
        for (T j = it + 1; j < end; j++){
            if (*j < *min_it){
                min_it = j;
            }
        }
        if (min_it != it){
            auto t = *min_it;
            *min_it = *it;
            *it = t;
        }
    }
}


template< typename T, typename T_comp>
void selection_sort(T begin, T end, T_comp cmp){
    for (T it = begin; it < end; it++){
        T min_it = it;
        for (T j = it + 1; j < end; j++){
            if (cmp(*j, *min_it)){
                min_it = j;
            }
        }
        if (min_it != it){
            auto t = *min_it;
            *min_it = *it;
            *it = t;
        }
    }
}


//код похож на код из википедии, не плагиат
//не знаю как написать сильно по другому

// bool cmp(int a, int b){
//     return a > b;
// }
// int main(){
//     std::vector<int> a = {1, 3, 3, -4, 6, 0};
//     selection_sort(a.begin(), a.end(), cmp);
//     std::sort(a.begin(), a.end(), cmp);
//     for(auto x: a){
//         std::cout << x << std::endl;
//     }
// }