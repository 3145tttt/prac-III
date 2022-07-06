#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

struct MeanFunctor
{   
    void operator()(double x){
        sum += x;
        ++n;
    }

    double mean(){
        return sum/n;
    }
private:
    double sum = 0;
    size_t n = 0;

};


int main(){
    std::vector<double> arr;
    double tmp;
    while (std::cin >> tmp) {
        arr.push_back(tmp);
    }
    const double PERCENT = 0.1;
    const size_t OFFSET_1 = arr.size()*PERCENT;
    const size_t OFFSET_2 = (arr.size() - 2*OFFSET_1)*PERCENT;

    std::sort(arr.begin() + OFFSET_1, arr.end() - OFFSET_1);

    MeanFunctor res = std::for_each(arr.begin() + OFFSET_1 + OFFSET_2, arr.end() - OFFSET_1 - OFFSET_2,
        MeanFunctor());

    std::cout << std::setprecision(10) << res.mean() << std::endl;
    
}