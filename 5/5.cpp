#include <iostream>
#include <list>

int main(){
    std::list<int> l;
    int tmp;
    while((std::cin >> tmp) && tmp != 0){
        l.push_back(tmp);
    }
    while(std::cin >> tmp){
        if(tmp < 0){
            tmp = -tmp;
            if(tmp <= ssize_t(l.size())){
                auto it_begin = l.begin();
                std::advance(it_begin, tmp - 1);
                l.erase(it_begin);
            }
        } else {
            int el;
            std::cin >> el;
            auto it_begin = l.begin();
            if(tmp > ssize_t(l.size())){
                l.push_back(el);
            } else {
                std::advance(it_begin, tmp - 1);
                l.insert(it_begin, el);
            }
        }
    }

    for(auto x: l){
        std::cout << x << std::endl;
    }
    //вызовется деструктор l, так что не думаю,
    // что нужно явно освобождать список
}