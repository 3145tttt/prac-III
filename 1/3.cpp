#include <iostream>

int main() {
    using std::cin;
    using std::cout;

    char cur;
    bool find_non_zero = false;
    bool start_num = false;
    while ((cur = getchar()) != EOF) {
        if (cur <= '9' && cur >= '0') {
            start_num = true;
            if(find_non_zero) {
                cout << cur;
            } else if (cur != '0') {
                find_non_zero = true;
                cout << cur;
            }
        } else {
            if(start_num && !find_non_zero){
                cout << "0";
            }
            start_num = false;
            find_non_zero = false;
            cout << cur;
        }
    }

    if(start_num && !find_non_zero){
        cout << "0";
    }
    return 0;
}