/*
Definire un template di funzione Fun(T1*, T2&) che ritorna un booleano con il segeuente comportamento.
Consideriamo una istanziazione implicita Fun(p,r) dove supponiamo che i parametri di tipo T1 e T2 siano
istanziati a tipi polimorfi (cioe che contengono almeno un metodo virtuale).
Allora Fun(p,r) ritorna true se e soltanto se valgono le seguenti condizioni:

1. I parametri di tipo T1 e T2 sono istanziati allo stesso tipo;

2. Siano D1* il tipo dinamico di p e D2& il tipo dinamico di r. Allora (i) D1 e D2 sono lo stesso tipo e
(ii) questo tipo é un sottotipo proprio della classe ios della gerarchia di classi di I/O (si ricordi che
ios é la classe base astratta della gerarchia);

*/

#include<iostream>
#include<fstream>
#include<typeinfo>
using namespace std;

class C {
    public:
        virtual *C();
};

template<class T1, class T2>
bool Fun(T1* p, T2& r){
    return typeid(p)==typeid(&r) && typeid(*p)==typeid(r) && dynamic_cast<ios*>(p) != nullptr; 
//  equivalente typeid(T1)==typeid(T2)
}

int main(){
    ifstream f("pippo");
    fstream g("pluto"), h("zagor");
    iostream *p = &h;
    C c1, c2;
    cout <<  Fun(&cout, cin) << endl;   // stampa 0
    cout <<  Fun(&cout, cerr) << endl;   // stampa 1
    cout <<  Fun(p,h) << endl;   // stampa 0
    cout <<  Fun(&f, *p) << endl;   // stampa 0
    cout <<  Fun(&g, h) << endl;   // stampa 1
    cout <<  Fun(&c1, c2) << endl;   // stampa 0
}