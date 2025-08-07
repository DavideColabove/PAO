#include <iostream>
using namespace std;

template <typename T>
class albero {
private:
    class nodo {
    public:
        T info;
        nodo* sx;
        nodo* cx;
        nodo* dx;


        nodo(const T& i, nodo* s = 0, nodo* c = 0, nodo* d = 0): info(i), sx(s),cx(c), dx(d)  {}
    };

    nodo * radice;
    nodo * copia(const nodo * n) const {
        if (n == nullptr) return nullptr;
        return(new nodo(n->info, copia(n->sx), copia(n->cx), copia(n->dx)));
    }
    void distruggi(nodo * n) {
        if (n) {
            distruggi(n->sx);
            distruggi(n->cx);
            distruggi(n->dx);
            delete n;
        }
    }

    bool sonoUguali(const nodo * n1, const nodo * n2) const {
        if (n1 == nullptr && n2 == nullptr) return true;
        if (n1 == nullptr || n2 == nullptr) return false;
        return (n1->info == n2->info && sonoUguali(n1->sx, n2->sx) && sonoUguali(n1->cx, n2->cx) && sonoUguali(n1->dx, n2->dx));
    }

    void stampa(const nodo *n) const {
    if (n) {
        stampa(n->sx);
        stampa(n->cx);
        stampa(n->dx);
        cout << n->info << " ";
    }
    }

public:
    albero(): radice(nullptr) {}
    albero(const T& i): radice(new nodo(i)){}
    albero(const albero & a): radice(copia(a.radice)){}
    ~albero() {distruggi(radice); }
    albero & operator=(const albero & a) {
        if (this != &a)
        {
            distruggi(radice);
            radice = copia(a.radice);
        }
        return *this;
    }
    bool operator==(const albero & a) const {
        return sonoUguali(radice, a.radice);
    }
    template <typename U>
    friend std::ostream & operator<<(std::ostream & os, const albero<U> & a);
};

template <typename T>
std::ostream & operator<<(std::ostream & os, const albero<T> & a) {
    a.stampa(a.radice);
    return os;
}



int main() {
    // Creazione di alberi
    albero<int> a1(10); // Albero con una radice con valore 10
    albero<int> a2(a1); // Copia di a1
    albero<int> a3;     // Albero vuoto

    // Stampa iniziale
    std::cout << "Albero a1: " << a1 << std::endl;
    std::cout << "Albero a2 (copia di a1): " << a2 << std::endl;
    std::cout << "Albero a3 (vuoto): " << a3 << std::endl;

    // Confronto di alberi
    std::cout << "a1 == a2? " << (a1 == a2 ? "True" : "False") << std::endl;
    std::cout << "a1 == a3? " << (a1 == a3 ? "True" : "False") << std::endl;

    // Modifica di a1
    a3 = a1; // Assegnazione
    std::cout << "Albero a3 dopo assegnazione: " << a3 << std::endl;
    std::cout << "a1 == a3? " << (a1 == a3 ? "True" : "False") << std::endl;

    return 0;
}
