#include <iostream>
#include <set>
#include <stack>
#include <string>

int main(){
    std::stack<std::string> POLIS;
    const std::set<char> op = {'+', '-', '/', '*'};

    char c;
    while(std::cin >> c){
        if(op.find(c) != op.end()){
            std::string c1 = POLIS.top();
            POLIS.pop();
            std::string c2 = POLIS.top();
            POLIS.pop();
            POLIS.push("(" + c2  + c  +  c1 + ")");
        } else {
            std::string s(1, c);
            POLIS.push(s);
        }
    }
    

    std::cout << POLIS.top() << std::endl;
    return 0;
}