#include<iostream>

using namespace std;

class Z{
    private:
        int x;
};

class B{
    private:
        Z bz;
};

class C: virtual public B{
    private:
        Z cz;
};

class D: public C{};

class E: virtual public B{
    public:
        Z ez;
        E& operator=(const E& e){
            B::operator=(e);
            ez = ez.e;
            return *this;
        }
};

class F: public D, public E{
    private:
        Z* fz;
    public:
        F(const F& f): B(f), D(f), E(f), fz(fz != nullptr ? new Z(*f.fz): nullptr){}
        ~F() {delete fz;}
        virtual F* clone() const{
            return new F(*this);
        }
};

