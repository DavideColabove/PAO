#include "pol.h"
#include <math.h>

double punto::lung(const punto& p1, const punto& p2){
    return sqrt(((p2.x-p1.x)^2)-((p2.y-p1.y)^2));
}

poligono::poligono(unsigned int n, const punto v[]){
    nvertici = n;
    pp = new punto[n];
    for (int i = 0; i < n; i++) {
        pp[i] = v[i];
    }
}

poligono::~poligono(){
    delete[] pp;
}

poligono::poligono(const poligono& p){
    nvertici = p.nvertici;
    pp = new punto[nvertici];
    for (int i = 0; i < nvertici; i++) {
        pp[i] = p.pp[i];
    }
}

poligono& poligono::operator=(const poligono& p){
    if (this != &p) {
        delete[] pp;
        nvertici = p.nvertici;
        pp = new punto[nvertici];
        for (int i = 0; i < nvertici; i++) {
            pp[i] = p.pp[i];
        }
    }
    return *this;
}

double poligono::perimetro() const{
    int i;
    double p = 0.0;
    for (i=0; i<nvertici; i++){
        p += punto::lung(pp[i], pp[(i+1)%nvertici]);
    }
    return p;
}