#include <iostream>

class Sum {
    long long a1, a2;
public:
    Sum(long long a, long long b) {
        a1 = a;
        a2 = b;
    }

    Sum(Sum a, long long b) {
        a1 = a.get();
        a2 = b;
    }

    long long get() const;
};

long long Sum::get() const {
    return a1 + a2;
}

// int main() {
//     using std::cout;
//     cout << Sum(Sum(3, 5), 5).get();
// }