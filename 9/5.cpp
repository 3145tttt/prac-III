#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

int main() {

    int year, month, days;
    {
        char t;
        std::cin >> year >> t >> month >> t >> days;
    }
    boost::gregorian::date prev(year, month, days);
    long long delta = 0;
    for(char t; std::cin >> year >> t >> month >> t >> days;){
        boost::gregorian::date cur(year, month, days);
        delta += std::abs((cur - prev).days());
        prev = cur;
    }
    std::cout << delta << std::endl;
    return 0;
};