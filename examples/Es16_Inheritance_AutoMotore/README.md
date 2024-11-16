# Descrizione

Ereditarietá privata vs relazione di composizione has-a


## Similaritá

1. In entrambi i casi un oggetto Motore "contenuto" in ogni oggetto Auto

2. In entrambi i casi, per gli utenti esterni, Auto* non é convertibile a Motore*


## Differenze

1. La composizion é necessaria se servono piú motori in un auto (a meno di usi limite di ereditarietá multipla)

2. Ereditarietá privata puó indurre ereditarietá multipla (problematica) non necessaria

3. Ereditarietá privata permette ad Auto di convertire Auto* a Motore*: finché sono all'interno di una funzione della classe derivata con ereditarietá privata il puntatore alla derivata é anche un puntatore alla base, solo internamente alla classe != esternamente no perché non c'é relazione di subtyping

4. Ereditarietá privata permette l'accesso alla parte protetta della base


## Ereditare i metodi pubblici

```cpp
class Base{
    private:
        int x;
    public:
        void f(){
            x=2;
        }
};

class Derivata : public Base{
    private:
        int y;
    public: 
        void g(){
            y = 3;
        }
};

int main(){
    Base b; Derivata d;
    Base *p = &b; Derivata *q = &d;

    p->f();     // OK
    p = &d;     // Derivata* é ora di tipo dinamico di p
    p->f();     // OK : si applica ad oggetti della base
    p->g();     // ILLEGALE! nella classe B non c'é alcuna funzione g() disponibile
                // compilatore statico => puó guardare solo il tipo statico del puntatore
    q->g();     // OK
    q->f();     // OK, ereditato dalla base => posso invocare su un puntatore della derivata le funzioni che eredito dalla base
}
```

## Ereditarietá e amicizia

Le amicizie della classe base non si ereditano!  
Significa che un tentativo di scrivere uno statement che tenta di accedere alla parte privata della classe derivata viene bloccata dal compilatore

Ció vale per funzioni:

```cpp
#include<iostream>
using std::cout;
using std::endl;

class C{
    private:
        int i;
    public:
        C(): i(1){}
        friend void print(C);
};

class D : public C{
    private:
        double z;
    public:
        D(): z(3.14){}
};

void print(C x){
    cout << x.i << endl;
    D d;
    cout << d.z << endl; // ILLEGALE: "D::z is private within this context"
}

int main(){
    C c; D d;
    print(c);   // stampa: 1
    print(d);   // OK, stampa: 1
}
```

A maggior ragione vale anche per le classi

Per risolvere, dobbiamo fare una nuova dichiarazione di amicizia

```cpp
#include<iostream>
using std::cout;
using std::endl;

class C{
    private:
        int i;
    public:
        C(): i(1){}
        friend void print(C);
};
void print(C x){
    cout << x.i << endl;
}

class D : public C{
    private:
        double z;
    public:
        D(): z(3.14){}
        friend void print(D);
};
void print(D x){
    cout << x.z << endl;
}

int main(){
    C c; D d;
    print(c);   // stampa: 1
    print(d);   // stampa: 3.14
}
```