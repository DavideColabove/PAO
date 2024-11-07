#include "telefonata.h"

telefonata::telefonata() : numero(0){}

telefonata::telefonata(const orario& i, const orario& f, const int& n) : inizio(i), fine(f), numero(n){}

orario telefonata::Inizio() const{
    return inizio;
}

orario telefonata::Fine() const{
    return fine;
}

int telefonata::Numero() const{
    return numero;
}

bool telefonata::operator==(const telefonata& t) const{
    return inizio == t.inizio && fine == t.fine && numero == t.numero;
}

std::ostream& operator<<(ostream& os, const telefonata& t){
    return os << "INIZIO" << t.inizio << " FINE " << t.fine << " NUMERO CHIAMATO " << t.numero;
}