#include<iostream>
#include<vector>
#include<list>

using namespace std;

class SIM{
    private:
        unsigned int sec;
        unsigned int MB;
    protected:
        static double costo_c;
        static double costo_d;
    public:
        SIM(unsigned int s =0, unsigned int m =0): sec(s), MB(m){}
        virtual double costoMeseCorrente() const = 0;
        unsigned int getSec() const{
            return sec;
        }
        unsigned int getMB() const{
            return MB;
        }
};

double SIM::costo_c = 0.03;
double SIM::costo_d = 0.04;

class Tel: public SIM{
    private:
        double base;
    public:
        Tel(unsigned int s, unsigned int m, double b): SIM(s,m), base(b){}
        double costoMeseCorrente() const{
            return base + getMB()*costo_d;
        }
        double getBase() const{
            return base;
        }
};

class Dati: public SIM{
    protected:
        static double costo_abb;
    public:
        Dati(unsigned int s, unsigned int m): SIM(s,m){}
        double costoMeseCorrente() const{
            return costo_abb + costo_c*getSec();
        }
};

double Dati::costo_abb = 13.99;

class PAO{
    private:
        list<const SIM*> sim;
    public:
        vector<Dati> fun1(double x){
            vector<Dati> res;
            for(list<const SIM*>::const_iterator cit = sim.begin(); cit != sim.end(); ++cit){
                const Dati* d = dynamic_cast<const Dati*>(*cit);
                if(d && d->getMB() >= x)
                    res.push_back(*d);
            }
            return res;
        }
        list<Tel*> fun2(){
            list<Tel*> res;
            for(list<const SIM*>::const_iterator cit = sim.begin(); cit != sim.end(); ++cit){
                const Tel* t  = dynamic_cast<const Tel*>(*cit);
                if(t && t->costoMeseCorrente() > 2*t->getBase())
                    res.push_back(const_cast<Tel*>(t));
            }
            return res;
        }
};