#include<iostream>

using namespace std;

class A{
    public:
        virtual ~A();
};

A::~A() {}

class B: public A{
    public:
};

class C{
    private:
        B* b;
    public:
        C(A* a = new A()): b(dynamic_cast<B*>(a)){}
        B* fun (A* a){
            return dynamic_cast<B*>(a);
        }
};