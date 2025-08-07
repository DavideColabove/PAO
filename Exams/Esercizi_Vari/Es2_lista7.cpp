#include<iostream>

using namespace std;

class A {public: virtual ~A() {} };
class B: virtual public A {};
class C: virtual public A {};
class D: virtual public A {};
class E: virtual public C {};
class F: virtual public C {};
class G: public B, public E, public F {};
B b; D d; E e; F f; G g; A* pa; B* pb; C* pc; F* pf;

//main() {pc = &e; cout << (dynamic_cast<D*> (pc) ? "OK" : "NO");}
//main() {cout << (dynamic_cast<B*> (&g) ? "OK" : "NO");}
//main() {pa = &f; cout << (dynamic_cast<C*> (pa) ? "OK" : "NO");}
//main() {pb = &b; cout << (dynamic_cast<G*> (pb) ? "OK" : "NO");}
//main() {cout << (dynamic_cast<D*> (&d) ? "OK" : "NO");}
//main() {pf = &g; cout << (dynamic_cast<E*> (pf) ? "OK" : "NO");}
//main() {pf = &f; cout << (dynamic_cast<E*> (pf) ? "OK" : "NO");}
