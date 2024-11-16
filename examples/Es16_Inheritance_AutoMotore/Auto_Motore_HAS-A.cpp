#include<iostream>
using std::cout, std::endl;

class Motore{
    private:
        int numCilindri;
    public:
        Motore(int nc): numCilindri(nc){}
        int getCilindri() const{
            return numCilindri;
        }
        void accendi() const{
            cout << "Motore a" << getCilindri() << " cilindri acceso" << endl; 
        }
};

class Auto{
    private: 
        Motore mot;
    public:
        Auto(int nc = 4): mot(nc){}
        void accendi() const{
            mot.accendi();
            cout << "Auto con motore a " << mot.getCilindri() << " cilindri accesa" << endl;
        }
};