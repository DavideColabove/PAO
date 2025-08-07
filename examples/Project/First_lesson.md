# Descrizione

Discussione riguardo il framework Qt nell'ambito del progetto didattico.


## Qt

Qt è un framework cross-platform per la creazione di GUI e di applicazioni cross-platform;

Perche Qt?
1. Completamente orientato agli oggetti
2. Scritto in C++
3. Usato in progetti di rilievo di AMD, Blizzard, EA ecc..

Aggiunge a C++:
1. Containers
2. Accesso ad SQL
3. XML e JSON (utile per il soggetto)
4. Programmazione concorrente
5. Programmaizone di rete

### Come eseguire una applicazione 

Per eseguire una applicazione in scritta in Qt:
1. Installare Qt
2. Scriverne il codice
3. Generare il file progetto
4. Fixare il file progetto
5. Generare il Makefile
6. Compilare
7. Modificare il codice
8. Ripetere da 5 a 6


## Primo codice in Qt

![HelloWorldQT](../../assets/QtHELLOWORLD.png)

Bisogna includere gli header file QApplication (contiene le definizioni per avviare una applicazione) e QLabel (un elemento con contenuto visualizzabile)

All'interno del main creiamo una QApplication che chiamiamo app (a cui possiamo passare dei parametri), di per se pero' essa non fa niente e non visualizza niente;
In questo caso semplice creiamo una variabile QLabel sullo stack che contiene il testo "Hello world!", ma se vogliamo che questa label venga mostrata dobbiamo invocare il metodo show() su di esso;
Dobbiamo poi invocare il metodo exec() sulla nostra QApplication che gestisce tutto il ciclo di vita dell'applicazione senza chiusura al termine delle operazioni.

## .pro e Makefile

### .pro

Possiamo generare il file .pro dal comando "qmake -project" che cerca i file nella cartella relativi al progetto e ne genera il file il file .pro corretto

ATTENZIONE: qmake non include automaticamente i widget nel file .pro, per cui dovremmo aggiungerli a mano editando il file aggiungendo QT += widgets

### Makefile

Il comando "qmake" senza argomenti genera un Makefile (se è presente un file .pro);
lanciando poi il comando "make" compilerà effettivamente in un esseguibile che possiamo lanciare con "./"

IMPORTANTE: provare con questi comandi in Linux dato che saranno usati per la valutazione

Se viene modificato un file esistente bisogna rilanciare il comando "make", mentre se viene aggiunto o rimosso un file bisognerà rilanciare anche il comando "qmake" e poi "make"

## Esempio di strutture layout per un applicazione GUI

![GameLayout](../../assets/QtLayout.png)

Identificare i blocchi che compongono la GUI sarà utile per l'implementazione in Qt.
Ogni framework GUI funziona tramite blocchi rettangolari, container e stretch (o spacers), che servono ad organizzare la struttura della GUI;

## Esempio di core model logico dell'applicazione

![GameCore](../../assets/CoreModel.png)

In questo esempio di core model, completamente scorrelato dalla GUI, vediamo la creazuione di uno schema logico per il funzionamento e disposizione delle classi: in questo caso, la classe base astratta Character viene specializzata in Hero (il giocatore) e Monster (il nemico) che estendono le funzionalità della classe Character aggiungendo i loro metodi specifici, aggiungendone attributi e overrideando metodi già definiti nella classe base astratta.

Le classi concrete DEVONO avere delle differenze significative (attributi diversi, metodi diversi, ecc..)

L'immagine rappresenta una diagramma UML, di seguito un cheatsheet:
1. Un rettangolo = una classe
2. Attributi e funzioni
3. ":" definiscono i tipi
4. "-" per campi dati privati, "#" per i protetti e "+" per i pubblici
5. Frecce per l'ereditarietà
6. Italico per i metodi virtuali, grassetto per i virtuali puri

## Separazione tra modello logico e GUI

![GUIwidgets](../../assets/GUIwidgets.png)

Sarebbe teoricamente possibile implementare direttamente l'interfaccia grafica durante lo sviluppo del modello logico ma cio' risulterebbe inefficiente;
Al contrario, se si tengono separati i due componenti è possibile testare man mano da CLI le funzioni appena implementate senza dover completare lo sviluppo della GUI.

Lo schema sopra riportato vengono rappresentate anche le implementazioni dei blocchi citati nelle sezioni precedenti;

Tutto cio che facciamo deve stare dentro il main window, che contine i widget della nostra applicazione.


## Segnali e slot


## Slots


## Signals

## Costruzione e Distruzione


## Abstract Factory Design Pattern 


