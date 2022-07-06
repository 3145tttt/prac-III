#include <iostream>
#include <stdexcept>


class Result: public std::exception {
    unsigned long long val;
public:
    Result(unsigned long long t): val(t){}

    unsigned long long get() const{
        return val;
    }
};

//akkerman func 3 args
void f(unsigned long long a, unsigned long long b, unsigned long long k){
    if(k == 0){
        throw Result(a + b);
    }
    if(b == 1) {
        throw Result(a);
    }
    try {
        f(a, b - 1, k);
    } catch(const Result& e) {
        try {
            f(a, e.get(), k - 1);
        } catch(const Result& e) {
            throw Result(e.get());
        }
    }
    std::cout << "nooo" << std::endl;
}

int main(){
    unsigned long long a, b, k;
    while(std::cin >> a >> b >> k){
        try {
            f(a, b, k);
        } catch(const Result& e) {
            std::cout << e.get() << std::endl;
        }
    }
}