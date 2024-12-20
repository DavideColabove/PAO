#include <iostream>
#include <string>
using namespace std;

class B {
public:
    string s;

    B(char x = 'a', char y = 'b') {
        s += x;
        s += y;
        cout << "B012 ";
    }

    B(const B& obj) : s(obj.s) {
        cout << "Bc ";
    }
};

class C {
private:
    B t;
    B* p;
    B u;

public:
    string s;

    C(char x = 'c', B y = B('d')) : u(y), s(y.s) {
        s += x;
        cout << s[s.size() - 2] << " C012 ";
    }
};

B F(B x, C& y) {
    (x.s) += (y.s)[0];
    return x;
}

int main() {
    B b('e');
    cout << "UNO\n";

    C c1('f', b);
    cout << "DUE\n";

    C c2;
    cout << "TRE\n";

    B b2 = F(b, c2);
    cout << "QUATTRO\n";

    cout << b2.s << " CINQUE\n";

    return 0;
}