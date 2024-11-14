# Descrizione

Spiegazione List, Deque, contentiri associativi in STL

## Teoria List

Contenitore lista: list<Tipo>
É implementata come una "doubly-linked list"

A differenza di vector permette di eseguire inserimento e rimozione in tempo costante in poszione arbitraria

Size:   size_of(T) + 16 byte 
            |           |         
            info        2 puntatori

É meno efficiente di vector nell'accesso agli elementi: infatti l'implementazione necessariamente deve percorrere la lista dall'inizio (o dalla fine)

NON É DISPONIBILE operator[ ]

## Teoria Deque

Contenitore bidirezionale: deque<Tipo>
Si tratta del contenitore "Double Ended Queue", coda a due estremi

Il contenitore deque unisce alcuni dei vantaggi principali del vector e della list
1. Accesso indicizzato efficiente per lettura e scrittua come in un vector = supporta operator[ ] 
2. Inserimento ed eliminazione agli estremi del contenitore sono efficienti come in una list

Lo si ottiene perche un deque é tipicamente implementato mediante una struttura dati complessa che consiste di piú array dinamici di dimensione fissa o di un buffer circolare.
Rispetto al vector, le riallocazioni sono generalmente piú efficienti 

## Teoria contenitori associativi 

I contenitori associativi permettono di accedere ad un elemento mediante il valore dell'elemento stesso o di una parte di tale valore, cioé la cosiddetta chiave di accesso all'elemento.
In ogni contenitore associativo le chiavi sono mantenute ordinate, quindi il tipo delle chiavi deve supportare l'operatore relazionale d'ordinamento operator<

Prendono il nome di set se le chiavi sono uniche e multiset se le chiavi possono essere ripetute

Vengono tipicamente mantenute ordinate mediante un albero 

Map e Multimap includono anche il valore contenuto nella chiave

## Esercizio

Definire un template di classe dList<T> i cui oggetti rappresentano una struttra dati lista doppiamente concatenata (doubly-linked list) per elementi di uno stesso tipo T.

### Richieste

Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione

2. dList<T> rende disponibile un costruttore dList(int k, const T& t) che costruisce una lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t

3. dList<T> permette l'inserimento in testa ed in coda ad una lista in tempo O(1) (cioé costante):
    1. Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento d1.insertFront(t) inserisce l'elemento t in testa a d1 in tempo O(1)
    
    2. Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento d1.insertBack(t) inserisce l'elemento t in coda a d1 in tempo O(1)

4. dList<T> rende disponibile un opportuno overlading di operator< che implementa l'ordinamento lessicografico

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::const.iterator i cui oggetti permettono di iterare sugli elementi di una lista