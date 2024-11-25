#include "qua.h"

quadrato::quadrato(const punto v[]): rettangolo(v){}

// specializzazione della funzionalitá del calcolo del perimetro 
double quadrato::perimetro() const{
    double lato = punto::lung(pp[1],pp[0]);
    return (lato*4);
}

// specializzazione della funzionalitá del calcolo del perimetro 
double quadrato::area() const{
    double lato = punto::lung(pp[1],pp[0]);
    return (lato*lato);
}