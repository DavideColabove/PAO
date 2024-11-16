#include<iostream>

class orario{
    friend std::ostream& operator<<(std::ostream&, const orario&);
    public:
        orario(int = 0, int = 0, int = 0);
        int Ore() const;
        int Minuti() const;
        int Secondi() const;
        orario operator+(const orario&) const;
        bool operator==(const orario&) const;
        bool operator<(const orario&) const;
    private:
        int sec;
};

std::ostream& operator<<(std::ostream& os, const orario& o){
    return os << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
}