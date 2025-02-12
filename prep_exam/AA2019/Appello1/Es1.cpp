#include<iostream>
#include<vector>
#include<list>

using namespace std;

enum Laurea{Informatica, Ingegneria, Altro};

class ICTStaff{
    private:
        double stipendio_fisso;
        Laurea l;
        bool magistrale;
    protected:
    double getStipendioFisso() const{
        return stipendio_fisso;
    }
    public:
        virtual ICTStaff* clone() const = 0;
        virtual double salary() const = 0;
        virtual ~ICTStaff() = default;
        Laurea getLaurea() const{
            return Laurea;
        }
        bool isMagistrale() const{
            return magistrale;
        }
};

class SwEngineer: public ICTStaff{
    private:
        bool sicurezza;
        static double extra;
    public:
        SwEngineer* clone() const override{
            return new SwEngineer(*this);
        }
        double salary() const override{
            return getStipendioFisso() + (isSecuritySW() ? extra  : 0);
        }
        bool isSecuritySW() const{
            return sicurezza;
        }
};

double SwEngineer::extra = 500.0;

class HwEngineer : public ICTStaff{
    private:
        int trasferte;
        double static extra_t;
    public:
        HwEngineer* clone() const override{
            return new HwEngineer(*this);
        }
        double salary() const override{
            return getStipendioFisso() + (extra_t * trasferte);
        }
};

double HwEngineer::extra_t = 300.0;

class Amazonia{
    private:
        class SmartP{
            public: 
                ICTStaff* ptr;
                SmartP(ICTStaff* p = nullptr): ptr(p != nullptr ? p->clone() : nullptr){}
                SmartP(const ICTStaff& ict): ptr(ict.ptr != nullptr ? (ict.ptr)->clone() : nullptr){}
                SmartP& operator=(const SmartP& s){
                    if(this != &s){
                        if(ptr){
                            delete ptr;
                            ptr = s.ptr ? nullptr : (s.ptr)->clone() : nullptr;
                        }
                    }
                    return *this;
                }
                ~SmartP(){
                    if(ptr)
                        delete ptr;
                }
                ICTStaff* operator->() const{
                    return ptr;
                }
                ICTStaff& operator*() const{
                    return *ptr;
                }
        };
        list<SmartP> specialisti;
    public:
        bool insert(SwEngineer* se, unsigned int k){
            int num = 0;
            SwEngineer* sw = nullptr;
            for(auto it = specialisti.begin(); it != specialisti.end() && num < k; ++it){
                sw = dynamic_cast<SwEngineer*>(it->ptr);
                if(sw && sw->isSecuritySW()) 
                    num++;
            }
            if(num < k){
                specialisti.push_back(se);
                return true;
            }
            return false;    
        }
        vector<HwEngineer> fire(double s){
            vector<HwEngineer> fired;
            HwEngineer* q = nullptr;
            for(auto it = specialisti.begin(); it != specialisti.end(); ++it){
                if((*it)->salary() > s){
                    q = dynamic_cast<HwEngineer*>(q->ptr);
                    if(q){
                        fired.push_back(*q);
                        delete it->ptr;
                        it = specialisti.erease(it);
                        --it;
                    }
                }
            }
            return fired;
        }
        vector<SwEngineer*> masterInf(){
            vector<SwEngineer*> master;
            SwEngineer* s = nullptr;
            for(auto it = specialisti.begin(); it != specialisti.end(); ++it){
                s = dynamic_cast<SwEngineer*>(*it);
                if(s && (*it)->isMagistrale() && (*it)->getLaurea == Informatica){
                    master.push_back(s);
                }
            }
            return master;
        }
};