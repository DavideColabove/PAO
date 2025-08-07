#ifndef TELEFONATA_H
#define TELEFONATA_H
#include <iostream>
#include "C:\Users\colag\Desktop\Es_PAO\Es1_Orario\orario.h"

class telefonata{
    private:
        const int numero;
        orario inizio, fine;    //relazione has-a
    public:
        telefonata(const orario&, const orario&, int&);
        telefonata();
        orario Inizio() const;
        orario Fine() const;
        int Numero() const;
        bool operator==(const telefonata&) const;
};

std::ostream& operator<<(ostream& os, const telefonata& t); 

#endif