#include<iostream>

class IntMod{
    friend std::ostream& operator<<(std::ostream&, const IntMod&);
    private:
        static int modulo;
        int value;
    public: 
        static void set_modulo(int m);
        static int get_modulo();
        IntMod(int v=0): value(v) {
            if(value<0) value*-1;
            value = value%modulo;
        }
        IntMod operator+(const IntMod& add);
        IntMod operator*(const IntMod& fat);
        operator int() const { return value;}
        int operator+(const int& add);
        int operator*(const int& fat);        
};

int IntMod::modulo = 1;

void IntMod::set_modulo(int m){
    if(m <= 0) std::cerr << "Modulo minore o uguale a 0";
    modulo = m;
}

int IntMod::get_modulo(){
    return modulo;
}

IntMod IntMod::operator+(const IntMod& add){
    return IntMod(((*this).value + add.value)%modulo);
}

IntMod IntMod::operator*(const IntMod& fat){
    return IntMod(((*this).value * fat.value)%modulo);
}

int IntMod::operator+(const int &add){
    return (value + add);
}

int IntMod::operator*(const int &fat){
    return (value * fat);
}

std::ostream& operator<<(std::ostream& os, const IntMod& obj){
    return os << "| " << obj.value << " | mod " << IntMod::get_modulo() << std::endl;
}

int main(){
    IntMod::set_modulo(2);
    IntMod nove = 9;
    IntMod cinque = 5;
    int x = 3;
    std::cout << nove + cinque << std::endl;
    std::cout << nove * cinque << std::endl;
    std::cout << x + cinque << std::endl;
    std::cout << cinque + x << std::endl;
    std::cout << x * cinque << std::endl;
}

