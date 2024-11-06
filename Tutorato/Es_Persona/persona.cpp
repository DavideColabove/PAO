#include <iostream>
#include <string>
#include "persona.h"

using std::ostream;
using std::endl;
using std::cout;
using std::string;

Persona::Persona(string& n , int dataN, int dataM) : nome(n), data_nascita(dataN), data_morte(dataM) {}

const string &Persona::getNome() const {
    return nome;
}

int Persona::getDataNascita () const {
    return data_nascita;
}

int Persona::getDataMorte () const {
    return data_morte;
}

ostream& operator<<(ostream& os, const Persona& p) {
    os << "Nome: " << p.getNome() << endl;
    os << "Data di nascita: " << p.getDataNascita() << endl;
    os << "Data di morte: " << p.getDataMorte() << endl;
    return os;
}

int main(){
    Persona p1("Luca", "2000", "2079");
    cout << p1;
}