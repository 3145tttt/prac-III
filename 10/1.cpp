#include <iostream>
#include <string>

int main(){
    enum STATE {
        INIT, FIRST, SECOND
    };

    std::string str;
    while(std::cin >> str) {
        int flag = 1;
        STATE cur_state = INIT;
        if(str[0] == '3' || str[0] == '4'){
            cur_state = FIRST;
        } else {
            cur_state = SECOND;
        } 
        for(const auto& cur: str){
            if(cur != '3' && cur != '4' && cur != '1' && cur != '2'){
                flag = 0;
                break;
            }
            if(flag == 0){
                break;
            }

            if(cur_state == FIRST){
                if(cur == '1' || cur == '2'){
                    cur_state = SECOND;
                } else if(cur != '3' && cur != '4'){
                    flag = 0;
                }
            } else if(cur_state == SECOND) {
                if(cur != '1' && cur != '2'){
                    flag = 0;
                }
            }
        }
        if(cur_state != INIT){
            std::cout << flag << std::endl;
        }
    }
}