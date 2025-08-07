#ifndef TRI_H
#define TRI_H
#include "pol.h"

class triangolo: public poligono{
    public:
        triangolo(const punto v[]);     // 3 vertici
        double area() const;            // metodo proprio di triangolo
                                        // perimetro() erediatato da poligono
};
#endif