#include<iostream>

using std::ostream;

class Vettore{
    friend ostream& operator<<(ostream&, const Vettore&);
    private:
        int *v;
        unsigned int dim;
    public:
        Vettore(unsigned int d = 0, int init = 0): v(dim==0 ? nullptr : new int[dim]), dim(d){
            for(int i = 0; i<dim; ++i)
                v[i] = init;
        }
        bool operator==(const Vettore& v) const{
            if(this == &v)
                return true;    // caso vettore v = v
            if(dim != v.dim)
                return false;
            for(int i = 0; i<dim; i++){
                if(this->v[i] != v.v[i])
                    return false;
            }
            return true;
        }
        int& operator[](unsigned int i) const{
            if(i < 0 || i >= dim)
                throw std::out_of_range("Indice out-of-range");
            else
                return v[i];
        }
        Vettore(const Vettore& v): dim(v.dim), v(new int[dim]) { 
            for(int i = 0; i<dim; i++){
                this->v[i] = v.v[i];
            }
        }
        Vettore& operator=(const Vettore& vet){
            if(this != &vet){
                delete[] v;
                dim = vet.dim;
                if(dim == 0)
                    return *this;
                else{
                    new int[dim];
                    for(int i = 0; i<dim; ++i){
                        v[i] = vet.v[i];
                    }
                }
            }
            return *this;
        }
        ~Vettore(){
            delete[] v;
        }
};

ostream& operator<<(ostream& os, const Vettore& v){
    for(int i=0; i<v.dim; ++i){
        os << v.v[i] << ' ';
    }
    return os;
}

int main()
{
    Vettore v1(5);  // Vettore di dimensione 5
    v1[0] = 10;    // Assegna un valore
    v1[1] = 20;    // Assegna un altro valore

    Vettore v2 = v1; // Costruttore di copia
    v2[2] = 30;     // Modifica il valore di v2

    std::cout << "v1: " << v1 << std::endl; // Output: v1: 10 20 0 0 0
    std::cout << "v2: " << v2 << std::endl; // Output: v2: 10 20 30 0 0

    v1 = v2;        // Assegnazione profonda
    std::cout << "v1: " << v1 << std::endl; // Output: v1: 10 20 30 0 0

    return 0;
}