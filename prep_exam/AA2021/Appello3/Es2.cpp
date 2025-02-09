#include<iostream>
#include<list>

using namespace std;

class Exc{
    private:
        unsigned int M;
    public: 
        Exc(unsigned int max): M(max){}
};

class Abbonato{
    private:
        unsigned int traffico;
        unsigned int oret;
    protected:
        static const double costo_base; 
        static const double costo_extra; 
    public:
        Abbonato(unsigned int t, unsigned int o): traffico(t), oret(o){}
        virtual double costoMeseCorrente() const = 0;
        unsigned int getTraffico() const{
            return traffico;
        }
        unsigned int getOret() const{
            return oret;
        }
};

const double Abbonato::costo_base = 15;
const double Abbonato::costo_extra = 5;

class AbbonatoTraffico: public Abbonato{
    private:
        unsigned int soglia_d;
    public: 
        AbbonatoTraffico(unsigned int t, unsigned int o, unsigned int sd): Abbonato(t, o), soglia_d(sd){}
        double costoMeseCorrente() const override{
            if(getTraffico() <= soglia_d*1024)
                return costo_base;
            return costo_base + costo_extra*(getTraffico() - soglia_d*1024)/1024;
        }
};

class AbbonatoTempo: public Abbonato{
    private:
        unsigned int soglia_t;
    public:
        AbbonatoTempo(unsigned int t, unsigned int o, unsigned int st): Abbonato(t, o), soglia_t(st){}
        double costoMeseCorrente() const override{
            if(getOret() <= soglia_t)
                return costo_base;
            return costo_base + costo_extra*(getOret() - soglia_t);
        }
        unsigned int getSogliaT() const{
            return soglia_t;
        }
};

class FilialeWI{
    private:
        list<const Abbonato*> abbonati;
        unsigned int max_abbonati;
    public:
        FilialeWI(unsigned int ma): max_abbonati(ma){}
        void aggiungAbbonato(const Abbonato& a){
            if(abbonati.size() >= max_abbonati)
                throw Exc(max_abbonati);
            else
                abbonati.push_back(&a);
        }
        list<const Abbonato*> abbonatiOltreSoglia(){
            list<const Abbonato*> res;
            for(auto cit = abbonati.begin(); cit != abbonati.end(); ++cit){
                const AbbonatoTraffico* ATF = dynamic_cast<const AbbonatoTraffico*>(*cit);
                const AbbonatoTempo* ATP = dynamic_cast<const AbbonatoTempo*>(*cit);
                if(ATP && (ATP->costoMeseCorrente() > 50 || ATP->getOret() > ATP->getSogliaT()))
                    res.push_back(ATP);
                if(ATF && ATF->costoMeseCorrente() > 50)
                    res.push_back(ATF);
            }
            return res;
        }
}