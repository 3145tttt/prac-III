#include <iostream>

class S {
    int val = 0;
    int flag = false;
    int flag_end = false;
public:
    S(){
        if(std::cin >> val){
            flag = true;
        }
    }
    ~S(){
        if(flag_end){
            std::cout << val;
        }
    }

    S(const S& other){
        if(std::cin >> val){
            val += other.val;
            flag = true;
        } else {
            val = other.val;
            flag_end = true;
        }
    }

    operator bool(){
        return flag;
    }
};

// using namespace std;
// void func(S v)
// {
//     if(v){
//         func(move(v));
//     }
// }
// int main(){
//     func(S());
// }