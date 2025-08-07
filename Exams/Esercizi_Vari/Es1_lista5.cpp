#include<iostream>
#include<vector>

using namespace std;

class Auto{
    protected:
        int hp;
        static int tassa_hp;
    public:
        virtual int tassa() const{
            return hp * tassa_hp;
        }
        Auto(int cv = 0): hp(cv){}
        ~Auto(){ cout << "Distruttore Auto invocato\n";}
};

int Auto::tassa_hp = 5;

class Diesel: public Auto{
    private:
        static int add_fiscale;
    public:
        Diesel(int cv =0): Auto(cv){}
        int tassa() const override{
            return Auto::tassa() + add_fiscale;
        }
};

int Diesel::add_fiscale = 100;

class Benzina: public Auto{
    private:
        bool euro4;
        static int bonus_fiscale;
    public:
        Benzina(int cv = 0, bool euro =true): Auto(cv), euro4(euro){}
        int tassa() const final override{
            if(euro4)
                return Auto::tassa() - bonus_fiscale;
            else
                return Auto::tassa();
        }
};

int Benzina::bonus_fiscale = 50;

class ACI{
    private:
        vector<Auto*> ListaAuto;
    public:
        void aggiungiAuto (const Auto& a){
            if(const Benzina* b = dynamic_cast<const Benzina*>(&a))
                ListaAuto.push_back(new Benzina (*b));
            else if(const Diesel* d = dynamic_cast<const Diesel*>(&a))
                ListaAuto.push_back(new Diesel (*d));
            else
                throw runtime_error("Tipo non supportato");
        }
        int incassaBolli() const{
            int bolli = 0;
            for(auto it = ListaAuto.begin(); it != ListaAuto.end(); ++it){
                bolli += (*it)->tassa();
            }
            return bolli;
        }
};

int main() {
    try {
        // Creazione di oggetti AUTO
        Benzina b1(50, false); // Auto a benzina non Euro 4
        Benzina b2(80, true);  // Auto a benzina Euro 4
        Diesel d1(100);         // Auto diesel
        Diesel d2(60);         // Altra auto diesel

        // Creazione dell'oggetto ACI
        ACI agenziaACI;

        // Aggiunta delle auto
        agenziaACI.aggiungiAuto(b1);
        agenziaACI.aggiungiAuto(b2);
        agenziaACI.aggiungiAuto(d1);
        agenziaACI.aggiungiAuto(d2);

        // Calcolo e stampa dell'incasso totale dei bolli
        cout << "Totale bolli incassati: " << agenziaACI.incassaBolli() << " euro"  << endl;

    } catch (const exception& e) {
        cerr << "Errore: " << e.what() << endl;
    }

    return 0;
}

