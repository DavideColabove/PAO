#ifndef TRIV_R
#define TRIV_R
#include "triv.h"

class tri_rettangolo: public triangolo{
    public: // triangolo rettangolo in pp[0]
        tri_rettangolo(const punto v[]);
        virtual double perimetro() const;   // overriding specializzato
        virtual double area() const;        // overriding specializzato
};
#endif