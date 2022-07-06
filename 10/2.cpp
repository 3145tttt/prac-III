#include <iostream>

int main(){

    enum STATE {
        ZEROS_0, ONES_0, ZEROS, ONES
    };
    char cur;
    std::cin >> std::noskipws;
    while(std::cin >> cur){
        if(isspace(cur)){
            while(std::cin >> cur){
                if(!isspace(cur)){
                    break;
                }
            }
        }
        int flag = 1;
        unsigned long long count_0 = 0, count_1 = 0;
        unsigned long long cur_cout_0 = 0, cur_count_1 = 0;
        STATE cur_state = ZEROS_0;
        if(cur == '0'){
            ++count_0;
        } else {
            flag = 0;
        }
        if(isspace(cur)){
            continue;
        }
        while(std::cin >> cur){
            if(isspace(cur)){
                if(cur_state == ZEROS || cur_state == ONES){
                    if(cur_count_1 != count_1 || cur_cout_0 != count_0){ 
                        flag = 0;
                    }
                }
                if(count_1 == 0 || count_0 == 0){
                    flag = 0;
                }
                break;
            }
            if(flag == 0){
                continue;
            }
            if(cur != '1' && cur != '0'){
                flag = 0;
            }

            if(cur_state == ZEROS_0) {
                if(cur == '0') {
                    ++count_0;
                } else if(cur == '1'){
                    ++count_1;
                    cur_state = ONES_0;
                }
            } else if (cur_state == ONES_0) {
                if(cur == '0') {
                    ++cur_cout_0;
                    cur_state = ZEROS;
                } else if(cur == '1'){
                    ++count_1;
                }
            } else if (cur_state == ZEROS) {
                if(cur == '0'){
                    ++cur_cout_0;
                } else if(cur == '1'){
                    ++cur_count_1;
                    cur_state = ONES;
                }
            } else if (cur_state == ONES) {
                if(cur == '0'){
                    //reset cycle
                    if(cur_count_1 != count_1 || cur_cout_0 != count_0){ 
                        flag = 0;
                    }
                    cur_count_1 = 0;
                    cur_cout_0 = 0;
                    ++cur_cout_0;
                    cur_state = ZEROS;
                } else if(cur == '1'){
                    ++cur_count_1;
                }
            }
        }
        if(count_1 == 0 || count_0 == 0){
            flag = 0;
        }
        if(cur_state == ZEROS || cur_state == ONES){
            if(cur_count_1 != count_1 || cur_cout_0 != count_0){ 
                flag = 0;
            }
        }
        std::cout << flag << std::endl;
    }
}