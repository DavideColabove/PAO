#include "ContoBancario.h"

double ContoBancario::deposita(double d){
    return d>=0 ? saldo += d : saldo;
}

double ContoBancario::preleva(double p){
    return p>=0 ? saldo -= p : saldo;
}

double ContoBancario::getSaldo() const{
    return saldo;
}

double ContoCorrente::deposita(double d){
    return ContoBancario::deposita(d-spesaFissa);
}

double ContoCorrente::preleva(double p){
    return ContoBancario::preleva(p+spesaFissa);
}

double ContoDiRisparmio::preleva(double p){
    return ContoBancario::preleva(p > ContoBancario::getSaldo()? 0 : p);
}

double ContoArancio::deposita(double d){
    contoDiappoggio.preleva(d);
    return ContoDiRisparmio::deposita(d); 
}

double ContoArancio::preleva(double p){
    contoDiappoggio.deposita(p);
    return ContoDiRisparmio::preleva(p); 
}