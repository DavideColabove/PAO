#include<iostream>
#include<string>
using namespace std;

class B: public string {
    friend class E;
    protected:
        static int i;
    public:
        B() {i++; cout << i << " B() ";};
        B(string s): string(s) {i++; cout << i << " " << s << " B(string) ";};
};
int B::i=0;

class C: virtual public B {
    public:
        C(int x = i) {cout << x << " C(0-1) ";};
        C(B d) {(B::i)++; cout << "C(B) ";};
};

class D: virtual public B {
    public:
        D(): B("pluto") {cout << "D() ";};
};

class E {
    public:
        D d;
        E() {(B::i)++; cout << "E() ";};
        E(D d) {(B::i)++; cout << "E(D) ";};
};

template<class T>
class F: public C, public D ,public E {
    public:
        T t;
        F(T x): E(D()), C(B()) {cout << i << " F(0-1) ";};
};

main() {
    E e; cout << " UNO\n";
    F<B> f(e.d); cout << " DUE\n";
    F<B>& rf = f; cout << " TRE\n";
    F<string>* pf = new F<string>("paperino"); cout << " QUATTRO\n";
}