#include<iostream>
#include "AlberoTernario.h"

template <class T> 
class albero;

int main(){
    albero<char> t1, t2, t3;
    t1.insert('b');
    t1.insert('a');
    t2.insert('a');
    t3 = t1;
    t3.insert('c');
    std::cout << (t1 == t2) << std::endl;
    std::cout << t1.search('b') << std::endl;
    std::cout << t1 << std::endl << t2 << std::endl << t3 << std::endl;
}