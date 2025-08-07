#include<iostream>
#include<fstream>
#include<typeinfo>
using namespace std;
class C { 
    public: 
        virtual  ~C() {} 
};

template<class T1, class T2>
bool Fun(T1* p, T2& r){
    if(!is_same_v<T1,T2>)
        return false;
    if(typeid(*p) != typeid(r))
        return false;
    if(!(dynamic_cast<ios*>(p) && dynamic_cast<ios*>(&r)))
        return false;
    return true;
}

main() {
    ifstream f("pippo"); fstream g("pluto"), h("zagor"); iostream* p = &h;
    C c1,c2;
    cout << Fun(&cout,cin) << endl; // stampa: 0
    cout << Fun(&cout,cerr) << endl; // stampa: 1
    cout << Fun(p,h) << endl; // stampa: 0
    cout << Fun(&f,*p) << endl; // stampa: 0
    cout << Fun(&g,h) << endl; // stampa: 1
    cout << Fun(&c1,c2) << endl; // stampa: 0
}