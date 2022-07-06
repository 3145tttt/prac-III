#include <iostream>
#include <stdexcept>


class Result: public std::exception {
    int val;
public:
    Result(int t): val(t){}

    int get() const{
        return val;
    }
};

//akkerman func 2 args
void A(int m, int n){
    if(m == 0){
        throw Result(n + 1);
    }
    if(n == 0) {
        try {
            A(m - 1, 1);
        } catch(const Result& e) {
            throw Result(e.get());
        }
    }
    try {
        A(m, n - 1);
    } catch(const Result& e) {
        try {
            A(m - 1, e.get());
        } catch(const Result& e){
            throw Result(e.get());
        }
    }
    std::cout << "nooo" << std::endl;
}

int main(){
    int m, n;
    std::cin >> m >> n;
    try {
        A(m, n);
    } catch(const Result& e) {
        std::cout << e.get() << std::endl;
    }
}