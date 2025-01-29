#include<iostream>
#include<vector>
#include<list>
#include<fstream>
#include<sstream>
#include<string>
#include<typeinfo>
using namespace std;

template <class T>
list<const iostream*> compare(vector<ostream*>& v, vector<const T*>& w){
    if(v.size() != w.size())
        throw string("");
    list<const iostream*> lista;
    for(int i =0; i < v.size(); ++i){
        if(dynamic_cast<fstream*>(v[i]) && typeid(*v[i]) == typeid(*w[i])){
            lista.emplace_back(dynamic_cast<const iostream*>(v[i]));
            ostream* temp = *v[i];
            T* t = const_cast<T*>(*w[i]);
            v.erase(v.begin()+i);
            w.erase(t);
            delete t;
            delete temp;
        }
        if((dynamic_cast<stringstream*>(w[i]))->good() && typeid(*v[i]) != typeid(*w[i]))
            lista.emplace_back(dynamic_cast<const iostream*>(w[i]));
    }
    return lista;
}