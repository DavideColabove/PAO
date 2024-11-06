#include <iostream>

class Nodo{
    friend class Tree;
    private:
        Nodo(char c = '*', Nodo* s=0, Nodo* d=0): info(c), sx(s), dx(d) {}
        char info;
        Nodo* sx;
        Nodo* dx;
        //distruttore Nodo() vers. standard
};

class Tree{
    private:
        Nodo* root;
        static Nodo* copia(Nodo*);
        static void distruggi(Nodo*);
    public:
        Tree(): root(0) {std::cout << "Ct" << std::endl; }
        Tree(const Tree& t): root(copia(t.root)){ std::cout << "Cc" << std::endl;}
        Tree& operator=(const Tree&);
        ~Tree()  {distruggi(root);}
};

int main(){
    Tree t1, t2;
    t1 = t2;
    Tree t3 = t2;
}