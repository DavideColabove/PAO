#include <iostream>
#include "orario.h"

/*  oggetti statici
Gli attributi statici devono essere inizializzati all'esterno della classe
TRANNE IL CASO IN CUI SIANO MARCATI CONST CHE GLI CONSETE DI ESSERE INIZIALIZZATI ALL'INTERNO DELLA CLASSE

int orario::Sec_di_una_Ora = 3600;
int orario::Sec_di_un_Giorno = 86400;
*/

// versione migliore del costruttore con valori di default (funziona con qualsiasi numero di variabili passate)
// se vogliamo che un parametro abbia valore di default, devono averlo anche tutti quelli alla sua destra
class orario::orario_rappr{
    public:
        int sec;
};  // basta il costruttore di default

orario::orario(int o, int m, int s) : punt(new orario_rappr){
    if(o<0 || o>23 || m<0 || m>59 || s<0 || s>59)
        punt->sec = 0;
    else
        punt->sec = o * 3600 + m * 60 + s;
}

int orario::Ore() const{  // metodo per le ore, specifico la classe e poi il metodo
    return punt->sec / 3600; // divisione intera
}

int orario::Minuti() const{
    return (punt->sec % 3600) / 60; // %resto divisione intera
}

int orario::Secondi() const{
    return punt->sec % 60;
}

orario orario::UnOraPiuTardi() const{ // NON FA SIDE-EFFECT: non modifica il valore di 'sec', ma lo restituisce aumentato -> prende il nome di funzione costante 
    orario aux;
    aux.sec = (punt->sec + 3600) % 86400;
    return aux; //costruzione di copia quando viene ritornato per valore un oggetto
}   // marcatura const obbligatoria se la funzione non fa side-effect

void orario::AvanzaUnOra(){ // FA SIDE-EFFECT: modifica il valore di 'sec'
    punt->sec = (punt->sec + 3600) % 86400;
}

void orario::StampaSecondi() const{ // marcatura const obbligatoria se l'oggetto di invocazione é usato in sola lettura
    std::cout << punt->sec << std::endl;
}   // se ci fosse una assegnazione a 'sec' -> side-effect -> non va messo const 
    // se nel corpo della funzione invoco un metodo non costante sul'oggetto di invocazione non puó essere const

orario orario::OraDiPranzo(){
    return orario(13,15);
}

orario operator+(const orario& t, const orario& s) {
    int sec = t.Secondi() + s.Secondi();
    int min = t.Minuti() + s.Minuti();
    sec = sec % 60;
    int ore = t.Ore() + s.Ore() + min / 60;
    min = min % 60;
    ore = ore % 24;
    return orario(ore,min,sec);  
}

orario operator-(const orario& t, const orario& s){ {
    int sec = t.Secondi() - s.Secondi();
    int min = t.Minuti() - s.Minuti();
    sec = sec % 60;
    int ore = t.Ore() - s.Ore() + min / 60;
    min = min % 60;
    ore = ore % 24;
    return orario(ore,min,sec);  
}

bool orario::operator==(orario o) const{
    return punt->sec == o.sec;
}

orario orario::operator<(orario o) const{
    return punt->sec < o.sec;
}

orario orario::operator>(orario o) const{
    return punt->sec > o.sec;
}

std::ostream& operator<<(std::ostream& os,const orario& o){
    return os << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
}

int main() {
    orario mezzanotte;
    std::cout << mezzanotte.Secondi() << std::endl; //stampa 0

    orario mezzanotte = orario();
    orario adesso_preciso = orario(14,25,47); // costruttore di copia 
    orario adesso = orario(14,25); // il costruttore crea un oggetto temporaneo anonimo 
                                   // (senza l-value quindi non indirizzabile) perció lo assegnamo 
                                   // ad un oggetto della classe orario
    

    orario* ptr = new orario; // viene invocato un costruttore anche quando si crea dinamicamente un oggetto sullo heap con new
    orario* ptr1 = new orario(14,25);
    std::cout << ptr->Ore() << std::endl; //stampa 0
    std::cout << ptr1->Ore() << std::endl; //stampa 14

    std::cout << "Si pranza alle " << orario::OraDiPranzo().Ore() << " e" 
                << orario::OraDiPranzo().Minuti() << " minuti\n";     //print della funzione OraDiPranzo (mette in mostra come non viene utilizzato l'oggetto di invocazione)

    orario ora(22,45);
    orario DUE_ORE_E_UN_QUARTO(2,15);
    ora = ora + DUE_ORE_E_UN_QUARTO;    //somma di orari tramite overloading dell'operatore +
}