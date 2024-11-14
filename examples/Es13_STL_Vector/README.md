# Descrizione

Spiegazione Vector in STL

## Teoria

Vector é un template di classe con due parametri di tipo ed un parametro default per il secondo parametro di tipo 

```cpp
template <class _Tp, class _Alloc = __STL_DEFAULT_ALLOCATOR(_Tp)>
class vector : protected _Vector_base<_Tp, _Alloc>{
    ...;
}
```

Esistono due modi di usare un vector:
Lo stile array ereditato da C e lo stile STL piú consono a C++

```cpp
int a[10];
vector<int> v(10)
```
Per accedere agli elementi di un vector si usa l'operatore di indicizzazione operator[]

```cpp
int n = 5;
vector<int> v(n);       //costruzione di copia
int a[n] = {2,4,5,2,-2};
for (int i = 0; i < n; ++i)
    v[i] = a[i] + 1;
```
Il metodo size() ritrona il numero di elementi contenuti nel vector

Il metodo capacity() ritorna invece la capacitá del vector

Il costruttore vector(size_type) costruisce un vector i cui elementi sono izializzati con il costruttore di default

Il costruttore vector(size_type n, const T& t) permetti di specificare un valore iniziale t da cui sono costruiti di copia tutti gli elementi 

```cpp
vector<int> ivec(10,-1);
```
I metodi fondamentali di utilizzo di un vettore
std::vector

1. void push_back(const T&) : inserimento in coda, richiede un T& passato per riferimento costante (l'elemento da inserire in coda), cella costruita di copia 

2. void pop_back() : rimozione dalla coda, lo rimuove e basta senza ritornarlo

3. T& front() : ritorna primo elemento, con possibilitá di fare modifiche quindi mi ritorna un T&

4. T& back() : ritorna ultimo elemento, con possibilitá di fare modifiche quindi mi ritorna un T&

5. iterator begin() : iteratore che punta al primo elemento

6. iterator end() : iteratore che putna al past-the-end

## Iteratori nei contenitori

Ad ogni classe contenitore C della STL sono associati due tipi iteratore

```cpp
C::iterator

C::const_iterator
```
Si usa iterator quando si necessita un accesso in lettura e scrittua agli elementi
Si usa const_iterator se basta un accesso come rvalue (in sola lettura)

Di conseguenza su un vector<T> posso chiamare begin() e end()
Al contrario, su un const vector<T> posso chiamare SOLO begin() const e end() const : ritornano un const_iterator

Su ogni tipo iteratore (anche const) di qualche istanza di contenitore Cont<Tipo>::[const_]iterator sono sempre disponibili le seguenti funzionalitá: 

```cpp
#include <vector>
Cont<Tipo> x;
Cont<Tipo>::[const_]iterator i;

x.begin();  // iteratore che punta al primo elemento

x.end();    // puntatrore all'(ultimo +1) elemento 

*i;         // elemento puntato da i

i++; ++i;   // puntatore all'elemento successivo: se i punta all'ultimo elemento di x allora ++i == x.end()

i--; --i;   // puntatore all'elemento precedente: se i punta al primo elemento di x allora i-- é indefinito (x.begin()-1)
            // (x.end())-- punta all'ultimo elemento
``` 

É possibile inizializzare un vector con un segmento di un array o di un vector tramite il template di costruttore:

template<class InputIterator>
vector(InputIterator, InputIterator)

```cpp
int main(){
    int ia[20];
    vector<int> iv(ia, ia+6);   // primo incluso, ultimo escluso
    cout << iv.size() << endl;  // size 6
    vector<int> iv2(iv.begin(), iv.end()-2);
    cout << iv2.size() << endl;
}
``` 

### Metodi di inserimento e rimozione

Le operazioni di insert() possono risultare piuttosto inefficienti e ció dipende dall'implementazione della classe vector 
Risulta quindi piú efficiente utilizzare una lista se sappiamo a priori di dover inserire elementi in posizioni casuali 

```cpp
#include<string>
#include<vector>

string s;
vector<string> vs, vs1;
vector<string>::iterator i;

vs.push_back(s);    // aggiunge s in coda
vs.insert(i,s);     // aggiunge s subito prima di *i
vs.insert(i,5,s);   // aggiunge 5 s subito prima di *i
i = vs.begin() + vs.size()/2;
vs.insert(i, vs.begin(), vs.end()); // inserisce tutti gli elementi di vs1 nella posizione mediana di vs
``` 
Allo stesso modo l'unico caso efficiente della rimozione da un vettore é la pop_back() che rimuove l'ultimo elemento
Per rimuovere elementi in posizioni arbitrarie si usa erase() che peró risulta inefficiente in quanto il vettore si ricompatta

```cpp
vector<string> v;
vector<string>::iterator i,j;

v.pop_back();   // toglie l'ultimo elemento 
v.erase(i);     // toglie l'elemento puntato da i
v.erase(i,j);   // toglie tutti gli elementi compresi tra l'iterartore i incluso e l'iteratore j escluso
```

Su tutti i contenitori sequenziali (vector, list, deque) sono definiti gli operatori booleani relazionali < e <=

```cpp
Cont<Tipo> x,y;
x == y, x != y, x < y, x <= y, x > y, x >= y;
//occorre che sul tipo base Tipo siano definiti i due operatori == e <
// ATTENZIONE: sui map confronta le coppie (chiave,valore)
```

push_back(), pop_back() sono definiti per tutti i contenitori sequenziali;
insert() e erase() sono definiti per tutti i contenitori

In ogni contenitore sequenziale (vector, deque, list) possiamo acedere al primo ed ultimo elemento con i metodi:

```cpp
T& front();
const T& front() const;

T& back();
const T& back() const;
```

L'overloading dell'operatore di subscripting operator[] é disponibile solo per i contenitori ad accesso casuale vector e deque

```cpp
Cont<Tipo> x;   // vector o deque
int i = 5;
Tipo e = x[i];  // elemento in posizione i-esima
```

Per portabilitá é preferibile utilizzare per gli indici il tipo interno al contenitore Cont<Tipo>::size_type (uint)

```cpp
Cont<Tipo> x;
Cont<Tipo>::size_type i = 5;
Tipo e = x[i];  // lemento in posizione i-esima
```