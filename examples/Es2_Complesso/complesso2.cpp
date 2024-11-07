#include<cmath>

class complesso_pol{
    private:
        double mod, arg;
    public:
        void inizializza(double, double);
        double reale();
        double immag();
};

void complesso_pol::inizializza(double r, double i){
    mod = sqrt(r*r + i*i);
    arg = atan(i/r);
}

double complesso_pol::reale(){
    return mod*cos(arg);
}   

double complesso_pol::immag(){
    return mod*sin(arg);
}