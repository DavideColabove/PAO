#include<iostream>

template <class T> class albero; //dichiarazione incompleta per far riconoscere operator<<

template <class T>
std::ostream& operator<<(std::ostream&, const albero<T>&);

template <class T>
class albero{
    friend std::ostream& operator<< <T> (std::ostream&, const albero<T>&);
    private:
        class nodo{
            public:
                T info;
                nodo *sx, *cx, *dx;
                nodo(const T& t, nodo* _sx = nullptr, nodo* _cx = nullptr, nodo* _dx = nullptr): info(t), sx(_sx), cx(_cx), dx(_dx){}               
        };
        nodo* radice;
        static nodo* copia(nodo*);
        void distruggi(nodo*);
        static bool rec_search(const T&, nodo*);
        static bool equals(nodo*, nodo*);
        static std::ostream& rec_print(std::ostream&, nodo*);
    public:
        albero();
        albero& operator=(const albero&);
        albero(const albero& a): radice(copia(a.radice)) {}
        ~albero() {if(radice) distruggi(radice);}
        void insert(const T&);
        bool search(const T&) const;
        bool operator==(const albero&) const;
};

template <class T>
typename albero<T>::nodo* albero<T>::copia(nodo *r){
    if(!r)
        return nullptr;
    return new nodo(r->info, copia(r->sx), copia(r->cx), copia(r->dx));
}

template <class T>
void albero<T>::distruggi(nodo *r){
    if(r != nullptr){
        distruggi(r->sx);
        distruggi(r->cx);
        distruggi(r->dx);
        delete r;
    }
}

template <class T>
bool albero<T>::rec_search(const T& t,nodo* r){
    if(r == nullptr)
        return false;
    // l'albero radicato in r non vuoto
    if(r->info == t)
        return true;
    // l'albero radicato in r e t non é presente nella radice
    return rec_search(t, r->sx) || rec_search(t, r->cx) || rec_search(t, r->dx);
}

template <class T>
bool albero<T>::equals(nodo *r1, nodo *r2){
    if(r1 == nullptr && r2 == nullptr)
        return true;
    // r1 || r2
    if(r1 == nullptr || r2 == nullptr)
        return false;
    // r1 && r2
    return r1->info == r2->info && equals(r1->sx, r2->sx) && equals(r1->cx, r2->cx) && equals(r1->dx, r2->dx);
}

template <class T>
std::ostream &albero<T>::rec_print(std::ostream& os, nodo* r){
    if(r){
        os << r->info << ' ';
        rec_print(os, r->sx);
        rec_print(os, r->cx);
        rec_print(os, r->dx);
    }
    return os;
}

template <class T>
albero<T>::albero() : radice(nullptr) {}

template <class T>
albero<T>& albero<T>::operator=(const albero& a){
    if(this != &a){
        distruggi(radice);
        radice = copia(a.radice);
    }
    return *this;
}

template <class T>
void albero<T>::insert(const T& t){
    radice = new nodo(t, radice, copia(radice), copia(radice));
}

template <class T>
bool albero<T>::search(const T& t) const{
    return rec_search(t, radice);
}

template <class T>
bool albero<T>::operator==(const albero& t) const{
    if(this == &t)
        return true;
    return equals(radice, t.radice);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const albero<T>& t){
    return albero<T>::rec_print(os,t.radice);
}