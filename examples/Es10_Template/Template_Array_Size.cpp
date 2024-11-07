#include <iostream>

template <class T, int size>

T min (T (&a) [size]){
    T vmin = a[0];
    for (int i=1; i<size; ++i){
        if (a[i] < vmin)
            vmin = a[i];
    }
    return vmin;
}

int main() {
    int ia[20]{3,5,6,15,76,18,23,45,24,11,14,12,765,43,15,12,98,64,28,29};
    orario ta[50];

    std::cout << min(ia);
    std::cout << min(ta);
    //oppure
    std::cout << min<int,20>(ia);
    std::cout << min<orario,50>(ta);
}