#include <iostream>
#include <map>
#include <string>


int main(){
    std::map<std::string, std::pair<unsigned, unsigned>> mark_count_map;
    
    std::string surname;
    unsigned mark;

    while(std::cin >> surname >> mark){
        mark_count_map[surname].first += mark;
        ++mark_count_map[surname].second;
    }

    for (const auto& [key, value] : mark_count_map) {
        std::cout << key << " " << 1.0*value.first/value.second << std::endl;
    }
}