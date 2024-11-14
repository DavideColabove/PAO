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