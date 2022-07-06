#include <iostream>
#include <iomanip>

void encodeOut(char c, int n){
    std::cout << "#" << c << std::hex << n << "#";
}

int main(){

    using std::cout;
    using std::cin;
    enum { L = 4 };

    char c;
    char prevC = 'a';
    int prevL = -1;
    cin >> std::noskipws;
    while(cin.get(c) && !std::cin.eof()){
        if(prevL == -1){
            prevC = c;
            prevL = 1;
        } else {
            if(prevC == c){
                ++prevL;
            } else if(prevL > L || prevC == '#'){
                encodeOut(prevC, prevL);
                prevC = c;
                prevL = 1;
            } else {
                for(int i = 0; i < prevL; ++i){
                    std::cout << prevC;
                }
                prevC = c;
                prevL = 1;
            }
        }
    }

    if(prevL > L || prevC == '#'){
        encodeOut(prevC, prevL);
    } else {
        for(int i = 0; i < prevL; ++i){
            cout << prevC;
        }
    }

    return 0;
}
