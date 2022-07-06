#include <iostream>
#include <string>
#include <stdexcept>

class String_worker {
public:
    std::string s;
    ~String_worker(){
        std::cout << s << std::endl;
    }
};

void process(){
    std::string s;
    if(std::cin >> s){
        String_worker tmp;
        tmp.s = s;
        process();
    } else {
        throw std::runtime_error("End");
    }
    std::cout << "noooo" << std::endl; //no return
}

int main(){
    try {
        process();
    } catch(...){

    }
}