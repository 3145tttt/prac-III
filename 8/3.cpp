#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
// #include "2.cpp"

Figure* make_figure(char type, std::string s2){
    if(type == 'R'){
        return Rectangle::make(s2);
    }
    if(type == 'S'){
        return Square::make(s2);
    }
    if(type == 'C'){
        return Circle::make(s2);
    }
    return nullptr;
}

bool my_cmp(const Figure* a, const Figure* b){
    return a->get_square() < b->get_square();
}

int main(){
    std::vector<Figure*> arr;
    std::string type;
    while(std::cin >> type){
        std::string args;
        std::getline(std::cin, args);
        arr.push_back(make_figure(type[0], args));
    }

    std::stable_sort(arr.begin(), arr.end(), my_cmp);

    for(auto it = arr.begin(); it != arr.end(); ++it){
        std::cout << (*it)->to_string() << std::endl;
        delete *it;
    }
}
