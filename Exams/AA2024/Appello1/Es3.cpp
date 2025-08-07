#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<list>
using namespace std;

template<class T>
list<const iostream*> fun(vector<ostream*>& v){
    list<const iostream*> lista;
    for(auto p: v){
        if(p)
            if(!((dynamic_cast<fstream*>(p))->good()))
                p = nullptr;
        if(p){
            if(const stringstream* s = dynamic_cast<stringstream*>(p)){
                if(s->good())
                    lista.push_back(s);
            }
        }
    }
    if(lista.empty())
        throw T();
    else
        return lista;
}