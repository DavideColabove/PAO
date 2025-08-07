#include<iostream>
#include<vector>

using namespace std;

class Cliente{
    private:
        unsigned int currentTel;
        unsigned int nTel;
        unsigned int nSMS;
        double MB;
        static double costoMB;
    public:
        virtual double costoMeseCorrente() const =0;
        unsigned int getCurrentTel() const{
            return currentTel;
        }
        unsigned int getNTel() const{
            return nTel;
        }
        unsigned int getNSMS() const{
            return nSMS;
        }
        double getMB() const{
            return MB;
        }
        double getCostoMB() const{
            return costoMB;
        }
};

double Cliente::costoMB = 0.01;

class AlMinuto: public Cliente{
    private:
        static double scattoRisposta;
        static double costoTel;
        static double costoSMS;
    public:
        double costoMeseCorrente() const override{
            return ((scattoRisposta*getNTel()) + (costoTel*getCurrentTel()) + (costoSMS*getSMS()) + (getCostoMB()*getMB()));
        }
};

double AlMinuto::scattoRisposta = 0.15;
double AlMinuto::costoTel = 0.20;
double AlMinuto::costoSMS = 0.10;

class Abbonamento: public Cliente{
    private:
        double costoFisso;
        unsigned int sogliaTel;
        static double extraMinuti;
    public:
        double costoMeseCorrente() const override{
            return (costoFisso + getMB()*getCostoMB() + (getCurrentTel() > sogliaTel ? ((getCurrentTel()-sogliaTel)*extraMinuti) : 0));
        }
        unsigned int getSogliaTel() const{
            return sogliaTel;
        }
};

double Abbonamento::extraMinuti = 0.30;

class sedeMoon{
    private:
        vector<Cliente*> clienti;
    public:
        void aggiungiCliente(const Cliente& c){
            const Cliente* c1 = &c;
            clienti.push_back(const_cast<Cliente*>(p1));
        }
        double incassoMensileCorente(){
            double incasso = 0.0;
            for(auto it = clienti.begin(); it != clienti.end(); ++it){
                incasso += (*it)->costoMeseCorrente();
            }
            return incasso;
        }
        int numClientiAbbonatiOltreSoglia(){
            int oltreSoglia =0;
            for(auto it = clienti.begin(); it != clienti.end(); ++it){
                Abbonamento* ab = dynamic_cast<Abbonamento*>(*it);
                if(ab && (ab->getCurrentTel > ab->getSogliaTel()))
                    oltreSoglia++;
            }
            return oltreSoglia;
        }
        vector<AlMinuto> alMinutoSMS(int k){
            vector<AlMinuto> res;
            for(auto it = clienti.begin(); it != clienti.end(); ++it){
                AlMinuto* am = dynamic_cast<AlMinuto*>(*it);
                if(am && am->getNSMS() > k){
                    res.push_back(AlMinuto(*am));
                }
            }
            return res;
        }
};