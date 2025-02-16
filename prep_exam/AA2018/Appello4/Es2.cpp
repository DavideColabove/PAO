#include<iostream>

using namespace std;

class A{
    public:
        virtual ~A(){}
};

class B: public A{
    public:
        virtual void f() = 0;
};

class C: public B{
    public:
        void f() const{}
};

class D{
    private:
        int num
    protected:
        D(int n): num(n){}
};

class E: public D{
    private:
        int a;
        double b;
    public:
        E& operator=(const E& e){
            if(this != &e){
                D::operator=(e);
                a = e.a;
                b = e.b;
            }
            return *this;
        }
};
