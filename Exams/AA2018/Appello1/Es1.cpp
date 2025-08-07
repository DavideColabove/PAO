#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Anomalia{
    private:
        char codiceTipo;
        
    public:
        Anomalia(char c) : codiceTipo(c){}
        char getCodice() const {
            return codiceTipo;
        }
}; 

class Scheda{
    private:
        string numero;
        double credito;
        double costo_sms;
    public:
        virtual void telefonata(unsigned int) = 0;
        virtual void connessione(double) = 0;

        Scheda(string n = 0, double c = 0, double s = 0): numero(n), credito(c >= 0? c : 0), costo_sms(s){}
        virtual ~Scheda() {}

        string getNumero() const{
            return numero;
        }
        double getCredito() const{
            return credito;
        }
        double getCostoSms() const{
            return costo_sms;
        }

        void messaggioSMS(unsigned int k){
            if(credito >= (k*costo_sms))
                credito -= k*costo_sms;
            else
                throw Anomalia('s');
        }

        void addebita(double c){
            credito -= c;
        }
        virtual Scheda* clone() const =0 ;
};

class Mensile: public Scheda{
    private:
        const int sogliaTel;
        int currentTel;
        const double sogliaMB;
        double currentMB;

        const double costoMensile;
    public:
        Mensile(string n = 0, double c = 0, double s = 0.1, const int sT = 60000, int cT = 0, const double sM  = 2096.0, double cM = 0, const double costoMs = 10.0): 
            Scheda(n,c,s), sogliaTel(sT), currentTel(cT), sogliaMB(sM), currentMB(cM), costoMensile(costoMs){}

        void telefonata(unsigned int n) override{
            if((currentTel + n) <= sogliaTel)
                currentTel += n;
            else 
                throw Anomalia('v');
        }
        void connessione(double k) override{
            if((currentMB + k) <= sogliaMB)
                currentMB += k;
            else
                throw Anomalia('d');
        }
        Mensile* clone() const override{
            return new Mensile(*this);
        }
};

class Consumo: public Scheda{
    private:
        double costoSec;
        double costoMB;
    public:
        Consumo(string n = 0, double c = 0, double s = 0.2, double cS = 0.1, double cM = 0.1):
            Scheda(n,c,s), costoSec(cS), costoMB(cM){}
        void telefonata(unsigned int n) override{
            if ((costoSec*n) > getCredito())
                throw Anomalia('v');
            addebita(costoSec*n);
        }
        void connessione(double k) override{
            if((costoMB*k) > getCredito())
                throw Anomalia('d');
            addebita(costoMB*k);
        }
        Consumo* clone() const override{
            return new Consumo(*this);
        }
};

class P2{
    private:
        vector<Scheda*> vs;
    public:
        Consumo* cambioPiano(string n){
            for(auto it = vs.begin(); it != vs.end(); ++it){
                Mensile* m = dynamic_cast<Mensile*>(*it);
                if(((*it)->getNumero() == n) && m){
                    Consumo* c = new Consumo((*it)->getNumero(), (*it)->getCredito());
                    delete *it;
                    *it = c;
                    return c;
                }
            }
            return nullptr;
        }

        vector<Consumo> rimuoviConsumoZero(){
            vector<Consumo> res;
            for(auto it = vs.begin(); it != vs.end(); ++it){
                Consumo* c = dynamic_cast<Consumo*>(*it);
                if(c && (*it)->getCredito() == 0){
                    res.emplace_back((*it)->getNumero(), (*it)->getCredito());
                    delete c;
                    it = vs.erase(it);
                    --it;
                }
            }
            return res;
        }

        double contabilizza(){
            double tot_prima = 0.0;
            double tot_dopo = 0.0; 
            for(auto it = vs.begin(); it != vs.end(); ++it){
                if((*it)->getCredito() > 0){
                    tot_prima += (*it)->getCredito();
                    
                    (*it)->telefonata(1);
                    (*it)->messaggioSMS(1);
                    (*it)->connessione(1);

                    tot_dopo += (*it)->getCredito();
                }
            }
            return tot_prima-tot_dopo;
        }
};

int main() {
    try {
        // Creazione di oggetti Mensile e Consumo
        Mensile m1("12345", 20.0, 0.1);
        Consumo c1("67890", 10.0, 0.2, 0.1, 0.05);
        
        // Stampa delle informazioni iniziali
        cout << "Numero: " << m1.getNumero() << " | Credito: " << m1.getCredito() << endl;
        cout << "Numero: " << c1.getNumero() << " | Credito: " << c1.getCredito() << endl;
        
        // Test messaggi SMS
        m1.messaggioSMS(5);
        c1.messaggioSMS(5);
        cout << "Dopo 5 SMS -> Credito m1: " << m1.getCredito() << " | Credito c1: " << c1.getCredito() << endl;
        
        // Test chiamate
        m1.telefonata(300);
        c1.telefonata(50);
        cout << "Dopo chiamate -> Credito c1: " << c1.getCredito() << endl;
        
        // Test connessione dati
        m1.connessione(1000);
        c1.connessione(50);
        cout << "Dopo connessione -> Credito c1: " << c1.getCredito() << endl;
        
        // Test cambio piano
        P2 provider;
        provider.cambioPiano("12345");
        cout << "Cambio piano per 12345 eseguito." << endl;
        
    } catch (Anomalia &e) {
        cout << "Errore! Codice Anomalia: " << e.getCodice() << endl;
    }
    
    return 0;
}