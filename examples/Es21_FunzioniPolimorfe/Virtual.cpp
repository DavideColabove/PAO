class orario{
    virtual void Stampa();  //metodo virtuale
    ...
};

void G(const orario& o){
    o.Stampa(); // chiamata polimorfa
}

int main(){
    dataora d;
    orario* p = &d;
    p->Stampa();    // chiamata polimorfa
}