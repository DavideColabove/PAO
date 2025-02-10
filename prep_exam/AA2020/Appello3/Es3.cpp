#include <iostream>
using namespace std;

class A {
public:
    virtual void f() const {cout <<" A::f ";}
    virtual void h() {cout <<" A::h "; m();}
    virtual void k() {cout <<" A::k "; f();}
    void m() {cout <<" A::m "; f();}
    virtual A* n() {cout <<" A::n "; return this;}
};

class B: public A {
public:
    virtual void f() const {cout <<" B::f ";}
    void h() {cout <<" B::h "; A::n();}
    virtual void m() {cout <<" B::m "; f();}
    A* n() {cout <<" B::n "; return this;}
};

class C: public A {
    public:
        virtual void f() {cout <<" D::f ";}
        void h() const {cout <<" D::h "; h();}
        void m() {cout <<" D::m "; h(); f();}
};

class D: public B {
public:
    B* n() {cout <<" E::n "; return this;}
protected:
    void r() {cout <<" E::r ";}
public:
    void m() {cout <<" E::m "; f(); r();}
};


int main() {
    A* q1 = new D(); 
    A* q2 = new B(); 
    A* q3 = new C(); 
    B* q4 = new D(); 
    const A* q5 = new C();

    //q1->f();    cout<<"\n";
    //q1->g();    cout<<"\n";
    //q2->h();    cout<<"\n";
    //q2->m();    cout<<"\n";
    //q3->g();    cout<<"\n";
    //q3->h();    cout<<"\n";
    q4->m();    cout<<"\n";
    //q4->g();    cout<<"\n";
    //(q3->n())->m();    cout<<"\n";
    //(q3->n())->n()->f();    cout<<"\n";
    //(q4->n())->m();    cout<<"\n";
    //(q5->n())->f();    cout<<"\n";
    //(dynamic_cast<B*>(q1))->m();    cout<<"\n";
    //(static_cast<C*>(q2))->g();    cout<<"\n";
    //(static_cast<B*>(q3->n()))->f();    cout<<"\n";

    return 0;
}