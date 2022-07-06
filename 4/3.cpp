#include <iostream>

int main(){
    using std::cin;
    using std::cout;

    long long n, m;
    cin >> m >> n;

    long long r1, c1, r2, c2;
    while(cin >> r1 >> c1 >> r2 >> c2) {

        if(r1 > r2) {
            long long r = r1;
            r1 = r2;
            r2 = r;
        }

        if(c1 > c2) {
            long long c = c1;
            c1 = c2;
            c2 = c;
        }

        const long long d1 = r2 - r1 + c2 - c1;
        const long long d2 = m + r1 - r2 + c2 - c1;
        const long long d3 = m + r1 - r2 + n + c1 - c2;
        const long long d4 = r2 - r1 + n + c1 - c2;
        // cout << r1 << " " << c1 << " " << r2 << " " << c2 << std::endl;
        // cout << d1 << " " << d2 << " " << d3 << " " << d4 << std::endl;
        cout << std::min(std::min(d1, d2), std::min(d3, d4)) << std::endl;

    }
    return 0;
}