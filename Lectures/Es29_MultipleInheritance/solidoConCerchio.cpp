#include <cmath>
#include <iostream>

using namespace std;

// gli oggetti sono solidi che hannoun cerchio come faccia

class solidoConCerchio{ // classe base astratta virtuale
    protected:
        double raggio;  // del cerchio
        double circonferenza() const{ return (2*M_PI*raggio);}
        double area_cerchio() const{ return (2*raggio*raggio);}
    public:
        // no costruttore di default
        solidoConCerchio(double r): raggio(r){}
        // virtuale pura: area del solido cheha un cerchio come faccia
        virtual double area() const = 0;
        // virtuale pura: volumedel solido che ha un cerchio come faccia
        virtual double volume() const = 0;
};

class cilindro: virtual public solidoConCerchio{
    protected:
        double altezza; // altezza del cilindro
        double area_laterale() const{
            return (circonferenza()*altezza);
        }
    public:
        cilindro(double r, double h): solidoConCerchio(r), altezza(h){}
        double area() const override{
            return (2*area_cerchio() + area_laterale());
        }
        double volume() const override{
            return (area_cerchio()*altezza);
        }
};

class cono: virtual public solidoConCerchio{
    protected:
        double altezza;
        double area_laterale() const{
            double apotema = sqrt(raggio*raggio + altezza*altezza);
            return (2*circonferenza()+apotema);
        }
    public:
        cono(double r, double h): solidoConCerchio(r), altezza(h){}
        double area() const override{
            return (area_cerchio() + area_laterale());
        }
        double volume() const override{
            return (area_cerchio()*altezza/3);
        }
};

class cilicono: public cilindro, public cono{
    // derivazione multipla: un solo sottooggeto solidoConCerchio
    public:
        cilicono(double r, double h1, double h2): solidoConCerchio(r), cilindro(r,h1), cono(r,h2){}
        // NOTA BENE: senza l'invocazione esplicita per solidoConCerchio(r) non compilerebbe perche non esiste
        // il costruttore di default per solidoConCerchio() 
        double area() const override{
            return (cilindro::area_laterale() + cono::area_laterale() + area_cerchio());
        }
        // NOTA BENE: eredito 2 metodi area_laterale() e volume() necessario l'uso dell'operatore di scoping
        double volume() const override{
            return (cilindro::volume() + cono::volume());
        }
};

int main(){
   solidoConCerchio* p;
   cilindro cil(1,2);
   cono co(1,2);
   cilicono clc(1, 2, 2);
   p = &cil;
   cout << "Area cilindro: " << p->area() << endl; 
   cout << "Volume cilindro: " << p->volume() << endl; 
   p = &co;
   cout << "Area cono: " << p->area() << endl; 
   cout << "Volume cono: " << p->volume() << endl;
   p = &clc;
   cout << "Area cilicono: " << p->area() << endl; 
   cout << "Volume cilicono: " << p->area() << endl; 
}