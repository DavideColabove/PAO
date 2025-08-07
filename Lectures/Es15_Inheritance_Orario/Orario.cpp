#include<iostream>
#include "Orario.h"

using std::endl;

orario::orario(int o, int m, int s){
    if(o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        sec = 0;
    else
        sec = o * 3600 + m * 60 + s; 
}

int orario::Ore() const{
    return sec / 3600;
}

int orario::Minuti() const{
    return (sec % 3600)  / 60;
}

int orario::Secondi() const{
    return sec % 60;
}

orario orario::operator+(const orario& o) const{
    int sec = (*this).Secondi() + o.Secondi();
    int minuti = (*this).Minuti() + o.Minuti();
    int ore = (*this).Ore() + o.Ore();
    return orario(ore,minuti,sec);
}

bool orario::operator<(const orario& o) const{
    return (*this).sec < o.sec;
}

bool orario::operator==(const orario& o) const{
    return (*this).sec == o.sec;
}

int main(){
    orario o1(12,34,11);
    orario o2(12,34,11);
}