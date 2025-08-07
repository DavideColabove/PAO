#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<fstream*> Fun(const vector<const ios*>& v){
    vector<fstream*> copia;
    for(auto i:v){
        iostream* nios = const_cast<iostream*>(dynamic_cast<const iostream*>(i));
        fstream* nfst = const_cast<fstream*>(dynamic_cast<const fstream*>(i));
        if(nios->tellg() > nios->tellg())
            nios->setstate(ios::failbit);
        if(nfst->rdstate() && nfst->is_open()){
            nfst->close();
            copia.push_back(nfst);
        }
    }
    if((*v).empty())
        throw std::exception;
    return copia;
}