#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;


Vettore& Vettore::operator=(const Vettore& v){
    if(this != &v){
        delete[] a;
        size = v.size;
        if(size == 0)
            return *this;
        else{
            new int[size];
            for(int j=0; j<size; ++j){
                a[j] = v.a[j];
            }
        }
    }
    return *this;
}

Vettore::~Vettore(){
    delete[] a;
}

Vettore& Vettore::append(const Vettore& v){
    if(v.size != 0){
        int* p = new int[size + v.size];
        unsigned int j = 0;
        for(; j < size; ++j)
            p[j] = a[j];
        for(; j < size + v.size; ++j)
            p[j] = v.a[j-size];
        delete[] a;             //FONDAMENTALE
        a = p;
        size = size + v.size;
    }
    return *this;
}

Vettore Vettore::operator+(const Vettore& v) const{
    Vettore aux(*this);
    aux.append(v);
    return aux;
}

bool Vettore::operator==(const Vettore& v) const{
    if(this == &v)
        return true;    //caso vettore v=v
    if(size != v.size)
        return false;
    for(unsigned int j=0; j<size; ++j){
        if(a[j] != v.a[j])
            return false;
    }
    return true;
}

int& Vettore::operator[](unsigned int j) const{
    return a[j];
}

unsigned int Vettore::getSize() const{
    return size;
}

int main(){
    Vettore v1(4), v2(3,2), v3(5,-3), v4;
    v1 = v2+v3;
    v2.append(v2);
    v3.append(v1).append(v3);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
}