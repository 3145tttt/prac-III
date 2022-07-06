#include <iostream>


/*
Язык имеет вид a^n 0^m b^n 1^m, m > 0, n > 0

S -> ABCD
AB-> AABB
CD-> CCDD
BC-> CB
A -> a
B -> b
C -> 0
D -> 1

тип 1
*/
int is_correct(char c){

    enum STATE { state_A, state_B, state_0, state_1};
    STATE cur_state = state_A;

    unsigned long long count_a = 1, count_0 = 0;
    unsigned long long count_b = 0, count_1 = 0;
    int flag = 1;

    if(c != 'a'){
        flag = 0;
    }
    while(std::cin >> c && !isspace(c)){
        if(cur_state == state_1 && count_0 < count_1){
            flag = 0;
        }

        if(cur_state == state_B && count_a < count_b){
            flag = 0;
        }

        if(!flag){
            continue;
        }

        if(cur_state == state_A){
            if(c == 'a'){
                ++count_a;
            } else if(c == '0'){
                ++count_0;
                cur_state = state_0;
            } else {
                flag = 0;
            }
        } else if(cur_state == state_0){
            if(c == '0'){
                ++count_0;
            } else if(c == 'b'){
                ++count_b;
                cur_state = state_B;
            } else {
                flag = 0;
            }
        } else if(cur_state == state_B){
            if(c == 'b'){
                ++count_b;
            } else if(c == '1'){
                ++count_1;
                cur_state = state_1;
            } else {
                flag = 0;
            }
        } else if(cur_state == state_1) {
            if(c == '1'){
                ++count_1;
            } else {
                flag = 0;
            }
        }
    }
    flag = flag && count_a == count_b && count_1 == count_0 && count_a > 0 && count_0 > 0;
    return flag;
}


int main(){
    char c;
    std::cin >> std::noskipws;
    while(std::cin >> c){
        if(!isspace(c)){
            std::cout << is_correct(c) << std::endl;
        }
    }

}