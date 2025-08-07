#include<iostream>

using namespace std;

template<class T>
class SmartP{
    private:
        T* p;
    public:
        SmartP(): p(nullptr){}
        SmartP(const T* ptr): p(new T(*const_cast<T*>(ptr))){}
        SmartP(const SmartP<T>& sp): p(new T(*(sp.p))){}
        SmartP<T>& operator=(const SmartP<T>& sp){
            if(this != &sp){
                delete p;
                p = new T(*sp.p);
            }
            return *this;
        }
        ~SmartP() {
            delete p;
        }
        T& operator*() const{
            return *p;
        }
        T* operator->() const{
            return p;
        }
        bool operator==(const SmartP& sp) const{
            return sp.p == p;
        }
        bool operator!=(const SmartP& sp) const{
            return sp.p != p;
        }
        SmartP<T> operator()(T*& p){
            return SmartP(p);
        }
};


class C{
    public:
        int *p;
        C(): p(new int (5)){}
};

int main(){
    const int a=1; const int* p = &a;
    
    SmartP<int>r;
    SmartP<int>s(&a);
    SmartP<int> t(s);
    
    cout<< *s  << " " <<*t << *p <<endl;
    *s=2; *t = 3;
    
    cout<< *s  << " " <<*t << *p << endl;
    r=t; *r=4;
    
    cout<<*r << *s  << " " <<*t << *p <<endl;
    
    cout<< (s==t) << (s!=p) <<endl;
    
    C c; SmartP<C> x(&c);
    cout << *(c.p) <<" " << *(x->p); cout << endl;
    
    *(c.p) = 6;
    cout << *s(c.p) << " " << *(x->p);cout << endl;
    SmartP<C> * q= new SmartP<C>(&c);
    delete q;
    cout << *(x->p); cout << endl;
}
