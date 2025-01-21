#include<iostream> 
#include<string>
#include<list>

using namespace std;

class Biglietto{
    private:
        string nome;
    public:
        Biglietto(string n): nome(n){} 
        virtual ~Biglietto(){}
};

class PostoNumerato: public Biglietto{
    private:
        int fila;
    public:
        PostoNumerato(string n, int f): Biglietto(n), fila(f <= 0 ? 1 : f){}
        int getFila() const{
            return fila;
        }
};


class PostoNonNumerato: public Biglietto{
    private:
        bool platea;
        bool ridotto;
    public:
        PostoNonNumerato(string n, bool p = false, bool r = false): Biglietto(n), platea(p), ridotto(r){}
        bool getPlatea() const{
            return platea;
        }
        bool getRidotto() const{
            return ridotto;
        }
};

class Spettacolo{
    private:
        const double p_base;
        const double p_add;
        const int max_n;
        const int max_f;
        int pn_venduti;
        list<Biglietto*> biglietti;
    public:
        Spettacolo(const double base, const double add, const double n, const double f, int v = 0): p_base(base), p_add(add), max_n(n), max_f(f){}
        ~Spettacolo(){
            for(auto elem:biglietti)
                delete elem;
        }
        void aggiungiBiglietto(Biglietto& b){
            if(const PostoNumerato *p = dynamic_cast<const PostoNumerato*>(&b)){
                if(pn_venduti < max_n){
                    biglietti.push_back(new PostoNumerato(*p));
                    pn_venduti++;
                    return;
                }
                else
                    throw runtime_error("Spettacolo pieno\n");
            }
            else{
                const PostoNonNumerato *pn = dynamic_cast<const PostoNonNumerato*>(&b);
                biglietti.push_back(new PostoNonNumerato(*pn));
                return;
            }
        }
        double prezzo(const Biglietto& b) const{
            if(const PostoNumerato *p = dynamic_cast<const PostoNumerato*>(&b)){
                if(p->getFila() < max_f){
                    return 2*p_base+2*p_add;
                }
                else    
                    return 2*p_add;
            }
            else{
                const PostoNonNumerato *pnn = dynamic_cast<const PostoNonNumerato*>(&b);
                if(pnn->getPlatea()){
                    if(pnn->getRidotto())
                        return p_base + p_add - p_add/2;
                    else
                        return p_base + p_add;
                }
                else{
                    if(pnn->getRidotto())
                        return p_base - p_add/2;
                    else
                        return p_base;
                }
            }
        }
        double incasso() const{
            double s = 0;
            for(auto elem:biglietti){
                s += prezzo(*elem);
            }
            return s;
        } 
};

int main() {
    try {
        // Creazione di uno spettacolo
        Spettacolo s(10.0, 5.0, 2, 5); // Prezzo base = 10.0, aggiuntivo = 5.0, max_n = 2, max_f = 5

        // Creazione di biglietti
        PostoNumerato b1("Posto1", 4); // Fila 4
        PostoNumerato b2("Posto2", 6); // Fila 6
        PostoNonNumerato b3("Posto3", true, false); // Platea, non ridotto
        PostoNonNumerato b4("Posto4", false, true); // Non platea, ridotto

        // Aggiunta biglietti allo spettacolo
        s.aggiungiBiglietto(b1);
        s.aggiungiBiglietto(b2);
        s.aggiungiBiglietto(b3);
        s.aggiungiBiglietto(b4);

        // Calcolo e stampa dell'incasso totale
        cout << "Incasso totale: " << s.incasso() << " euro" << endl;
    } catch (const exception& e) {
        cerr << "Errore: " << e.what() << endl;
    }

    return 0;
}