#include<iostream>
#include<list>
#include<vector>
#include<typeinfo>
#include<string>

using namespace std;

class A{
    public:
        virtual A* f() const = 0;
};

class B: public A{};

class C: public B{
    public:
        B* f() const{
            return new C();
        }
};

class D: public B{};

class E: public B{
    public:
        A* f() const{
            return new E();
        }
};

class F: public C, public D, public E{
    public:
        D* f() const{
            return new F;
        }
};

list<const D* const> fun(const vector<const B*>& v){
    list<const D* const> lista;
    int c = 0;
    for(vector<const B*>::iterator it = v.begin(); it != v.end();){
        const B* q =  *it;
        if(q != nullptr && typeid(*q) == typeid(C)){
            c++;
            if(c > 2){
                throw C();
            }
            it = v.erase(it);
            delete q;
        }
        else{
            A* ptr = q->f();
            if(!ptr)
                throw string("nullptr");
            if(dynamic_cast<D*>(ptr) && !(dynamic_cast<E*>(ptr)))
                lista.push_back(dynamic_cast<const D*>(ptr));
            ++it;
        }
    }
    return lista;
} 