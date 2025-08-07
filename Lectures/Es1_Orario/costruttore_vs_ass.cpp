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
 
int orario::Ore(){  // metodo per le ore, specifico la classe e poi il metodo
    return sec / 3600; // divisione intera
}

int orario::Minuti(){
    return (sec % 3600) / 60; // %resto divisione intera
}

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

int main() {
        orario adesso(11,55);   // costruttore ore-minuti
        orario copia;           // costruttore di default
        copia = adesso;         // assegnazione 

        orario copia1 = adesso; // costruttore di copia analogo a int x=y
        orario copia2(adesso);  // costruttore di copia analogo a int x(y)

        /*
            il COSTRUTTORE DI COPIA crea un nuovo oggetto copia1 in cui copia,
            capo dati per campo dati, l'oggetto adesso

            l'ASSEGNAZIONE assegna il valore di ogni capo dati dell'oggetto adesso
            al corrispondente campo dati dell'oggetto preesistente copia
        */
}
