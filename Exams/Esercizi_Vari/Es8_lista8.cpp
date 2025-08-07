#include<iostream>

using namespace std;

class Studente{
    private:
        string nome;
        string corso;
        int anni;
        int n_esami;
        int esami_s;
        double media;
    protected:
        Studente(string n, string c, int a, int nE, int eS, double m): nome(n), corso(c), anni(a >= 3 && a<= 6 ? a : 3), n_esami(nE >= 15 && nE <= 60 ? nE : 15), esami_s(eS >= 0 && eS <= n_esami ? eS : 1), media(m >= 18 && m <= 30? m : 18){}
    public:
        int getDurataCorso() const{
            return anni;
        }
        string getNome() const{
            return nome;
        }
        string getCorso(){
            return corso;
        }
        int getEsamiN() const{
            return n_esami;
        }
        int getEsamiS() const{
            return esami_s;
        }
        double getMedia() const{
            return media;
        }
        virtual ~Studente(){}
};

class StudenteIC: public Studente{
    private:
        int anno_corso;
        int reddito;
    public:
        StudenteIC(string n, string c, int a, int nE, int eS, double m, int ac, int r): Studente(n,c,a,nE,eS,m), anno_corso(ac >= 1 && ac <= getDurataCorso()? ac : 1), reddito(r){}
        int classeDiReddito() const{
            if(reddito <= 15000)
                return (anno_corso == getDurataCorso()) ? 0 : 1;
            else if(reddito <= 30000)
                return 2;
            else
                return 3;
        }
        int getReddito() const {
            return reddito;
        }
};

class StudenteFC: public Studente{
    private:
        int fuori_corso;
    public:
        StudenteFC(string n, string c, int a, int nE, int eS, double m, int fc): Studente(n,c,a,nE,eS,m), fuori_corso(fc >= 1 ? fc : 1){}
        bool bonus() const{
            if(getEsamiN()-getEsamiS() < 5)
                return true;
            else
                return false;
        }
        int getFuoriCorso() const{
            return fuori_corso;
        }
};

class Tasse{
    private:
        static int importo_base;
        static int penale;
        static int bonus_tassazione;
    public:
        static int calcolaTasse(Studente& s){
            if(StudenteIC* IC = dynamic_cast<StudenteIC*>(&s)){
                if(IC->getMedia() >= 28)
                    return (importo_base + penale*(IC->classeDiReddito())) - bonus_tassazione;
                else
                    return (importo_base + penale*(IC->classeDiReddito()));
            }
            else if(StudenteFC* FC = dynamic_cast<StudenteFC*>(&s)){
                if(FC->bonus())
                    return (importo_base + 3*penale*(FC->getFuoriCorso())) - bonus_tassazione;
                else   
                    return importo_base + 3*penale*(FC->getFuoriCorso());
            }
        }
};

int Tasse::importo_base = 1400;
int Tasse::penale = 200;
int Tasse::bonus_tassazione = 800;

int main() {
    // Crea gli oggetti Studente
    StudenteFC pippo("Pippo", "Matematica", 3, 20, 15, 25.0, 1);
    StudenteIC pluto("Pluto", "Informatica", 3, 30, 20, 27.5, 2, 15000);
    StudenteFC paperino("Paperino", "Fisica", 4, 25, 21, 28.5, 2);

    // Calcola e stampa le tasse
    cout << "Lo studente fuori corso di " << pippo.getCorso() << " " << pippo.getNome()
         << " deve pagare " << Tasse::calcolaTasse(pippo) << " euro di tasse." << endl;

    cout << "Lo studente in corso di " << pluto.getCorso() << " " << pluto.getNome()
         << " deve pagare " << Tasse::calcolaTasse(pluto) << " euro di tasse." << endl;

    cout << "Lo studente fuori corso di " << paperino.getCorso() << " " << paperino.getNome()
         << " deve pagare " << Tasse::calcolaTasse(paperino) << " euro di tasse." << endl;

    return 0;
}