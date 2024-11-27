#include <iostream> 
#include <string>
#include "Lavoratore.h"

using namespace std;

string Lavoratore::getNome() const{
    return nome;
}

void Lavoratore::printInfo() const{
    std::cout << nome;
}

double Dirigente::stipendio() const{
    return fissoMensile;
}

void Dirigente::printInfo() const{  // overriding
    std::cout << "Dirigente ";
    Lavoratore::printInfo();    // invocazione statica
}

double Rappresentante::stipendio() const{   // implementazione
    return baseMensile + commissione*tot;
}

void Rappresentante::printInfo() const{     // overriding
    std::cout << "Rappresentante ";
    Lavoratore::printInfo();
}

double LavoratoreOre::stipendio() const{    // implementazione
    if( oreLavorate <= 160)     // nessuno straordinario
        return pagaOraria*oreLavorate;
    else    // le ore straordinarie vengono pagate il doppio
        return 160*pagaOraria + (oreLavorate - 160) * 2 * pagaOraria; 
}

void LavoratoreOre::printInfo() const{      // overriding
    std::cout << "Lavoratore a ore ";
    Lavoratore::printInfo();
}