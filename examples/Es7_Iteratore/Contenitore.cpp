class contenitore{
    private:
        class nodo{
            public:
                int info;
                nodo* next;
                nodo(int x, nodo* p): info(x), next(p){}
        }
        nodo* first;
    public:
        class iteratore{
            friend class contenitore;   //concedo alla classe contenitore il diritto di accedere agli iteratori
            private:
                contenitore::nodo* punt;
            public:
            bool operator==(const iteratore& i) const{ return punt == i.punt;}
            bool operator!=(const iteratore& i) const{ return punt != i.punt;}
            iteratore& operator++(){ if(punt) punt = punt->next; return *this;} // prefisso
        };
        iteratore begin() const;    //costruttore di iteratore 
        iteratore end() const;      //costruttore di iteratore
        int& operator[](const iteratore&) const;
        contenitore(): first(nullptr){}
        void aggiungi_in_testa(int x) {first = new nodo(x, first);
        int somma_elementi(const contentirore&);
};

contenitore::iteratore contenitore::begin() const{
    iteratore aux;  //costruttore di default standard
    aux.punt = first;   // per amicizia ho accesso a punt
    return aux;
}

contenitore::iteratore contenitore::end() const{
    iteratore aux;
    aux.punt = nullptr;
    return aux;
}

int& contenitore::operator[](const iteratore& it) const{
    return it.punt->info;   // per amicizia, nessun controllo su it.punt
}

int contenitore::somma_elementi(const contenitore& c){
    int somma = 0;
    for(contenitore::iteratore it = c.begin(); it != c.end(); ++it)
        somma += c[it];
    return somma;
}