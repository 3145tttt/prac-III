
class C
{

private:
public:
    C(C a, C b){};
    C(const C* a){};
    C(double a){};
    C(){};

    C operator+(int b){ return 0.0; };
    C operator++(){ return 0.0;};
    C operator*(C b){return 0.0;};
    C operator[](int i){return 0.0;}; 
    C operator~() const{ return 0.0;};

    operator int() const {return 0; };
};