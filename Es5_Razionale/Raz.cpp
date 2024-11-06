#include <iostream>
#include "Raz.h"


Raz::Raz(int n, int d) : num(n), den(d==0? 1 : d){};

Raz Raz::inverso() const {
    return Raz(num==0? 0 : den, num);
}

Raz::operator double() const{
    return static_cast<double>(num) / static_cast<double>(den);
}

Raz::operator+(const Raz& r) const{
    return Raz(num*r.den + r.num*den, den*r.den);
}

Raz::operator*(const Raz& r) const{
    return Raz(num*r.num, den*r.den);
    
}

bool Raz::operator==(const Raz& r) const{
    return num*r.den == den*r.num;
}

Raz& Raz::operator++(){    //forma prefissa
    num = num + den;
    return *this;
}

Raz Raz::operator++(int){   //forma postfissa
    Raz aux(*this);
    num = num + den;
    return aux;
}

Raz Raz::unTerzo(){
    return Raz(1,3);
}

std::ostream& operator<<(std::ostream& os, const Raz& r){
    return os << "Il razionale in virgola mobile e " 
        << r.operator double();
}


int main() {
    Raz x(2,3), y(2), z, u(1,8), v(3,2), w(8,4);

    std::cout << x+y+v*u << std::endl; 
    std::cout << u.inverso() << std::endl;
    std::cout << (y == w) << std::endl;
    std::cout << y++ << " " << ++w << std::endl;
    std::cout << (++y + Raz::unTerzo()) << std::endl;
    std::cout << 2 + Raz(1,2) << std::endl;
}