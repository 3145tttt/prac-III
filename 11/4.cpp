#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>

const std::map<char, int> hash = {{'*', 1}, {'/', 1},
    {'+', 2}, {'-', 2}, {'&', 3}, {'^', 4}, {'|', 5}};

std::string S(std::string::const_iterator &s_begin, std::string::const_iterator s_end, int min, int max, int prev){
    std::string answer = "";
    int cur_min = 6;
    int cur_max = 0;
    int last = 6;

    for(; s_begin < s_end; ++s_begin){
        //std::cout << *s_begin << std::endl;
        if(*s_begin == '('){
            ++s_begin;
            answer += S(s_begin, s_end, cur_min, cur_max, last);
        } else if(*s_begin == ')'){
            // std::cout << cur_min << " " << cur_max << " " << prev << " " << last << std::endl;
            if(s_begin + 1 != s_end){
                const char c = *(s_begin + 1);
                if(hash.find(c) != hash.end()){
                    if(hash.at(c) < cur_max && cur_max != 0){
                        // std::cout << "og\n";
                        return '(' + answer + ')';
                    }
                }
            }
            // std::cout << cur_min << " " << cur_max << " " << min << " " << max << " " << prev << std::endl;
            if(((cur_max >= min && prev <= cur_max) ) && cur_min != 6 && min != 6){
                // std::cout << "oh\n";
                return '(' + answer + ')';
            }
            return answer;
        } else {
            answer += *s_begin;
            if(hash.find(*s_begin) != hash.end()){
                last = hash.at(*s_begin);
                
                if(last > cur_max){
                    cur_max = last;
                }
                if(last < cur_min){
                    cur_min = last;
                }
            }
        }
    }
    return answer;
}

int main(){
    std::string str;
    std::cin >> str;
    auto b = str.cbegin();
    std::cout << S(b, str.cend(), 6, 0, 6) << std::endl;
}