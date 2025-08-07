#include <iostream>

template <class T>

T min(T a, T b){
    return a < b ? a : b;       //creo dei vincoli, dipende da un parametro di tipo
} 

int main(){
    int i, j, k;
    i = 10;
    j = 8;
    //orario r, s, t;

    //istanziazione implicita del template
    k = min(i,j);
    std::cout << k << std::endl;
    //j = min(r,s);

    //istanziazione esplicita del template: meno utilizzata!
    k = min<int>(i,j);
    //j = min<orario>(r,s);
}