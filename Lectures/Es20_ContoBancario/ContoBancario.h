#ifndef CONTOBANCARIO_H
#define CONTOBANCARIO_H 

class ContoBancario{
    private:
        double saldo;   // nessun vincolo: puó andare in negativo
    public:
        ContoBancario(double x =0): saldo(x){}
        double deposita(double);
        double preleva(double);
        double getSaldo() const;
};

class ContoCorrente: public ContoBancario{
    private:
        static double spesaFissa;
    public:
        double deposita(double);
        double preleva(double);
        ContoCorrente(double x=0): ContoBancario(x){}
};
double ContoCorrente::spesaFissa = 1.0;

class ContoDiRisparmio: public ContoBancario{
    // saldo >= 0 invariante globale
    public:
        ContoDiRisparmio(double x=0): ContoBancario(x>=0 ? x : 0){}
        double preleva(double);
        // ContoBancario::deposita(double) non viene ridefinita
};

class ContoArancio: public ContoDiRisparmio{
    private:
        ContoCorrente& contoDiappoggio;
    public:
        ContoArancio(ContoCorrente& ap, double x=0): ContoDiRisparmio(x), contoDiappoggio(ap){}
        double deposita(double);
        double preleva(double);
};
#endif