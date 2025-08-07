#include <iostream>
#include <vector>
using namespace std;

class A{
private:
    virtual void f() const = 0;
    vector<int*>* ptr;
};

class D: virtual public A{
private:
    int z;
    double w;
};

class E: public D{
private:
    vector<double*> v;
    int *p;
    int& ref;
public:
    void f() const {}
    E(): p(new int(0)), ref(*p) {}
    //ridefinizione del costruttore di copia di E
    E(const E& e): D(e), v(e.v), p(e.p), ref(e.ref) {}
}