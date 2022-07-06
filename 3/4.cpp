#include <vector>
#include <string>
#include <cmath>
#include "3.cpp"
// #include "cmc_complex.h"
// #include "cmc_complex_stack.h"
// #include "cmc_complex_eval.h"

int main(int argC, char *argV[]){
    const numbers::complex C(argV[1]);
    const double R = std::stod(argV[2]);
    const long long N = std::stoll(argV[3]);
    std::vector <std::string> args(argC - 4);
    for(int i = 4; i < argC; ++i){
        args[i - 4] = argV[i];
    }
    numbers::complex I;
    const numbers::complex IM(0, 1);
    for(long long i = 0; i < N; ++i){
        const double PHI = 2*M_PI*(i + 0.5)/N;
        numbers::complex z(R*cos(PHI), R*sin(PHI));
        I += numbers::eval(args, z + C)*IM*z;
    }
    
    std::cout << (I * 2*M_PI*R/N).to_string() << std::endl;
}