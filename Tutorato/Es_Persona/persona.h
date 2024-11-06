#include <iostream>
#include <string>

using std::ostream;
using std::string;

class Persona{
    private:
        string nome;
        int data_nascita, data_morte;
    public:
        Persona(string& n, int dataN, int dataM);
        string getNome() const;
        int getDataNascita () const;
        int getDataMorte () const;
    
        friend ostream& operator<<(ostream& os, const Persona& p);
};