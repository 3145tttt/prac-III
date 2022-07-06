#include <iostream>

class C
{
public:
    static void f(){};
    static const char c;
};

// const char C::c = '+';
// int main()
// {
//     C ob;
//     C::f();
//     return 0;
// }