#include<iostream>

class dataora: public orario{
    private:
        int giorno;
        int mese; 
        int anno;
    public:
        int Giorno() const;
        int Mese() const;
        int Anno() const;
}