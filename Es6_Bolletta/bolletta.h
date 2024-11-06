#ifndef BOLLETTA_H
#define BOLLETTA_H
#include "C:\Users\colag\Desktop\Es_PAO\Es4_Telefonata\telefonata.h"
#include <iostream>

using std::ostream;

class bolletta{
    public:
        class iteratore{
            friend class bolletta;
            private:
                bolletta::nodo* punt;   // nodo puntato dall'iteratore
            public:
                bool operator==(const iteratore&) const;
                bool operator!=(const iteratore&) const;
                iteratore& operator++();
                iteratore operator++(int);
                telefonata& operator*() const;
                telefonata* operator->() const;
        };  // end classe iteratore
        bolletta();
        ~bolletta();
        bolletta(const bolletta&);  //copia profonda
        bolletta& operator=(const bolletta&);   //assegnazione profonda
        bool Vuota() const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata Estrai_Una();
        friend ostream& operator<<(ostream&,const bolletta&);
        // metodi che usano iteratore
        iteratore begin() const;
        iteratore end() const;
        telefonata& operator[](const iteratore&) const;
    private:
        class nodo{
            public:
                nodo();
                ~nodo();
                nodo(const telefonata&, nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first; //puntatore al primo nodo della lista
        static nodo* copia(nodo*);
        static void distruggi(nodo*);
};

orario Somma_Durate(bolletta b);

bolletta Chiamate_A(int num, bolletta& b);

ostream& operator<<(ostream&,const bolletta&);

#endif 