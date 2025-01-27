#include<iostream>
#include<typeinfo>
#include<fstream>
#include<sstream>
using namespace std;

class D : public ios {
    public:
};

int F(ios&  ref){
    if(dynamic_cast<istream*>(&ref) && !dynamic_cast<ostream*>(&ref))
        return -1;
    if(!dynamic_cast<istream*>(&ref) && dynamic_cast<ostream*>(&ref))
        return 1;    
    if(dynamic_cast<istream*>(&ref) && dynamic_cast<ostream*>(&ref))
        return 0; 
    return 9;
}

main() {
    istream& b = cin;
    ostream& c = cout;
    stringstream d;
    ifstream e("pippo");
    ofstream f("pluto");
    D g;
    cout << F(b) << ' ' << F(c) << ' ' << F(d) << ' ' << F(e) << ' '
    << F(f) << ' ' << F(g) << endl;
    // stampa: -1 1 0 -1 1 9
}