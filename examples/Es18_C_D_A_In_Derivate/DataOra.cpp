
class dataora : public orario{
    private:
        int giorno;
        int mese;
        int anno;
    public:
        dataora::dataora(int a, int me, int g, int o, int m, int s) : orario(o,m,s), anno(a), mese(me), giorno(g) {}
}

int main(){
    dataora d(2020, 11, 17, 11, 55, 13);
    cout << d.Ore();        // stampa: 11
    cout << d.Giorno();     // stampa: 17
}
