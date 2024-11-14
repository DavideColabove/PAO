# Descrizione

Spiegazione List in STL

## Teoria

Contenitore lista: list<Tipo>
É implementata come una "doubly-linked list"

A differenza di vector permette di eseguire inserimento e rimozione in tempo costante in poszione arbitraria

Size:   size_of(T) + 16 byte 
            |           |         
            info        2 puntatori
            
É meno efficiente di vector nell'accesso agli elementi: infatti l'implementazione necessariamente deve percorrere la lista dall'inizio (o dalla fine)

NON É DISPONIBILE operator[]

## Iteratori nei contenitori



### Metodi di inserimento e rimozione

