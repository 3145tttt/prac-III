#include <iostream>

/*
S -> aSd | X
X -> bXc | Y
Y -> cd
*/

void Y(){
    std::cout << "bc";
}

void X(int k2){
    if(k2 == 1){
        Y();
        return;
    }
    std::cout << 'b';
    X(k2 - 1);
    std::cout << 'c';
}

void S(int k1, int k2){
    if(k1 == 0){
        X(k2);
        return;
    }
    std::cout << 'a';
    S(k1 - 1, k2);
    std::cout << 'd';
}

void gen(int i, int k){
    if(i == 0){
        return;
    }
    S(i, k - i);
    std::cout << std::endl;
    gen(i - 1, k);
}

int main(){
    int k;
    std::cin >> k;
    if(!(k & 1)){
        gen(k/2 - 1, k/2);
    }
    return 0;
}