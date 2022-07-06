#include <array>
#include <complex>
#include <iostream>
#include <vector>
#include <limits>

namespace Equations {

template <typename T>
std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> arr){
    const T EPS = std::numeric_limits<T>::epsilon();
    if(std::norm<T>(arr[2]) <= EPS) { //a == 0
        if(std::norm<T>(arr[1]) <= EPS) { //b == 0
            const bool INF_FLAG = std::norm<T>(arr[0]) <= EPS; // c == 0
            return std::make_pair<bool, std::vector<std::complex<T>>>(!INF_FLAG, {});
        }
        return std::make_pair<bool, std::vector<std::complex<T>>>(true, {-arr[0]/arr[1]}); // root1 = -c/b;
    }
    const T k1 = 4;
    const T k2 = 2;
    const std::complex<T> D = std::sqrt(arr[1]*arr[1] - k1*arr[0]*arr[2]); //(b^2 - 4ac)^1/2
    const std::complex<T> x1 = (-arr[1] + D)/(k2*arr[2]), x2 = (-arr[1] - D)/(k2*arr[2]); 
    return std::make_pair<bool, std::vector<std::complex<T>>>(true, {x1, x2});
}

}

// int main()
// {
//     std::array<std::complex<double>, 3> v1{
//         std::complex<double>(1.0, 2.0),
//         std::complex<double>(2.0, 0),
//         std::complex<double>(3, 1.3)
//     };

//     auto res = Equations::quadratic(v1);
//     std::cout << res.first;
// }
