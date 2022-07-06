#include <iostream>

class C {
private:

    int _a;
public:

    C(int a): _a(a) {};

    int get() const {
        return 2*_a;
    }

    operator int () const {
        return this->get(); 
    };

};

// int main(void)
// {
//     C c1(7), c2 = 5, c3(c1 + c2);
//     std::cout << c1.get() << ' ' << c2.get() << ' ' << c3.get() << std::endl;
//     return 0;
// }