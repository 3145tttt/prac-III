#include <iostream>
#include <iomanip>


int main(){
    using std::cout;
    using std::cin;
    
    unsigned offset, arr[4];
    while(cin >> std::hex >> offset){
        for(int k = 0; k < 4; ++k){
            if(cin >> std::hex >> arr[0] >> arr[1] >> arr[2] >> arr[3]) {
                unsigned out_x = 0;
                for (int i = 0; i <= 3; ++i){
                    out_x += (arr[i] << (24 - 8*i));
                }
                cout << out_x << std::endl;
            }
            

        }
    }

    return 0;
}