#include <iostream>
#include <math.h>
#include "triv_r.h"

tri_rettangolo::tri_rettangolo(const punto v[]): triangolo(v) { }

double tri_rettangolo::perimetro() const{
    double a = punto::lung(pp[1], pp[0]), 
        b = punto::lung(pp[0], pp[2]);
    return (a + b +sqrt(a*a + b*b));
}

double tri_rettangolo::area() const{
    double a = punto::lung(pp[1], pp[0]),
        b = punto::lung(pp[2],pp[0]);
    return (a*b / 2);
}

