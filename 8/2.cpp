#include "1.cpp"
#include <iostream>
#include <string>
#include <cmath>

class Rectangle: public Figure {
public:
    double a, b;
    static Rectangle* make(std::string s) {
        Rectangle* tmp = new Rectangle;
        size_t ind = s.find(' ');
        tmp->a = std::stod(s.substr(0, ind));
        tmp->b = std::stod(s.substr(ind + 1));
        return tmp;
    };
    double get_square() const override {
        return a*b;
    }
};

class Square: public Figure {
public:
    double a;
    static Square* make(std::string s) {
        Square* tmp = new Square;
        tmp->a = std::stod(s);
        return tmp;
}
    double get_square() const override {
        return a*a;
    }
};

class Circle: public Figure {
public:
    double r;
    static Circle* make(std::string s) {
        Circle* tmp = new Circle;
        tmp->r = std::stod(s);
        return tmp;
    };
    double get_square() const override {
        return M_PI*r*r;
    }
};

// int main(){

// }