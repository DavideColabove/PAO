#include<iostream>

using namespace std;

template <class X, class Y>
X* fun(X* p){ return dynamic_cast<Y*>(p); }

int main(){
    D d; fun<A,B>(&d);
    if( fun<A,B>(new D()) == 0) cout << "Bjarne ";
    if( dynamic_cast<D*>(new B() == 0)) cout << "Stroustrup";
    A* p = fun<C,B>(new C());
}