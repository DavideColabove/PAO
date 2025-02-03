#include<iostream>
#ifndef RAZ_H
#define RAZ_H

class Raz{
    private:
        int num;
        int den;
    public:
        Raz(int n = 0, int d = 1): num(n), den(d==0? 1 : d){}
        Raz inverso() const;
        operator double() const;
        Raz operator+(const Raz&) const;
        Raz operator*(const Raz&) const;
        Raz& operator++();
        Raz operator++(int);
        friend std::ostream& operator<<(std::ostream&, const Raz&);
        static Raz uno();
};

std::ostream& operator<<(std::ostream& os, const Raz& r){
    return os << r.num << '/' << r.den;
}
#endif 
