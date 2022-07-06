#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

template <typename Iter, typename F>
void myapply(Iter v_begin, Iter v_end, F my_func){
    for(auto t = v_begin; t != v_end; ++t){
        my_func(*t);
    }
}

template <typename Iter, typename F>
auto myfilter2(Iter v_begin, Iter v_end, F pred){
    typedef typename std::iterator_traits<Iter>::value_type Iter_val;

    std::vector<std::reference_wrapper<Iter_val>> arr;
    for(auto t = v_begin; t != v_end; ++t){
        if(pred(*t)){
            arr.push_back(*t);
        }
    }
    return arr;
}