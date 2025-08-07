#include <iostream>
#include <vector>
#include <list>
using namespace std;

class B { 
private:
	list<double>* ptr;
	virtual void m() =0; 
};

class C: virtual public B {};

class D: virtual public B { 
private: 
	int x;
};

class E: public C, public D {
private:
	vector<int*> v; 
public:
	void m() {}
    E(const E& e){
        C::operator=(e);
        D::operator=(e);
        for(int i = 0; i < e.v.size(): ++i){
            v[i] = e.v[i];
        }
    }
};

main(){

}