#include "tri.h"
#include <mat.h>

triangolo::triangolo(const punto v[]): poligono(3, v){}

double triangolo::area() const{
    double perimetro = perimetro()/2;
    double a = punto::lung(pp[1], pp[0]);
    double b = punto::lung(pp[2], pp[1]);
    double c = punto::lung(pp[2], pp[0]);
    return sqrt(perimetro*(perimetro-a)*(perimetro-b)*(perimetro-c));
}