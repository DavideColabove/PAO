#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Workout{
    private:
        unsigned int durata;
    public:
        Workout(int d=0): durata(d){}
        Workout(const Workout& w): durata(w.durata){}
        virtual ~Workout(){}
        virtual Workout* clone() const = 0;
        virtual int calorie() const = 0;
        unsigned int getDurata() const{
            return durata;
        }
};

class Corsa: public Workout{
    private:
        double km;
    public:
        Corsa(int d =0, double k = 0): Workout(d), km(k){}
        Corsa(const Corsa& c): Workout(c), km(c.km){}
        ~Corsa() {}
        Corsa* clone() const override{
            return new Corsa(*this);
        }
        int calorie() const override{
            return (500 * (km*km))/getDurata();
        }
};

class Nuoto: public Workout{
    private:
        unsigned int vasche;
    public:
        Nuoto(int d=0, int v=0): Workout(d), vasche(v){}
        Nuoto(const Nuoto& n): Workout(n), vasche(n.vasche){}
        ~Nuoto(){}
        unsigned int getVasche() const {
            return vasche;
        }
};

class StileLibero: public Nuoto{
    public:
        StileLibero* clone() const override{
            return new StileLibero(*this);
        }
        int calorie() const override{
            return (getDurata() < 10 ? 35*getVasche() : 40*getVasche());
        }
};

class Dorso: public Nuoto{
    public:
        Dorso* clone() const override{
            return new Dorso(*this);
        }
        int calorie() const override{
            return (getDurata() < 15 ? 30*getVasche() : 45*getVasche());
        }
};

class Rana: public Nuoto{
    public:
        Rana* clone() const override{
            return new Rana(*this);
        }
        int calorie() const override{
            return 25*getVasche();
        }
};

class InForma{
    private:
        vector<const Workout*> wt;
    public:
        vector<Nuoto*> vasche(int k){
            vector<Nuoto*> res;
            for(auto it = wt.begin(); it != wt.end(); ++it){
                Nuoto* n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it));
                if(n->getVasche() > k){
                    res.push_back(n->clone());
                }
            }
            return res;
        }
        return res;
        vector<Workout*> calorie(int k){
            vector<Workout*> res;
            for(auto it = wt.begin(); it != wt.end(); ++it){
                Workout* w = const_cast<Workout*>(*it);
                if((w->calorie() > k) && !(dynamic_cast<Rana*>(w))){
                    res.push_back(w->clone());
                }
            }
            return res;
        }
        void removeNuoto(){
            int MAX_calorie= 0;
            for(auto it = wt.begin(); it != wt.end(); ++it){
                Nuoto* n = dynamic_cast<Nuoto*>(const_cast<Workout*>(*it));
                if(n){
                    if(n->calorie() > MAX_calorie)
                        MAX_calorie = n->calorie();
                    if(n->calorie() == MAX_calorie)
                        wt.erase(it);
                }
                throw string("NoRemove");
            }
        }
};





