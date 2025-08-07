#include <iostream>

using std::cout;
using std::endl;

class Z {
public:
  Z(int x) {}
};

class A {
public:
  void f(int) { cout << "A::f(int) "; f(true); }
  virtual void f(bool) { cout << "A::f(bool) "; }
  virtual A *f(Z) { cout << "A::f(Z) "; f(2); return this; }
  A() { cout << "A() "; }
};

class B : virtual public A {
public:
  void f(const bool &) { cout << "B::f(const bool&) "; }
  void f(const int &) { cout << "B::f(const int&) "; }
  virtual B *f(Z) { cout << "B::f(Z) "; return this; }
  virtual ~B() { cout << "~B "; }
  B() { cout << "B() "; }
};

class C : virtual public A {
public:
  C *f(Z) { cout << "C::f(Z) "; return this; }
  C() { cout << "C() "; }
};

class D : virtual public A {
public:
  virtual void f(bool) const { cout << "D::f(bool) "; }
  A* f(Z) { cout << "D::f(Z) "; return this; }
  ~D() { cout << "~D "; }
  D() { cout << "D() "; }
};

class E : public C {
public:
  C *f(Z) { cout << "E::f(Z) "; return this; }
  ~E() { cout << "~E "; }
  E() { cout << "E() "; }
};

class F : public B, public E, public D {
public:
  void f(bool) { cout << "F::f(bool) "; }
  F* f(Z) { cout << "F::f(Z) "; return this; }
  F() { cout << "F() "; }
  ~F() { cout << "~F ";}
};

B *pb = new B;
C *pc = new C;
D *pd = new D;
E *pe = new E;
F *pf = new F;
B *pb1 = new F;
A *pa1 = pb, *pa2 = pc, *pa3 = pd, *pa4 = pe, *pa5 = pf;

int main() {
  cout << endl;

  cout << "1: "; pa3->f(3); cout << endl;
  cout << "2: "; pa5->f(3); cout << endl;
  cout << "3: "; pb1->f(true); cout << endl;
  cout << "4: "; pa4->f(true); cout << endl;
  cout << "5: "; pa2->f(Z(2)); cout << endl;
  cout << "6: "; pa5->f(Z(2)); cout << endl;
  cout << "7: "; (dynamic_cast<E*>(pa4))->f(Z(2)); cout << endl;
  cout << "8: "; (dynamic_cast<C*>(pa5))->f(Z(2)); cout << endl;
  cout << "9: "; pb->f(3); cout << endl;
  cout << "10: "; pc->f(3); cout << endl;
  cout << "11: "; (pa4->f(Z(3)))->f(4); cout << endl;
  cout << "12: "; (pc->f(Z(3)))->f(4); cout << endl;
  cout << "13: "; E* puntE = new F; cout << endl;
  cout << "14: "; A* puntA = new F; cout << endl;
  cout << "15: "; delete pa5; cout << endl;
  cout << "16: "; delete pb1; cout << endl;
}

/*
Stampa:
1: A::f(int) A::f(bool) 
2: A::f(int) F::f(bool) 
3: B::f(const bool&) 
4: A::f(bool) 
5: C::f(Z) 
6: F::f(Z) 
7: E::f(Z) 
8: F::f(Z) 
9: B::f(const int&) 
10: C::f(Z) 
11: E::f(Z) A::f(int) A::f(bool) 
12: C::f(Z) C::f(Z) 
13: A() B() C() E() D() F() 
14: A() B() C() E() D() F() 
15: 
16: ~F ~D ~E ~B 
*/