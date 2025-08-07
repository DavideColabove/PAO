#include <iostream>

class Raz{
    private:
        int num, den;   // INV: den != 0
    public:
        //conversione int x => Raz(x,1) 
        explicit Raz(int n = 0, int d = 1);
        Raz inverso() const;
        operator double() const;
        operator+(const Raz&) const;
        operator*(const Raz&) const;
        bool operator==(const Raz& r) const;
        Raz& operator++();   //forma prefissa, ritorna il valore per riferimento 
        Raz operator++(int);   //forma postfissa, ritorna il valore di x prima dell'incremento
        static Raz unTerzo();
};

std::ostream& operator<<(std::ostream&, const Raz&);