#include <iostream>

class A {
    int a;
public:
    bool printed = true;
    A(){
        std::cin >> a;
    }
    
    A(A &object_a){
        std::cin >> a;
        a += object_a.a;
        object_a.printed = false; 
    }

    ~A(){
        if(printed){
            std::cout << a;
        }
    }
};