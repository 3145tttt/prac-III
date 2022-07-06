#include <iostream>
#include <string>

bool have_N(const std::string &s){
    for(const char &ch : s){
        if(ch < 'a' || ch > 'z'){
            return true;
        }
    }
    return false;
}


int main(){

    std::string rule_l, rule_r;
    bool have_start = false, have_S_r = false, have_error_l = false;
    bool have_eps = false, have_eps_S = false;
    bool context_free = true;

    while(std::cin >> rule_l >> rule_r){
        //-1
        if(!have_N(rule_l)){
            have_error_l = true;
            break;
        }
        //10
        if(rule_l == "S") {
            have_start = true;
        }
        //2
        if(rule_l.size() > 1){
            context_free = false;
        }
        //23
        if(context_free){
            if(rule_r == "_"){ 
                have_eps = true;
                if(rule_l != "S"){
                    have_eps_S = true;
                }
            }
            if(rule_r.find('S') != std::string::npos){
                have_S_r = true;
            }
        }
    }

    if(have_error_l || !have_start){
        std::cout << -1 << std::endl;
    } else if(context_free){
        if(have_eps_S || (have_eps && have_S_r)){
            std::cout << 2 << std::endl;
        } else {
            std::cout << 23 << std::endl;
        }
    } else {
        std::cout << 10 << std::endl;
    }
    return 0;
}