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

