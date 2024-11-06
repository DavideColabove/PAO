#include "bolletta.h"

using std::ostream;
using std::endl;

bolletta::nodo::nodo() : next(0) {} // costruttore di defult per il campo dati info

bolletta::nodo::nodo(const telefonata& t, nodo* s ) : info(t), next(s) {}

bolletta::bolletta() : first(0) {}

bolletta::bolletta(const bolletta& b) : first(copia(b.first)) {}    // COPIA PROFONDA

ostream& operator<<(ostream& os ,const bolletta& b){
    os << "TELEFONATE IN BOLLETTA:" << endl;
    bolletta::nodo* p = b.first;
    int i = 1;
    while(p){
        os << i++ << ") " << p->info << endl;
        p = p->next;
    }
    return os;
}

bool bolletta::iteratore::operator==(const iteratore& i) const {
    return punt == i.punt;
}

bool bolletta::iteratore::operator!=(const iteratore& i) const {
    return punt != i.punt;
}

bolletta::iteratore& bolletta::iteratore::operator++() {    // prefisso
    if(punt)   
        punt = punt->next;
    return *this;
}   // N.B. se punt == 0 non fa nulla

bolletta::iteratore bolletta::iteratore::operator++(int) {  // postfisso
    iteratore aux = *this;
    if(punt)
        punt = punt->next;  // side-effect
    return aux;
}

bolletta::iteratore bolletta::begin() const {
    bolletta::iteratore aux;
    aux.punt = first;   // amicizia
    return aux;
}

bolletta::iteratore bolletta::end() const {
    bolletta::iteratore aux;
    aux.punt = nullptr; // amicizia
    return aux; 
}

telefonata& bolletta::operator[](const bolletta::iteratore& it) {
    return (it.punt)->info; // amicizia
    // NB: nessun controllo it.punt != 0
}

bolletta::nodo::~nodo() {
    // invocazione automatica del distruttore di telefonata
    // deallocazione automatica puntatore next
    if(next != 0)
        delete next;
}

bolletta::~bolletta() {
    if(first)
        delete first;
}

bolletta& bolletta::operator=(const bolletta& b){   // ASSEGNAZIONE PROFONDA
    if(this == &b){         // != tra puntatori -> evita il problema x = x 
        distruggi(first);       // pulizia dello heap
        first = copia(b.first); // operator= tra puntatori
    }
    return *this;           // ritorna l'oggetto di invocazione
}

bool bolletta::Vuota() const {
    return first == 0;
}

void bolletta::Aggiungi_Telefonata(const telefonata& t){
    first = new nodo(t, first); // crea un nuovo nodo e lo inserisce in testa alla lista
}

void bolletta::Togli_Telefonata(const telefonata& t){
    nodo* p = first, *prec = nullptr;
    while(p && !(p->info == t)){
        prec = p;
        p = p->next;
    }   // p==0 (not found) o p punta al nodo da rimuovere
    if(p){  // ho trovato t
        if(!prec)   // p punta al primo nodo
            first = p->next;
        else    //p punta ad un nodo succesivo al primo
            prec->next = p->next;
        delete p;   // ATTENZIONE: deallocare!
    }
}

telefonata bolletta::Estrai_Una(){
    // PRECONDIZIONE: bolletta non vuota
    nodo* p = first;
    first = first->next;
    telefonata aux = p->info;   // costruttore di copia
    delete p;   // ATTENZIONE: deallocare!
    return aux;
}

bolletta::nodo* bolletta::copia(nodo* p){
    if(!p) 
        return nullptr;  // caso base: lista vuota
    else
        return new nodo(p->info, copia(p->next));
        // passo induttivo:
        // per ip.indutt. copia(p->next) é la copia della coda di p,
        // quindi inserisco una copia del primo nodo di p in testa alla lista copia(p->next)
}
/*
VERSIONE ITERATIVA:

bolletta::nodo* bolletta::copia(nodo* p){
    if(!p)
        return nullptr;
    nodo* primo = new nodo(p->info, nullptr);
    nodo* q = primo;
    while(p->next){
        p = p->next;
        q->next = new nodo(p->info, nullptr);
        q = q->next;
    }
    return primo;
}
*/

void bolletta::distruggi(nodo* p){
    // caso base: lista vuota => nulla da fare
    if(p){
        // passo induttivo:
        // per ip.indutt. distruggi(p->next) dealloca la coda di p
        // e rimane quindi da deallocare solamente il primo nodo di p
        distruggi(p->next);
        delete p;
    }
}  
/*
VERSIONE ITERATIVA:

void bolletta::distruggi(nodo* p){
    if(p != nullptr){
        //scorro tutta la lista deallocando ogni nodo
        nodo* q = p;
        while (p != nullptr){
            p = p->next;
            delete q;
            q = p;
        }
    }
}
*/

orario Somma_Durate(const bolletta& b){
    orario durata;  // costruttore di default di orario
    for(bolletta::iteratore it = b.begin(); it != b.end(); ++it){
        durata = durata + (b[it].Fine() - b[it].Inizio());
    }
    return durata;
}

bolletta Chiamate_A(int num, bolletta& b){
    bolletta selezionate, resto;    // oggetti locali
    while(!b.Vuota()){
        telefonata t = b.Estrai_Una();
        if(t.Numero() == num)
            selezionate.Aggiungi_Telefonata(t);
        else
            resto.Aggiungi_Telefonata(t);
    }
    b = resto;  // overloading di operator= in bolletta
    return selezionate;
}

telefonata& bolletta::iteratore::operator*() const {
    return punt->info;
}

telefonata* bolletta::iteratore::operator->() const {
    return &(punt->info);
}

int main(){
    bolletta b1;

    int n1 = 2121212, n2 = 3131313;

    telefonata t1(orario(9,23,12), orario(10,4,53), n1);
    telefonata t2(orario(11,15,4), orario(11,22,53), n2);

    b1.Aggiungi_Telefonata(t1);
    b1.Aggiungi_Telefonata(t2);
    std::cout << b1;

    bolletta b2;
    b2 = b1;    // copia superficiale di oggetti => condivisione di memoria (copia di puntatori allo stesso indirizzo)
                // soluzione ridefinire l'operatore di assegnazione come deep copy => lenta e costosa
    b2.Togli_Telefonata(t1);
    std::cout << b1 << b2;
}
