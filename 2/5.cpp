#include <iostream>
#include <string>

class BinaryNumber
{
private:
    std::string s;
public:
    BinaryNumber(const std::string &s): s(s) {}
    operator std::string () const {
        return s;
    }

    const BinaryNumber &operator++() {
        const long long N = s.size();
        for(long long i = N - 1; i > -1; --i){
            if(s[i] == '0') {
                s[i] = '1';
                break;
            }
            s[i] = '0';
        }
        if(s[0] == '0'){
            s.insert(0, 1, '1');
        }

        return *this;
    }
};