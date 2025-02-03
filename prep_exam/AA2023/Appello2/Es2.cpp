#include <iostream>

using namespace std;

class A{
    public:
    virtual ~A() =0;
};

A::~A()=default;

class B: public A{
    public:
        ~B()=default;
};
class C: virtual public B{};
class D: virtual public B{};
class E: public C, public D{};


int fun(const A& x, B* y){
    A* p=const_cast<B*>(dynamic_cast<const B*>(&x));
    auto q=dynamic_cast<const C*>(&x);

    if(dynamic_cast<E*>(y)){
        if(!p || q) return 1;
        else return 2;
    }

    if(dynamic_cast<C*>(y)) return 3;
    if(q) return 4;
    if(p && typeid(*p)!=typeid(D)) return 5;

    return 6;

}

B b; C c; D d; E e;

int main()
{
    cout<<fun(d,&d)<<fun(b,&b)<<fun(c,&b)<<fun(e,&b)<<fun(b,&e)
    <<fun(b,&c)<<fun(c,&c)<<fun(d,&e)<<fun(c,&d)<<fun(c,&e);
}
//QUESTA E' SOLO UNA DELLE SOLUZIONI POSSIBILI