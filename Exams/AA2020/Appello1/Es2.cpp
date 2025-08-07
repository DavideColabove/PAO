#include<iostream>
#include<list>
#include<vector>

using namespace std;

class B { 
    private:
        vector<bool>* ptr;
        virtual void m() const=0;
};
    
class D: public B { 
    private: 
        int x;
};
    
class F: public D { 
    private: 
        list<int*> l; 
        int& ref; 
        double* p; 
    public: 
        void m() const {}
        F(F f): D(f), l(f.l), ref(f.ref), p(f.p){}
        F(const F& f): D(f), l(f.l), ref(f.ref), p(f.p){}
        F& operator=(const F& f){
            D::operator=(f);
            l = f.l;
            ref = f.ref;
            p = f.p;
            return *this;
        }
};