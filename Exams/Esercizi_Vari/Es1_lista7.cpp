#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() {}
};

class B {
public:
    virtual ~B() {}
};

class C : virtual public A, virtual public B {
public:
    C() { cout << "C0 "; }
    C(B* x, A y = A()) { cout << "C1-2 "; }
};

class D : public C {
public:
    D() { cout << "D0 "; }
    D(C x) { cout << "D1 "; }
};

// Variabili globali
A a;
B b;
C c;
D d;

//main(){D z0(a);}
//main(){D z1(b);}
//main(){D z2(&b);}
//main(){D z3(&c);}
//main(){D z4(c);}
//main(){D z5(d);}
//main(){C z6(&a,c);}
//main(){C z7(&c);}
main(){C z8(&d,d);}