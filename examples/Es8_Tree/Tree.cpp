#include<iostream>
#include"Tree.h"

Nodo* Tree::copia(Nodo* r){
    if(r == nullptr)
        return nullptr;
    return new Nodo(r->info, copia(r->sx), copia(r->dx));
}

void Tree::distruggi(Nodo* r){
    if(r != nullptr){
        distruggi(r->sx);
        distruggi(r->dx);
        delete r;
    }
}

Tree& Tree::operator=(const Tree& t){
    if(this != &t){
        distruggi(root);
        root = copia(t.root);
    }
    std::cout << "C=" << std::endl; 
    return *this;
}
