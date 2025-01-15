#include<iostream>

using namespace std;

class ContoBancario{
    protected:
        int saldo;
    public:
        ContoBancario(int s = 0): saldo(s){}
        virtual int deposita(int d){
            return saldo += d;
        }
        virtual int preleva(int d){
            return saldo -= d;
        }
        int getSaldo(){
            return saldo;
        }
};

class ContoCorrente: public ContoBancario{
    private:
        static int spesa_fissa;
    public:
        ContoCorrente(int s = 0): ContoBancario(s){}
        int deposita(int d) override{
            return ContoBancario::deposita(d-spesa_fissa);
        }
        int preleva(int d) override{
            return ContoBancario::preleva(d+spesa_fissa);
        }
};

int ContoCorrente::spesa_fissa = 2;

class ContoDiRisparmio: public ContoBancario{
    public:
        ContoDiRisparmio(int s=0): ContoBancario(s >= 0 ? s : 0){} 
        int preleva(int d) override{
            if(d<=saldo)
                return ContoBancario::preleva(d);
            else
                throw runtime_error("Saldo insufficiente per il prelievo");
        }
};

class ContoArancio: public ContoDiRisparmio{
    private:
        ContoCorrente& c;
    public:
        ContoArancio(ContoCorrente& conto, int s = 0): c(conto), ContoDiRisparmio(s){}
        int deposita(int d) final override{
            c.preleva(d);
            return ContoDiRisparmio::deposita(d);
        }
        int preleva(int d) final override{
            if(d<=this->getSaldo()){
                c.deposita(d);
                return ContoDiRisparmio::preleva(d);
            }
            throw runtime_error("Saldo insufficiente per il prelievo");
        }
};


#include <iostream>
#include <stdexcept>

int main() {
    try {
        // Creazione di un conto corrente con un saldo iniziale di 100
        ContoCorrente cc(100);
        std::cout << "Saldo iniziale conto corrente: " << cc.getSaldo() << std::endl;

        // Operazioni sul conto corrente
        cc.deposita(50);
        std::cout << "Saldo dopo deposito di 50 (meno spesa fissa): " << cc.getSaldo() << std::endl;

        cc.preleva(30);
        std::cout << "Saldo dopo prelievo di 30 (piu' spesa fissa): " << cc.getSaldo() << std::endl;

        // Creazione di un conto di risparmio con un saldo iniziale di 200
        ContoDiRisparmio cr(200);
        std::cout << "Saldo iniziale conto di risparmio: " << cr.getSaldo() << std::endl;

        // Operazioni sul conto di risparmio
        cr.deposita(100);
        std::cout << "Saldo dopo deposito di 100: " << cr.getSaldo() << std::endl;

        try {
            cr.preleva(350); // Questo dovrebbe lanciare un'eccezione
        } catch (const std::runtime_error& e) {
            std::cout << "Errore: " << e.what() << std::endl;
        }

        cr.preleva(50);
        std::cout << "Saldo dopo prelievo di 50: " << cr.getSaldo() << std::endl;

        // Creazione di un conto arancio legato al conto corrente
        ContoArancio ca(cc, 300);
        std::cout << "Saldo iniziale conto arancio: " << ca.getSaldo() << std::endl;

        // Operazioni sul conto arancio
        ca.deposita(50);
        std::cout << "Saldo conto arancio dopo deposito di 50: " << ca.getSaldo() << std::endl;
        std::cout << "Saldo conto corrente dopo deposito su conto arancio: " << cc.getSaldo() << std::endl;

        ca.preleva(100);
        std::cout << "Saldo conto arancio dopo prelievo di 100: " << ca.getSaldo() << std::endl;
        std::cout << "Saldo conto corrente dopo prelievo da conto arancio: " << cc.getSaldo() << std::endl;

        try {
            ca.preleva(500); // Questo dovrebbe fallire poiché il saldo non è sufficiente
        } catch (const std::runtime_error& e) {
            std::cout << "Errore: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Eccezione non gestita: " << e.what() << std::endl;
    }

    return 0;
}

