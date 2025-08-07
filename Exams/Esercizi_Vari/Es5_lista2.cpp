#include <iostream>
using namespace std;

class C {
    public:
        C(): size(1), a(new int[1]) {a[0]=0;}
        C& operator=(const C& x) {
            if(this!=&x){
                size=x.size;
                a=new int[size];
                for(int i=0;i<size;i++) 
                    a[i]=x.a[i];
            }
            return *this;
        }
        void add(int k) {
            int *b=a;
            a=new int[size+1];
            ++size;
            a[0]=k;
            for(int i=1;i<size;i++) 
                a[i]=b[i-1];
            delete[] b;
        }
        int& operator[](int i) const {return a[i];}
        void stampa() const {
            for(int i=0;i<size;i++) 
                cout<<a[i]<< ' ';
        }
        ~C() {stampa(); cout<<" ~C "; delete[] a;}
    private:
        int size;
        int* a;
};

main(){
    C v; v.add(1);
    C w=v; w[1]=2;
    v.stampa(); cout<<"UNO\n";
    w.stampa(); cout<<"DUE\n";
    C* p=new C; p->add(3);
    *p=v;
    (*p)[0]=4; v[1]=5;
    v.stampa(); cout<<"TRE\n";
    w.stampa(); cout<<"QUATTRO\n";
    p->stampa(); cout<<"CINQUE\n";
    w=*p;
    w[1]=6; v[0]=7;
    v.stampa(); cout<<"SEI\n";
    w.stampa(); cout<<"SETTE\n";
    p->stampa(); cout<<"OTTO\n";
    delete p; cout<<"NOVE\n";
}