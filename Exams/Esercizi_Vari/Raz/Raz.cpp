#include<iostream>
#include "Raz.h"

Raz Raz::inverso() const{
    return Raz(den,num);
}

Raz::operator double() const{
    return (double)num/den;
}

Raz Raz::operator+(const Raz& r) const{
    return Raz(num*r.den+r.num*den, den*r.den);
}

Raz Raz::operator*(const Raz& r) const{
    return Raz(num*r.num,r.den*den);
}

Raz Raz::operator++(){  // prefisso
    num = num + den;
    return *this;
}

Raz Raz::operator++(int){   // postfisso
    Raz temp(num+den, den);
    num = num+den;
    return temp;
}

Raz Raz::uno(){
    return Raz(1,1);
}

int main(){
    Raz a(2,3), b(5,1), c(5), d(8,8), e(5,1);
    std::cout << a.inverso() << std::endl;
    std::cout << ++b << std::endl;
    std::cout << c++ << std::endl;
    std::cout << a+e << std::endl;
    std::cout << e*d << std::endl;
    std::cout << Raz::uno() << std::endl;
    std::cout << 2.2+c << std::endl;
}