/*
Si consideri la gerarchia di classi per l'I/O. La classe base ios ha il distruttore virtuale, 
il costruttore di copia privato ed un unico costruttore (a 2 parametri con valori di default) protetto.
Diciamo che le classi derivate da istream ma non da ostrean (ad esempio ifstream), e istream stessa, 
sono classi di input, le classi derivate da ostream ma non da istream (ad esempio ofstream), 
ed ostream stessa, sono classi di output, mentre le classi derivate sia da istream
che da ostream sono classi di I/O (esempi: iostream e fstrean). Quindi ogni classe di input, 
output o I/O è una sottoclasse di ios. Definire una funzione int F(ioss ref) che restituisce -1 
se il tipo dinamico di ret è un riferimento ad una classe di input, I se il tipo dinamico di ref è un 
riferimento ad una classe di output, O se il tipo dinamico di ref è un riferimento ad una classe di I/O,
mentre in tutti gli altri casi ritorna 9.
*/
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class D: public ios{ };

int F(ios& ref){
    if(dynamic_cast<istream*>(&ref) && !dynamic_cast<ostream*>(&ref)) 
        return -1;
    if(dynamic_cast<ostream*>(&ref) && !dynamic_cast<istream*>(&ref))
        return 1;
    if(dynamic_cast<istream*>(&ref) && dynamic_cast<ostream*>(&ref))
        return 0;
    return 9;
}

int main(){
    istream& b = cin;
    ostream& c = cout;
    stringstream d;
    ifstream e("pippo");
    ofstream f("pluto");
    D g;
    cout <<  F(b) << ' ' << F(c) << ' ' << F(d) << ' ' << F(e) << ' ' << F(f) << ' ' << F(g) << endl;
    // stampa: -1 1 0 -1 1 9
}