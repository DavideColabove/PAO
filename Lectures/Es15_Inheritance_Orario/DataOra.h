#include<iostream>

enum Giorno{lun, mar, mer, gio, ven, sab, dom};

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

class dataorasett: public dataora{
    private:
        Giorno giornosettimana;
    public:
        Giorno GiornoSettimana() const;
};