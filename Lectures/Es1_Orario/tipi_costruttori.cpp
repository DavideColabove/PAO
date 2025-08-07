#include <iostream>

class orario {
    private:
        int sec; //campo dati
    public:
        orario(); // costruttore di default -> DEVE ESSERCI SEMPRE!!
        orario(int,int);    // costruttore ore-minuti
        orario(int,int,int); // costruttore ore-minuti-secondi
        int Ore();  // selettore delle ore
        int Minuti(); // selettore dei minuti
        int Secondi(); // selettore dei secondi
};
 
orario::orario(){   // costruttore di default 
    sec = 0;    
}

orario::orario(int o, int m){ 
    if(o<0 || o>23 || m<0 || m>59) 
        sec = 0;
    else
        sec = o * 3600 + m * 60;
}

orario::orario(int o, int m, int s){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        sec = 0;
    else
        sec = o * 3600 + m * 60 + s;    
}
