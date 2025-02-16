#include<iostream>

using namespace std;

class A {
    public:
        virtual void m() =0;
};

class B: virtual public A {};

class C: virtual public A {
        public:
    virtual void m() {}
};

class D: public B, public C {
    public:
        virtual void m() {}
};

class E: public D {};

class F: public E {};
    
char G(A* p, B& r) {
    C* pc = dynamic_cast<E*>(&r);
    if(pc && typeid(*p)==typeid(r)) 
        return 'G';
    if(!dynamic_cast<E*>(&r) && dynamic_cast<D*>(p))
        return 'Z';
    if(!dynamic_cast<F*>(pc)) 
        return 'A';
    else if(typeid(*p)==typeid(E)) 
        return 'S';
    return 'E';
}
int main(){
    cout << G(new E,*new F) << G(new D,*new E) << G(new E, *new E) << G(new F,*new F) << G(new C, *new F) << G(new E,*new D) << G(new F, *new D) << G(new C,*new E);
}

