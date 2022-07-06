#include <iostream>
#include <string>

bool check(const std::string &s, int &pos){
    bool f = true;
    for(size_t i = 0; i < s.size(); ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(!f){
                return 0;
            }
            pos = i;
            f = false;
        }
    }
    return 1;
}

int main(){

    std::string l, r;
    bool have_S_to_eps = 0, have_S_r = 0;
    bool left_reg = 1, right_reg = 1, automate = 1, have_r_one_N = 1;
    unsigned long long count_N_to_eps = 0, count_only_N_r = 0, count_S_to_N = 0;
    
    while(std::cin >> l >> r){
        if(r == "_"){
            if(l == "S"){
                have_S_to_eps = 1;
            } else {
                ++count_N_to_eps;
            }
            continue;
        }

        if(r.find('S') != std::string::npos){
            have_S_r = 1;
        }

        int pos = -1;
        have_r_one_N = have_r_one_N && check(r, pos);
        if(have_r_one_N){
            left_reg = left_reg && (pos == 0 || pos == -1);
            right_reg = right_reg && (pos == (int)(r.size() - 1) || pos == -1);
            automate = automate && 
                        ((r.size() == 1 && pos == -1) || (r.size() <= 2 && pos != -1));
            count_only_N_r += (r.size() == 1 && pos != -1);
            count_S_to_N += (l == "S" && r.size() == 1 && pos != -1);

        }
    }
    if(have_r_one_N && left_reg){
        if(automate && !count_N_to_eps && (count_only_N_r == 0 || (count_S_to_N == 1 && count_only_N_r == 1)) && 
            ((have_S_to_eps && !have_S_r) || !have_S_to_eps)) {
            std::cout << 311;
        } else {
            std::cout << 31;
        }
    } else if(have_r_one_N && right_reg){
        if(automate && !count_N_to_eps && (count_only_N_r == 0 || (count_S_to_N == 1 && count_only_N_r == 1)) && 
            ((have_S_to_eps && !have_S_r) || !have_S_to_eps)) {
            std::cout << 321;
        } else {
            std::cout << 32;
        }
    } else if((have_S_to_eps && have_S_r) || count_N_to_eps > 0){
        std::cout << 2;
    } else {
        std::cout << 21;
    }
    std::cout << std::endl;

    return 0;
}