#include<iostream>

class Vettore{
    private:
        int* a;
        unsigned int size;
        // vettore vuoto IFF a==nullptr && size==0
        // vettore non vuoto IFF a!= nullptr && size > 0
    public:
        Vettore(unsigned int dim = 0, int init = 0): a(dim == 0 ? nullptr : new int[dim]), size(dim) {for(int j=0; j<dim; ++j) a[j] = init;}
        Vettore& operator=(const Vettore& v);
        Vettore(const Vettore& v): a(v.size == 0 ? nullptr : new int[v.size]), size(v.size) {for(int j=0; j<size; ++j) a[j] = v.a[j];}
        ~Vettore();
        Vettore operator+(const Vettore&) const;
        Vettore& append(const Vettore&);
        bool operator==(const Vettore&) const;
        int& operator[](unsigned int) const;
        unsigned int getSize() const;
};

std::ostream& operator<<(std::ostream& os, const Vettore& v){
    for(unsigned int j=0; j<v.getSize(); ++j){
        os << v[j] << ' ';
    }
    return os;
}