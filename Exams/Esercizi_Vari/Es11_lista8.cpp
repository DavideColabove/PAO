#include<iostream>
#include<memory>
#include<vector>

using namespace std;

class Biglietto{
    protected:
        int distanza;
        static double prezzo_base;
    public:
        virtual double prezzo() const = 0;
        Biglietto(int d = 0): distanza(d){}
};

double Biglietto::prezzo_base = 0.1;

double Biglietto::prezzo() const{
    return distanza * prezzo_base;
}

class BigliettoPrimaClasse: public Biglietto{
    public:
        BigliettoPrimaClasse(int d = 0): Biglietto(d) {}
        virtual double prezzo() const{
            if(distanza < 100)
                return Biglietto::prezzo()*1.3;
            else
                return Biglietto::prezzo()*1.2;
        }
};

class BigliettoSecondaClasse: public Biglietto{
    private:
        bool prenotazione;
    public:
        BigliettoSecondaClasse(int d = 0, bool p = false): Biglietto(d), prenotazione(p){}
        virtual double prezzo() const{
            if(prenotazione)
                return 5+Biglietto::prezzo();
            else  
                return Biglietto::prezzo();
        }
        bool getPrenotazione() const{
            return prenotazione;
        }
};

class BigliettoSmart{
    private:
        shared_ptr<Biglietto> Bsmart;
    public:
        BigliettoSmart(Biglietto* b = nullptr): Bsmart(b) {}
        Biglietto* operator->() const{
            return Bsmart.get();
        }
        Biglietto& operator*() const{
            return *Bsmart;
        }
};

class TrenoPieno{
    private:
        bool PrimaClasse;
    public:
        TrenoPieno(bool c): PrimaClasse(c){
            if(PrimaClasse)
                cout << "Posti esauriti per Prima Classe" << endl;
            else
                cout << "Posti esauriti per Seconda Classe" << endl;
        }
};

class Treno{
    private:
        vector<BigliettoSmart> venduti;
        int max_prima;
        int max_seconda_pren;
        int count_prima;
        int count_seconda;
        int count_seconda_np;
        int ar[3];
    public:
        Treno(int mp =0, int msp =0, int cp =0, int cs =0, int csnp =0): max_prima(mp), max_seconda_pren(msp), count_prima(cp), count_seconda(cs), count_seconda_np(csnp){}
        int* bigliettiVenduti(){
            ar[0] = count_prima;
            ar[1] = count_seconda;
            ar[3] = count_seconda_np;
            return ar;
        }
        void vendiBiglietto(const Biglietto& b){
            if(const BigliettoPrimaClasse* prima = dynamic_cast<const BigliettoPrimaClasse*>(&b)){
                if(count_prima >= max_prima)
                    throw TrenoPieno(1);
                venduti.emplace_back(new BigliettoPrimaClasse(*prima));
                count_prima++;
            }
            if(const BigliettoSecondaClasse* seconda = dynamic_cast<const BigliettoSecondaClasse*>(&b)){
                if(seconda->getPrenotazione()){
                    if(count_seconda >= max_seconda_pren)
                        throw TrenoPieno(0);
                    venduti.emplace_back(new BigliettoSecondaClasse(*seconda));
                    count_seconda++;
                }
                venduti.emplace_back(new BigliettoSecondaClasse(*seconda));
                count_seconda_np++;
            }
        }
        double incasso() const{
            double totale = 0.0;
            for(const auto v:venduti){
                totale += v->prezzo();
            }
            return totale;
        }
};

int main() {
    // Creazione del treno con limiti specifici
    Treno treno(2, 2); // Massimo 2 posti Prima Classe, massimo 2 prenotati in Seconda Classe

    // Creazione dei biglietti
    BigliettoPrimaClasse bp1(50);   // Prima Classe, distanza 50
    BigliettoPrimaClasse bp2(150);  // Prima Classe, distanza 150
    BigliettoPrimaClasse bp3(80);   // Prima Classe, distanza 80 (per testare l'overflow)

    BigliettoSecondaClasse bs1(100, true);   // Seconda Classe, prenotato, distanza 100
    BigliettoSecondaClasse bs2(200, false);  // Seconda Classe, non prenotato, distanza 200
    BigliettoSecondaClasse bs3(150, true);   // Seconda Classe, prenotato, distanza 150 (per testare l'overflow)
    BigliettoSecondaClasse bs4(120, false);  // Seconda Classe, non prenotato, distanza 120

    try {
        // Vendita biglietti Prima Classe
        cout << "Vendita Biglietti Prima Classe:" << endl;
        treno.vendiBiglietto(bp1);
        treno.vendiBiglietto(bp2);

        // Questo dovrebbe generare un errore (Posti esauriti per Prima Classe)
        treno.vendiBiglietto(bp3);  
    } catch (const TrenoPieno& e) {
        cout << "Errore: treno pieno per Prima Classe!" << endl;
    }

    try {
        // Vendita biglietti Seconda Classe
        cout << "\nVendita Biglietti Seconda Classe:" << endl;
        treno.vendiBiglietto(bs1); // Prenotato
        treno.vendiBiglietto(bs2); // Non prenotato
        treno.vendiBiglietto(bs3); // Prenotato (dovrebbe generare errore)

        // Questo dovrebbe funzionare, non prenotato
        treno.vendiBiglietto(bs4);
    } catch (const TrenoPieno& e) {
        cout << "Errore: treno pieno per Seconda Classe!" << endl;
    }

    // Verifica dei biglietti venduti
    int* venduti = treno.bigliettiVenduti();
    cout << "\nBiglietti Venduti:" << endl;
    cout << "Biglietti Prima Classe venduti: " << venduti[0] << endl;
    cout << "Biglietti Seconda Classe prenotati venduti: " << venduti[1] << endl;
    cout << "Biglietti Seconda Classe non prenotati venduti: " << venduti[2] << endl;

    // Calcolo dell'incasso totale
    double incassoTotale = treno.incasso();
    cout << "\nIncasso Totale: " << incassoTotale << " euro" << endl;

    return 0;
}



