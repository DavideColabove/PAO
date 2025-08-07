#include<iostream>
#include<typeinfo>
#include<vector>

using namespace std;

class B {public: virtual  ~B() {} };

class C: public B {};

class D: public B {};

class E: public C {};

int Fun(vector<B*> &v){
    if(v.empty())
        return 0;
    int c = 0;
    for(auto elem:v){
        if(dynamic_cast<C*>(elem) && typeid(*elem) != typeid(*v[0]))
            c++;
    }
    return c;
}

main() {
    vector<B*> u, v, w;
    cout << Fun(u) << endl; // stampa 0
    B b; C c; D d; E e; B *p = &e, *q = &c;
    v.push_back(&c); v.push_back(&b); v.push_back(&d); v.push_back(&c);
    v.push_back(&e); v.push_back(p);
    cout << Fun(v) << endl; // stampa 2
    w.push_back(p); w.push_back(&d); w.push_back(q); w.push_back(&e);
    cout << Fun(w) << endl; // stampa 1
}

