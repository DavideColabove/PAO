#include "pol.h"
#include <math.h>

double punto::lung(const punto& p1, const punto& p2){
    return sqrt(((p2.x-p1.x)^2)-((p2.y-p1.y)^2));
}

poligono::poligono(unsigned int n, const punto v[]){}

poligono::~poligono(){}

poligono::poligono(const poligono& p){}

poligono& poligono::operator=(const poligono& p){}

double poligono::perimetro() const{
    int i;
    double p = 0.0;
    for (i=0; i<nvertici; i++){
        p += punto::lung(pp[i], pp[(i+1)%nvertici]);
    }
    return p;
}