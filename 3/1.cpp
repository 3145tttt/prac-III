#include <string>
#include <iostream>
#include <cmath>

namespace numbers {
    class complex {
        double _a, _b;
    public:
        complex(double a = 0, double b = 0): _a(a), _b(b){ }

        explicit complex(std::string str) {
            const size_t POS = str.find(',');
            _a = std::stod(str.substr(1, POS));
            _b = std::stod(str.substr(POS + 1));
        }

        explicit complex(const char *str_char) {
            std::string str = str_char;
            const size_t POS = str.find(',');
            _a = std::stod(str.substr(1, POS));
            _b = std::stod(str.substr(POS + 1));
        }

        double re() const {
            return _a;
        }

        double im() const {
            return _b;
        }
        double abs2() const {
            return _a*_a + _b*_b;
        }

        double abs() const {
            return sqrt(abs2());
        }

        std::string to_string() const {
            enum { LEN = 256 };
            char buf[LEN];
            std::snprintf(buf, LEN, "(%.10g,%.10g)", _a, _b);
            return buf;
        }

        void to_string(char *buf, size_t size) const {
            std::snprintf(buf, size, "(%.10g,%.10g)", _a, _b);
        }

        complex& operator+=(const complex& right){
            _a += right.re();
            _b += right.im();
            return *this;
        }

        complex& operator-=(const complex& right){
            _a -= right.re();
            _b -= right.im();
            return *this;
        }

        complex& operator*=(const complex& right){
            const double a = _a*right.re() - _b*right.im();
            _b = _b*right.re() + _a*right.im();
            _a = a;
            return *this;
        }

        complex& operator/=(const complex& right){
            const double c = right.re(), d = right.im();
            double _div = right.abs2();
            const double a = _a*c + _b*d;
            const double b = _b*c - _a*d;
            _a = a / _div;
            _b = b / _div;
            return *this;
        }

        complex operator~() const {
            complex tmp(_a, -_b);
            return tmp;
        }

        complex operator-() const {
            complex tmp(-_a, -_b);
            return tmp;
        }

    };

    complex operator+(const complex& lhs, const complex& right) {
            complex tmp = lhs;
            tmp += right;
            return tmp;
        }

        complex operator-(const complex& lhs, const complex& right) {
            complex tmp = lhs;
            tmp -= right;
            return tmp;
        }

        complex operator*(const complex& lhs, const complex& right) {
            complex tmp = lhs;
            tmp *= right;
            return tmp;
        }

        complex operator/(const complex& lhs, const complex& right) {
            complex tmp = lhs;
            tmp /= right;
            return tmp;
        }
}