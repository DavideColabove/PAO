#ifndef POLV_H
#define POLV_H

class punto{
    private:
        double x,y;
    public:
        punto(double a=0, double b=0): x(a) , y(b){}
        // metodo statico che calcola la distanza tra due punti
        static double lung(const punto&, const punto&);
};

class poligono{
    protected:
        unsigned int nvertici;
        punto* pp;  // array dinamico di punti
    public:
        // si assume v array ordinato degli n vertici
        poligono(unsigned int, const punto v[]);
        ~poligono();                            
        poligono(const poligono&);              
        poligono& operator=(const poligono&);   
        // contratto: ritorno il perimetro del poligono di invocazione
        virtual double perimetro() const;   // metodo virtuale
        virtual double area() const =0;     // metodo virtuale puro
};
#endif