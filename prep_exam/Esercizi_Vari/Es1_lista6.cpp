#include <iostream>
using namespace std;

class B {
public:
    int b;
    explicit B(int x = 1) : b(x) {}
    virtual B* m(B& x) { return new B(b + x.b); }
    virtual void print() { cout << b << " "; }
};

class C : public B {
public:
    int c;
    explicit C(int x = 2) : B(x), c(x) {}
    void print() { B::print(); cout << c << " "; }
    void f() { B* x = m(*this); x->print(); }
};

class D : public C {
public:
    int d;
    explicit D(int x = 3) : C(x), d(x) {}
    B* m(B& x) {
        C* p = dynamic_cast<C*>(&x);
        D* q = dynamic_cast<D*>(&x);
        if (!p) return new C(d + x.b);
        if (q) return new D(d + q->d);
        return new B(x.b);
    }
    void print() { C::print(); cout << d << " "; }
};

int main() {
    B b(1); C c; D d;
    B* p1 = new D(3); B* x;
    B* p2 = p1->m(*p1); p2->print(); cout << " **1\n";

    x = p1->m(c); x->print(); cout << " **2\n";

    x = p1->m(b); x->print(); cout << " **3\n";

    x = p2->m(*p1); x->print(); cout << " **4\n";

    x = x->m(b); x->print(); cout << " **5\n";

    C* p3 = new C(4); p3 -> f(); cout << " **6\n";

    p3 = &d; p3->f(); cout << " **7\n";

    (dynamic_cast<C*>(p3->m(d)))->f(); cout << " **8\n";

    return 0;
}