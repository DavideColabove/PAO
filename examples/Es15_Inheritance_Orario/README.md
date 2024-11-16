# Descrizione

L'ereditarietá prevede un tipo di relazione IS-A
Polimorfismo: le variabili possono cambiare forma mentre il programma é in esecuzione

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

![Inheritance Animals](../../assets/inheritance_animals.png)

Subtyping: Sottotipo D => Supertipo B
    1. Per oggetti: D => B     estrae il sottooggetto
        1. "Butta via" la parte in piú (i campi dati propri della classe derivata D)
        2. Non c'é quindi polimorfismo
    2. Per puntatori e riferimenti: D* => B*  D& => B&
        1. Supporta il polimorfismo
        2. Copia l'indirizzo, significa prendere un indirizzo e farlo puntare ad un oggetto (vederlo come fosse un oggetto del supertipo) ma continua ad avere l'informazione specifica del sottotipo
        3. Non viene "buttato via" nulla

## Gerarchie di classi: sottotipi diretti ed indiretti

![Class hierarchies](../../assets/class_hierarchies.png)

Ogni passo si chiama "passo di derivazione diretta":
F => sottoclasse diretta di => E => sottoclasse diretta di => D => sottoclasse diretta della => Base

Quindi F é una sottoclasse di D (per transitivitá) di tipo indiretto

## Casi d'uso di ereditarietá 

1. Estensione
    1. DataOra <: Orario

2. Specializzazione
    1. QButton <: Qcomponent
    2. Relazione di sottotipaggio
    3. Il pulsante non aggiunge caratteristiche ad una componente ma é una componente specializzata

3. Ridefinizione
    1. Queue <: List
    2. La coda ha un campo dati di tipo lista
    3. Ad esempio: ridefinendo il comportamento dell'insert e permettendo l'inserimento solo in coda alla lista, eredito l'intefaccia di List e ne ridefinisco alcuni sue funzionalitá
    4. Una coda appunto, non aggiunge altre funzioni alla lista
    5. Specializzazione != Ridefinizione: la prima va a specializzare alcune funzioni mentre la ridefinizione ne va a cambiare il comportamento

4. Riutilizzo di codice
    1. Queue reuse List
    2. NON É SUBTYPING
    3. Coda non é sottotipo di lista: faccio un passo di ereditarietá (godo dei vantaggi di definire per ereditarietá un tipo), se in un contesto chiedo una lista non ci posso mettere una coda

## Conversioni

Data una classe B, per ogni sottotipo D (in generale indiretto) di B valgono quindi le seguenti conversioni implicite:

1. D => B (oggetti)

2. D& => B& (riferimenti)

3. D* => B* (puntatori)