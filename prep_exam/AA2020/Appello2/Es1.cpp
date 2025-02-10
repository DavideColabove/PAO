#include<iostream>
using namespace std;

template<class T, int sz = 0>
class Vettore{
    private:
        T* ptr;
    public:
        Vettore(const T& x = T()): ptr(sz==0? nullptr: new T[sz]){
            for(int i = 0; i<sz; i++){
                ptr[i] = x;
            }
        }
        Vettore(const Vettore& v): ptr(sz==0? nullptr: new T[sz]){
            for(int i = 0; i < sz; i++){
                ptr[i] = v.ptr[i];
            }
        }
        Vettore& operator=(const Vettore& v){
            if(this != &v){
                delete [] ptr;
                ptr = sz==0? nullptr: new T[sz];
                for(int i = 0; i<sz; ++i){
                    ptr[i] = v.ptr[i];
                }
            }
            return *this;
        }
        ~Vettore(){
            delete [] ptr;
        }
        T& operator*(){
            return ptr[0];
        }
        const T& operator*() const{
            return ptr[0];
        }
        T& operator[](int i){
            return ptr[i];
        }
        const T& operator[](int i) const{
            return ptr[i];
        }
};

template<class T, int sz>
ostream& operator<<(ostream& os, const Vettore<T,sz>& v){
    for(int i = 0; i < sz; ++i){
        os << v[i] << ' ';
    }
    return os;
}

int main() {
  Vettore<int,4> v1(2); Vettore< Vettore<int,3> ,3> v2(3);
  Vettore<int,4> v3(v1); Vettore<int,4> v4; v3[2]=6;
  *v1=9;
  v4=v1;
  v4[3]=5;
  cout << v1 << endl; // 9 2 2 2
  cout << v2 << endl; // 3 3 3  3 3 3  3 3 3
  cout << v3 << endl; // 2 2 6 2
  cout << v4 << endl; // 9 2 2 5
}

