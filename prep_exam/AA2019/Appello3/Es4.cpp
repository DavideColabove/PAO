#include<iostream>

using namespace std;

class Z{
    Z(int x = 0){}
};

class B{
    private:
        Z bz;
};

class C: virtual public B{
    private:
        Z* cz;
};

class D: public C{};

class E: public B{
    public:
        Z ez;
}

class F: public D, public E{
    private:
        Z* pz;
    public:
        F(const F& f): D(f), E(f), pz(f.pz){} 
}