#include "Lavoratore.h"
#include "Lavoratore.cpp"
#include<iostream>
#include<string.h>

using namespace std;

int main(){
    Dirigente d("Pippo", 4000);
    Rappresentante r("Topolino", 1000, 3, 250);
    LavoratoreOre l("Pluto", 15, 170);
    stampaStipendio(d);
    stampaStipendio(r);
    stampaStipendio(l);
}