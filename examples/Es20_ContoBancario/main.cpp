#include "ContoBancario.h"
#include <iostream>

int main(){
    ContoCorrente cc(2000);
    ContoArancio ca(cc, 1500);
    ca.deposita(350);
    ca.preleva(400);
    cc.preleva(150);
    std::cout << cc.getSaldo() << std::endl;    // stampa: 1897
    std::cout << ca.getSaldo() << std::endl;    // stampa: 1450
}