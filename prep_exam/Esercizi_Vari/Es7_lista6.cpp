#include<iostream>

using namespace std;

template<class T>
class nodo{
    public:
        nodo* sx;
        nodo* cx;
        nodo* dx;
        T info;
        nodo(T i, nodo* s = nullptr, nodo* c = nullptr, nodo* d = nullptr): info(i), sx(s), cx(c), dx(d){}
};

template<class T>
class albero<T>{
    private:
        nodo* radice;
    public:
        albero(T i, nodo* r = nullptr): nodo(i), radice(r){}

};
