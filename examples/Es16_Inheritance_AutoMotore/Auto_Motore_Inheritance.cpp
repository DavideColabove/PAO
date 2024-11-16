#include<iostream>
using std::cout, std::endl;

class Motore {
    private: 
        int numCilindri;
    public:
        Motore(int nc): numCilindri(nc){}
        int getCilindri() const{
            return numCilindri;
        }
        void accendi() const{
            cout << "Motore a " << getCilindri() << " cilindri acceso" << endl;
        }
};

class Auto : private Motore{    // Auto has-a Motore come sottooggetto
    public:
        Auto(int nc = 4): Motore(nc){}
        void accendi() const{
            Motore::accendi();      // se non utilizzo Motore:: diventa una chiama ricorsiva
            cout << "Auto con motore a " << getCilindri() << " cilindri accesa" << endl;
        }
};