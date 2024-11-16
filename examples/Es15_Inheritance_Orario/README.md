# Descrizione

L'ereditarietá prevede un tipo di relazione IS-A

## Teoria Inheritance

In questo caso, una DataOra é (anche) un Orario
Per un oggetto di DataOra avró "inscatolato" dentro anche un oggetto di tipo Orario

Vado quindi a definire nella classe DataOra definisce solo i suoi field e le sue funzioni, sottointendendo che tutto quello che ho ereditato da Orario é parte di DataOra 
I field di DataOra prendono il nome di campi dati propri

La classe che definiamo per ereditarietá prende il nome di classe derivata (D)
La classe da cui eredito si chiama classe base (B)
Si puó anche dire che D é sottotipo (subclass) mentre B é supertipo (superclass)

É importante sottolineare che esitono le classi e i tipi
Si potrá quindi ereditare da una classe ma senza avere una relazione di sottotipaggio

In questo caso:
Orario -> sottooggetto
int giorno, int mese, int anno -> campi dati propri
L'insieme dei precedenti compone -> oggetto DataOra

La relazione "IS-A" induce il subtyping che é la caratteristica fondamentale dell'ereditarietá:
Ogni oggetto della classe derivata é utilizzabile anche come oggetto della classe base

![Inheritance Animals](./assets/inheritance_animals.png)


## Esercizio



### Richieste

