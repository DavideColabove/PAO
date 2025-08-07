#ifndef TRIV_H
#define TRIV_H
#include "polv.h"

class triangolo: public poligono{
    public:
        triangolo(const punto v[]);
        // eredita perimetro()
        // contratto: ritorno l'area del triangolo di invocazione
        virtual double area() const;    // nuovo metodo virtuale
};
#endif