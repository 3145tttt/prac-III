#include <iostream>
#include <string>
#include <vector>

int main(){
    std::string s;
    std::getline(std::cin, s);
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
    
    std::vector <std::string_view> arr(s.size());
    std::string_view t = s;
    arr[0] = t;
    for(int i = 1; i < ssize_t(s.size()); ++i){
        t.remove_prefix(1);
        arr[i] = t;
    }
    std::sort(arr.begin(), arr.end());
    for(int i = 0; i < ssize_t(arr.size()); ++i){
        std::cout << s.size() - arr[i].length() << std::endl;
    }
}