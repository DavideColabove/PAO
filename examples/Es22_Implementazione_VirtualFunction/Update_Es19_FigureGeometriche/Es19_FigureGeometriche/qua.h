#ifndef QUA_H
#define QUA_H
#include "ret.h"

// Quadrato é un rettangolo specializzato

class quadrato: public rettangolo{
    public:
        quadrato(const punto v[]);  // invoca quello di rettangolo
        double perimetro() const;   // ridefinizione
        double area() const;        // ridefinizione
};
#endif