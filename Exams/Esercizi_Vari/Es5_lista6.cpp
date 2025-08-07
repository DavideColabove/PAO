#include <iostream>
using namespace std;

class A {
private:
void h() {cout<<" A::h ";}
public:
virtual void g() {cout <<" A::g ";}
virtual void f() {cout <<" A::f "; g(); h();}
void m() {cout <<" A::m "; g(); h();}
virtual void k() {cout <<" A::k "; g(); h(); m(); }
A* n() {cout <<" A::n "; return this;}
};

class B: public A {
private:
virtual void h() {cout <<" B::h ";}
public:
virtual void g() {cout <<" B::g ";}
void m() {cout <<" B::m "; g(); h();}
void k() {cout <<" B::k "; g(); h(); m();}
B* n() {cout <<" B::n "; return this;}
};
B* b = new B(); A* a = new B();


int main() {
    cout << "b->f(): ";
    b->f();
    cout << endl;

    cout << "b->m(): ";
    b->m();
    cout << endl;

    cout << "b->k(): ";
    b->k();
    cout << endl;

    cout << "a->f(): ";
    a->f();
    cout << endl;

    cout << "a->m(): ";
    a->m();
    cout << endl;

    cout << "a->k(): ";
    a->k();
    cout << endl;

    cout << "(b->n())->g(): ";
    (b->n())->g();
    cout << endl;

    cout << "(b->n())->n()->g(): ";
    (b->n())->n()->g();
    cout << endl;

    cout << "(a->n())->g(): ";
    (a->n())->g();
    cout << endl;

    cout << "(a->n())->m(): ";
    (a->n())->m();
    cout << endl;

    delete b; // Pulizia della memoria
    delete a;
    return 0;
}