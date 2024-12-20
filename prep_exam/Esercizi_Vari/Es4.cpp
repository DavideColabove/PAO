#include<iostream>
#include<string>
 
using std::string; using std::cout;
 
class C {
    private:
        int d;
    public:
        C(string s=""): d(s.size()) {}
        explicit C(int n): d(n) {}
        operator int() {return d;}
        C operator+(C x) {return C(d+x.d);}
};

main() {
 C a, b("pippo"), c(3);
 cout << a << ' ' << 1+b << ' ' << c+4 << ' ' << c+b;
}