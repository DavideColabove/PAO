#include<iostream>

using namespace std;

class D;

class B {
    public:
        virtual D* f() =0;
};

class C {
    public:
        virtual C* g();
        virtual B* h() =0;
};

class D: public B, public C {
    public:
        D* f() {cout << "D::f "; return new D;}
        D* h() {cout << "D::h "; return dynamic_cast<D*>(g());}
};

C* C::g() {
    cout << "C::g ";
    B* p = dynamic_cast<B*>(this);
    if(p) 
        return p->f(); 
    else 
        return this;
}

class E: public D {
    public:
        E* f() {
            cout << "E::f ";
            E* p = dynamic_cast<E*>(g());
            if(p) 
                return p; 
                else return this;
        }
};

class F: public E {
    public:
        E* g() {cout << "F::g "; return new F;}
        E* h() {
            cout << "F::h ";
            E* p = dynamic_cast<E*>(E::g());
            if(p) 
                return p; 
            else 
                return new F;
        }
};

B* p; C* q; D* r;

int main(){
    r = new F; r->h();
}
