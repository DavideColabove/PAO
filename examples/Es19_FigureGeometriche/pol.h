#ifndef POL_H
#define POL_H

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
        ~poligono();                            // distruttore profondo
        poligono(const poligono&);              // copia profonda
        poligono& operator=(const poligono&);   // assegnazione profonda
        double perimetro() const;   // ritorna il perimetro del poligono
};
#endif