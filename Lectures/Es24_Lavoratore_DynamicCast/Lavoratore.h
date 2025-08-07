#ifndef LAVORATORE_H
#define LAVORATORE_H
#include<iostream>
#include<string>

using namespace std;

class Lavoratore {  // classe base astratta
    private:
        string nome;
    public:
        virtual ~Lavoratore(){}
        Lavoratore (string  n): nome(n){};
        string getNome() const;
        virtual double stipendio() const =0;    // virtuale pura
        virtual void printInfo() const;         // virtuale 
};

class Dirigente: public Lavoratore{
    private:
        double fissoMensile;    // stipendio fisso
    public:
        Dirigente(string n, double d = 0): Lavoratore(n), fissoMensile(d){}
        virtual double stipendio() const;   // implementazione
        virtual void printInfo() const;     // overriding
};

class Rappresentante: public Lavoratore{
    private:
        double baseMensile;
        double commissione;
        int tot;
    public:
        Rappresentante(string n, double d=0, double e=0, int x=0): Lavoratore(n), baseMensile(d), commissione(e), tot(x){}
        virtual double stipendio() const;   // implementazione
        virtual void printInfo() const;     // overriding
};

class LavoratoreOre: public Lavoratore{
    private:
        double pagaOraria;
        double oreLavorate;     // ore lavorate nel mese
    public:
        LavoratoreOre(string n, double d=0, double e=0): Lavoratore(n), pagaOraria(d), oreLavorate(e){}
        virtual double stipendio() const;
        virtual void printInfo() const;
};

//funzione esterna
void stampaStipendio(const Lavoratore& x){
    x.printInfo();  // chiamata polimorfa
    std::cout << " in questo mese ha guadagnato " << x.stipendio() << " Euro. \n" << std::endl;     // chiamata (super)polimorfa
}
#endif