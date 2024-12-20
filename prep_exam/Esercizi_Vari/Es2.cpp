#include <iostream>
using std::cout;

class A {
private:
    int x;

public:
    // Costruttore con parametro di default
    A(int k = 5) : x(k) { cout << k << " A01 "; }

    // Costruttore di copia
    A(const A& a) : x(a.x) { cout << "Ac "; }

    // Metodo membro g
    A g() const { return *this; }
};

class B {
private:
    A ar[2];        // Array di 2 oggetti di tipo A
    static A a;     // Membro statico della classe A

public:
    // Costruttore di default
    B() {
        ar[1] = A(7);  // Assegna ad ar[1] un oggetto temporaneo A(7)
        cout << "B0 ";
    }

    // Costruttore di copia
    B(const B& b) { cout << "Bc "; }
};

// Inizializzazione del membro statico della classe B
A B::a = A(9);

A Fun(A* p, const A& a, B b) {
    *p = a;  // Assegna l'oggetto a all'oggetto puntato da p
    a.g();   // Chiama il metodo g su a
    return *p;  // Restituisce l'oggetto puntato da p
}

int main() {
    cout << "ZERO\n";
    A a1;       // Costruisce un oggetto A con valore di default
    cout << "UNO\n";

    A a2(3);    // Costruisce un oggetto A con valore 3
    cout << "DUE\n";

    A* p = &a1; // Puntatore a A che punta ad al
    cout << "TRE\n";

    B b;        // Costruisce un oggetto B
    cout << "QUATTRO\n";

    a1 = Fun(p, a2, b);  // Chiama la funzione Fun
    cout << "CINQUE\n";

    A a3 = Fun(&a1, *p, b);  // Chiama la funzione Fun
    cout << "SEI";
}
