#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

class A {
    private:
        int k;
    public:
        A(int x=9): k(x) {cout << "A01 ";}
        virtual ~A() {cout << k << " ~A() ";}
        virtual void m() {cout << k << " A::m() ";}
};

class B: virtual public A {
    private:
        string s;
    public:
        ~B() {cout << "~B() ";}
        B(string _s = "pippo"): s(_s) {cout << "B01 ";}
        virtual void m(int x) {cout << s << " B::m(int) ";}
};

class C: virtual public A {
    public:
        C(int x): A(x) {}
};

class D: public B, public C {
    public:
        D(int x=8): A(x), C(x) {cout << "D01 ";}
        virtual void m() {cout << "D::m() ";}
        virtual void m(int x) {cout << "D::m(int) ";}
};

class E: public D {
    private:
        A a;
    public:
        E(): D(5) {cout << "E() ";}
        E(const A& _a): a(_a) {cout << "E(A) ";}
        virtual void m() {cout << "E::m() ";}
        virtual void m(int x) {cout << "E::m(int) ";}
};

main() {
    B b("zagor"); cout << "ZERO\n";
    D* pd = new D(6); cout << "UNO\n";
    b = *pd; b.m(5); cout << "DUE\n";
    E* pe = new E(); cout << "TRE\n";
    E e2(b); cout << "QUATTRO\n";
    delete pd; cout << "CINQUE\n";
    pd = pe; pd->m(); cout << "SEI\n";
    E* q = dynamic_cast<E*>(pd); q->D::m(4); cout << "SETTE\n";
    delete pe; cout << "OTTO\n";
}