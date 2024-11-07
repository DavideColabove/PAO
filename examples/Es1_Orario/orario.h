#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>
using std::ostream;

class orario {
    private:
        class orario_rappr;
        orario_rappr* punt;
    public:
        orario(int =0,int =0,int =0); // costruttore ore-minuti-secondi con argomenti di default
        int Ore() const;  // selettore delle ore
        int Minuti() const; // selettore dei minuti
        int Secondi() const; // selettore dei secondi
        orario UnOraPiuTardi() const;
        void AvanzaUnOra();
        void StampaSecondi() const;
        static orario OraDiPranzo(); // static non ha bisogno dell'oggetto di invocazione
        static const int Sec_di_una_Ora = 3600;
        static const int Sec_di_un_Giorno = 86400;
        bool operator==(orario) const;
        orario operator<(orario) const;
        orario operator>(orario) const;
}; 

ostream& operator<<(ostream&, const orario&);

#endif