#include<iostream>
#include<fstream>
#include<sstring>

using namespace std;

class Fallimento{};

long Fun(const ios& s){
    const ifstream* ifs = dynamic_cast<const ifstream*>(&s)
    if(s.fail())   
        throw Fallimento();
    if(!ifs)
        return -2;
    if(!(ifs->is_open()))
        return -1;
    ifstream* nifs = const_cast<ifstream*>(ifs);
    return nifs->tellg();
}