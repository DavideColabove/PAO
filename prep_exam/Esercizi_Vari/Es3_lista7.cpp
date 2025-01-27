#include<iostream>

using namespace std;

class A {
    public:
    virtual  ~A() {};
};
class B: public A {};
class C: virtual public B {};
class D: virtual public B {};
class E: public C, public D {};

char F(A* p, C& r) {
    B* punt1 = dynamic_cast<B*> (p);
    try{
        E& s = dynamic_cast<E&> (r);
    }
    catch(bad_cast) {
        if(punt1) return ’O’;
        else return ’M’;
    }
    if(punt1) return ’R’;
    return 'A';
}

main(){
    A a; B b; C c; D d; E e;
    cout << F(&b,e) << F(&b,c) << F(&a,c) << F(&a,e);
}