#include<iostream>
#include<typeinfo>
#include<vector>
#include<algorithm>
using namespace std;

class B {
    public:
        int k;
        B(int x=1): k(x) {}
        virtual ~B() {}
};

class C: public B {
    public:
        C(): B(2) {}
};

class D {
    public:
        B* punt;
        D(B* p): punt(p) {
            if(typeid(*p)==typeid(B)) 
                punt = new B(p->k);
        }
        D(const D& d): punt(d.punt) {
            if(typeid(*(d.punt))==typeid(B)) 
                punt = new B((d.punt)->k);
        }
        D& operator=(const D& d) {
            if(this != &d) {
                if((typeid(*(d.punt))==typeid(B))) 
                    punt = new B((d.punt)->k);
                else 
                    punt = d.punt;
        }
        return *this;
    }
};

main(){
    B b1(4), b2; C c1;
    D d1(&c1), d2(&b1), d3(&b2), d4(d1), d5(d2); d5=d1;
    vector<D> v; vector<B*> w;

    v.push_back(d1); v.push_back(d2); v.push_back(d3);
    v.push_back(d3); v.push_back(d4); v.push_back(d5);

    for(int i=0; i < v.size(); i++){
        if(find(w.begin(),w.end(),v[i].punt)==w.end()) 
            w.push_back(v[i].punt);
    }

    for(int i=0; i< w.size(); i++)
        cout << w[i]->k << ' ';
}
