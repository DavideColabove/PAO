#ifndef RET_H
#define RET_H
#include "pol.h"

class rettangolo: public poligono{
    public:
        rettangolo(const punto v[]); // nvertici == 4
        double perimetro() const;   // ridefinizione
        double area() const;        // metodo proprio di rettangolo
};
#endif