#include <iostream>
#include <cmath>
#include <iomanip> 

int main(){
    using std::cout;
    using std::cin;

    double S = 0, S_square = 0, x;
    int n = 0;
    while(cin >> x) {
        S += x;
        S_square += x*x;
        ++n;
    }
    S /= n;
    S_square /= n;

    cout << std::setprecision(10) << S << std::endl;
    cout << std::setprecision(10) << sqrt(S_square - S*S) << std::endl;

}