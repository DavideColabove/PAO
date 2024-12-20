#include<iostream>
using std::cout;

class C {
    public:
        int x;
        C(int k=5): x(k) {};
        C* m(C& c) {
            if((c.x != 5) && (x==5)) return &c;
            return this;
        }
};

main() {
    C a, b(2), c(a);
    cout << (b.m(b))->x << ' ' << (a.m(a))->x << ' ' << (b.m(c))->x
        << ' ' << c.m(a) << ' ' << c.m(c);
}