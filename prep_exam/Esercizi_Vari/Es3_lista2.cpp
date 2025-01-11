class Nodo{
    friend class Tree;
    private:
        Nodo(string st="***", Nodo* s=0, Nodo* d=0) : info(st), sx(s), dx(d){}
        string info;
        Nodo* sx;
        Nodo* dx;   
};

class Tree{
    public:
        Tree() : radice(0){}
        Tree(const Tree& t) : radice(copia(t.radice)) {} // copia profonda
    private:
        Nodo* radice;
        Nodo* copia(Nodo* r){
            if(!r)
                return nullptr; //caso base
            else
                return new Nodo(r->info,copia(r->sx),copia(r->dx)); //passo induttivo
        }
};