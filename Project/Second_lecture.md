# Descrizione

Discussione riguardo il framework Qt nell'ambito del progetto didattico.


## RECAP

### HeroPanel

Per quanto riguarda l'heroPanel abbiamo visto:
1.  Uso di QHBoxLayout per disporre i widget orizzontalmente
2.  QPixmap e QLabel per le immagini
3.  QGridLayout per creare un layout a griglia per i widget
4.  QPushButtons, il suo utilizzo ed alcune sue funzioni
5.  Una funzione membro refresh() per incapsulare la logica di refresh

### Battle widget

Per il widget di battaglia abbiamo visto:
1.  QVBoxLayout per disporre verticalmente i widget
2.  L'aggregazione di altri widget (heroPanel e monsterPanel)
3.  L'uso di addStretch() per aggiungere spaziatura ridimensionabile
4.  Esporre le member function per reagire agli eventi

### Main Window

Per le main window è bene ricordare:
1.  MainWindow estende QMainWindow per ereditarietà pubblica
2.  E' un oggetto e necessità della macro Q_OBJECT
3.  E' necessario utilizzare setCentralWidget per rendere visibile il widget che queste devono contenere altrimenti non viene visualizzato nulla


## Esempio pannello eroe

![HeroPanel](../../assets/HeroPanel.png)

Il pannello dell'eroe contiene 3 elementi al suo interno:
1.  Una artwork
2.  Un pannello delle informazioni che abbiamo realizzato nella lezione precedente
3.  Un bottone per avviare la lotta

Qt mette a dispozione il widget QLabel che permette di rappresentare anche le immagini, senza necessità di definirne uno personalizzato;

Abbiamo anche un metodo refresh() che si comporta analogamente al metodo show() nella lezione precedente

### Costruttore del pannello eroe

![HeroPanelConstructor](../../assets/HeroPanelConstructor1.png)

Usiamo questa volta QHBoxLayout per disporre in orizzonale i widget necessari, percio' dichiariamo un puntatore di tipo QHBoxLayout layout sul quale invochiamo il metodo setAlignment per definire il posizionamento dei widget al suo interno (se non lo facessimo Qt userebbe la disposizone di default)

Inizializziamo una variabile di tipo QPixmap di nome image (un oggetto QPixmap è una mappa di pixel ovvero un raster) per l'artwork dell'eroe: al costruttore passiamo il percorso di dove trovare questa immagine.
Nel percorso notiamo " (":assets/" + QString::forStdString(hero.getName()) + ".png") questo parametro passato al costruttore dice che:
1.  L'artwork si trova nella cartella "assets/", grazie al ":" capisce di non dover cercare tra i file di sistema ma nella specificia cartella
2.  Appende poi il nome dell'eroe ottenuto dalla conversione dell'output della funzione getName() su hero in una QString
3.  Appende infine l'estensione ".png"

Possiamo ora creare una QLabel artwork e per dire che deve mostrare l'immagine appena creata usiamo la member function setPixmap() a cui passiamo l'immagine dell'eroe sulla quale viene invocata la funzione scaledToHeight(256) per ridimensionare l'immagine mantenendo inalterato il rapporto

Essendo questo il primo widget aggiunto, rispettando quanto definito nel QHBoxLayout alignment, l'artwork troverà posto piu' in alto possibilie e piu' a sinistra possibile; 

Creiamo infine l'hero panel visto nella lezione precedente (passato dal costruttore), ci invochiamo il metodo show() per mostrarlo e aggiungiamo il widget al layout
Allo stesso modo dell'artwork esso troverà posto sempre in alto, sempre a sinistra ma subito dopo l'artwork stess (perche aggiunta in precedenza)

### Pulsantiera dei comandi

![HeroPanelButtons](../../assets/HeroPanelButtons.png)

La pulsantiera dei comandi utilizza il layout a griglia, che è idealmente una scacchiera in cui possiamo inserire degli altri widget tramite il loro indice di posizione;

Utilizziamo un puntatore a QGridLayout chiamato commands e creiamone uno tramite il new QGridLayout();
Non sarà direttamente figlio del widget ma andrà innestato dentro il QHBoxLayout creato prima.

Andiamo poi a creare i 3 pulsanti che vogliamo mostrare:
Creiamo i pulsanti QPushButton sempre con l'uso di un puntatore ad un oggetto di tipo QPushButton e creiamone uno con la new al cui costruttore passiamo l'etichetta di cio' che vogliamo scritto nel pulsante (un po' come con le QLabel)
Una volta creato procediamo ad aggiungerlo alla pulsantiera prima creata QGridLayout sempre tramite il metodo addWidget a cui pero' dobbiamo specificare il nome del QPushButton (nel primo caso "attack"), la riga e la colonna che dovrà occupare (nel primo caso "0","0" essendo il primo elemento) ed infine il numero di celle verticali ed orizzontali che dovrà occupare (in tutti i casi di questo esempio saranno bottoni 1x1);
Il procedimento per gli altri bottoni è analogo, negli altri due casi pero' viene invocata la member function setEnabled(false) che serve a disabilitare il pulsante (rendendolo non cliccabile, in grigio).

### Funzione refresh

![HeroPanelButtons](../../assets/HeroPanelButtons.png)

Funzionamento molto semplice, analogo a show(), infatti viene invocata la funzione show() su info per ridisegnare cio' che potrebbe essere cambiato dopo l'attacco


## Esempio widget di Battaglia

![BattleWidget](../../assets/BattleWidget.png)

La scena della battaglia potremmo definirilo come lo schermo principale del nostro sketch che mostra:
1.  In alto il pannello del mostro (ipotizziamo di averlo creato analogamente a quello dell'eroe)
2.  Al centro una spaziatura
3.  Nella parte inferiore il pannello dell'eroe con la relativa pulsantiera

E' anch'esso un widget e lo realizziamo estendendo pubblicamente la classe QWidget e utilizziamo la macro Q_OBJECT

Questa classe necessiterà di alcuni attributi:
1.  L'HeroPanel
2.  Il MonsterPanel (ovvi, in quanto andranno mostrati qui dentro)
3.  Un riferimento al mostro
4.  Un riferimento all'eroe (per interagirci direttamente)

Il costruttore di questa classe Battle necessiterà dei prima citati riferimenti al mostro ed all'eroe, ed un puntatore QWidget alla classe padre = 0

Avremo poi bisogno di un metodo pubblico playerAttacks() per gestire la battaglia: il giocatore effettua il suo attacco, il mostro riceve il danno, vede i propri punti ferita diminuire ed il mostro ribatte con il suo attacco;

A riga 13 vediamo che oltre alla keyword public abbiamo anche slots che il compilatore ignora;

### Costruttore widget di Battaglia

![BattleWidgetConstructor](../../assets/BattleWidgetConstructor.png)

Per prima cosa ne definiamo il costuttore inizializzando la superclasse QWidget, i puntatori ad hero ed a monster;

Vediamo di nuovo l'utilizzo di un QVBoxLayout, la creaizone di un MonsterPanel a cui passiamo il riferimento al mostro e lo aggiungiamo al layout.

Viene invocata a riga 9 la member function addStretch() che ci permette di creare dello spazio vuoto tra i due pannelli.

Infine creiamo un HeroPanel  a cui passiamo il riferimento all'eroe e lo aggiungiamo al layout.

### Funzione playerAttacks()

![playerAttacks](../../assets/BattleWidget_playerAttacks.png)

Questa funzione gestirà la battaglia utilizzando la logica presente nel modello

Quello che succede è che il player attacca il mostro, il quale vedrà i propri punti ferita ridursi invocando il metodo refresh() sul monsterPanel il quale a sua volta chiamerà il metodo show() sull'infoPanel aggiornando le informazioni del pannello tra cui i punti ferita del mostro;
Di risposta il mostro attacca l'eroe, il quale ridurra i punti ferita del player e allora verrà invocato il metodo refresh() sull'heroPanel che a sua volta invocherà il metodo show() sull'infoPanel agggiornando le informazioni dell'eroe.


## La MainWindow

![MainWindow](../../assets/MainWindow.png)


E' un tipo specifico in Qt che viene utilizzato per la finestra principale, nel concreto quello che succede generalmente è che verrà scritto il codice per un certo numero di widget e poi si scriverà il codice di una singola main window;

Essa è comunque un QObject quindi servirà la macro Q_OBJECT e si estende la classe QMainWindow e necessiterà solo di un costruttore a cui passeremo un riferimento all'eroe ed uno al mostro;

Nel codice del costruttore andiamo ad istanziare una Battle passando il riferimento all'eroe ed al mostro;
A riga 3 diciamo di mostrare il widget della battaglia appena creata.


## Il file Main.cpp

![Main.cpp](../../assets/MainFile.png)

Il file Main.cpp servirà come punto di partenza della nostra applicazione;

Dobbiamo quindi istanziare una QApplication app a cui passiamo due argomenti qualora ce ne fosse la necessità;
In questo caso andiamo a creare "manualmente" "(solitamente si legge da un database, o da un file di testo, o da un file JSON,...) l'eroe ed il mostro e li passiamo alla main window che andremo ad usare;

Tramite il metodo resize() invocato sulla main window creata in precedenza possiamo definire la dimensione di apertura di default della main window.
Invochiamo poi il metodo show() per mostrare la main window, ed infine invochiamo il metodo exec() sulla QApplication app creata in precedenza per controllarne il ciclo di vita.


## Riassunto Layout e strutture

![LayoutStructureWrapUp](../../assets/LayoutStructureWrapUp.png)

Ricordiamo che i widgets sono elementi che vediamo effettivamente come etichette, immagini, pulsanti ecc..
I layout al contrario sono dei concetti di disposizione degli elementi, ma ne vediamo gli effetti;

Questi elementi in genere sono organizzati in un struttura dati ad albero, con un certo numero di figli il quale a sua volta puo' avere altri figli.

I widgets:
1.  Sono organizzati in una struttura ad albero
2.  Hanno legami di parentela padre-figlio
3.  Funzionano a composizione (eg. HeroPanel è composto da Artwork, Info ecc..)
4.  Vengono distrutti automaticamente da Qt

I layout invece:
1.  Contengono widgets
2.  Sono contenuti in widgets
3.  Organizzano contenuti
4.  Si occupano della disposizione dei widget nello spazio


## Comportamento logico su input grafico

![AttackClick](../../assets/AttackClick.png)

La nostra applicazione dovrà fare qualcosa in determinate circostanze, nel nostro caso l'unica fonte di interazione sarà il bottone "attack" che, quando premuto dovrà andare ad invocare la funzione playerAttacks() definita in battle_scene;
Al suo interno viene gestita la logica della battaglia quindi l'eroe attacca il mostro, il mostro risponde attaccando l'eroe e successivamente si aggiornano i punti ferita di entrambi grazie all'invocazione di refresh() in hero_panel e monster_panel chiamate da playerAttacks();

Questa serie di operazioni la possiamo vedere come una catena di eventi che succedono uno dopo l'altro, in particolare in seguito alla pressione del pulsante di attacco.

Diremo quindi che c'è un evento che si attiva al click sul pulsante;


## Event driven programming

![EventDrivenProgramming](../../assets/EventDrivenProgramming.png)

Questa gestione degli eventi in Qt è stata implementata tramite segnali e slot: vengono gestiti via codice ma prendiamo come riferimento l'immagine sopra per maggior chiarezza;

I rettangoli rappresentano i widgets (in altro il nome del widget in questione), nella parte superiore dei rettangoli abbiamo i segnali che possiedono dei connettori sia a destra che a sinistra: i connettori ci suggeriscono che possiamo avere sia degli input sia degli output (quelli a destra sono input e quelli a sinista sono output);
Nella parte inferiore dei rettangoli abbiamo cio' che Qt chiama slot, che a differenza dei segnali non possono avere nessun output ma hanno soltanto degli input;
Notiamo che i connettori si possono connettere in modo che l'output di un segnale sia l'input di un altro segnale od uno slot.

I SEGNALI: sono i possibili eventi che un widget puo' emettere (eg. il QPushButton prevede la possibilità di emettere il segnale "pressed");

GLI SLOT: sono le possibili reazioni, quello che puo' avvenire in risposta ad un segnale scatenato da un evento.

I COLLEGAMENTI: sono un'astrazione di una relazione del tipo "dato evento scatena tale reazione";

Abbiamo visto che i segnali hanno connettori sia di input che di output: è chiaro come quello di output nel QPushButton è il segnale emesso alla pressione del pulsante che indica che tale pulsante è stato premuto;
Qt permette di realizzare la propagazione di segnale cioè attivando un secondo segnale mediante il primo.

![SignalOurGame](../../assets/SignalOurGame.png)

Nel nostro esempio, il QPushButton emetterà il segnale "pressed" (nativamente presente in Qt) quello che vogliamo in risposta è l'attivazione dello slot playerAttacks() nella classe Battle.

Quello che fa la keyword slots nella definizione di una classe è dichiarare che i metodi successivi sono utilizzabili come slot (dal punto di vista pratico non c'è alcuna differenza tra uno slot ed un metodo privato o pubblico).

Il metodo che vogliamo attivare è playerAttacks() ma c'è un problema, nella classe battle non possediamo un riferimento al QPushButton quindi non possiamo collegarci a quel pulsante per rimanere in ascolto del segnale di pressione perche non abbiamo puntatori o riferimenti a quel pulsante;
Al contrario, il costruttore dell'heroPanel alloca il pulsante nella pulsantiera presente nell'heroPanel;
L'heroPanel è l'unico che puo' quindi collegarsi a quel pulsante percio' dobbiamo utilizzare il relay di segnale: la classe heroPanel esporrà il proprio segnale attack e collegherà la pressione del pulsante attacca a questo segnale creando un relay di segnale.
La classe Battle puo' connettersi al segnale personalizzato attack, quando viene emesso il segnale heroPanel di attack il widget della battaglia sa che deve rispondere con la simulazione della battaglia.


### Signals

![SinglasDeclaration](../../assets/SinglasDeclaration.png)

Nell'heroPanel l'implementazione dei segnali porta una unica differenza, cioè che deve essere dichiarato un nuovo segnale (vedi riga 10 e 11);
I segnali non hanno modificatori di accesso, sono sempre tutti pubblici.
Utilizziamo l'etichetta signals che indica che tutto cio' che c'è da li in poi va considerato come segnale.
I segnali si dichiarano allo stesso modo delle member functions, cioè un tipo che sarà quasi sempre void, il nome del segnale e tra parentesi gli argomenti che vogliamo che il nostro segnale trasporti;

ATTENZIONE: I segnali vanno solo dichiarati ma mai implementati (in questo caso, abbiamo la dichiarazione in HeroPanel.h ma non l'implementazione in HeroPanel.cpp) perchè i segnali non hanno un comportamento da svolgere ma solo una segnalazione che un certo evento si è scatenato


### Slots 

![SlotsDelcaration](../../assets/SlotsDelcaration.png)

Gli slot abbiamo anticipato essere in tutto e per tutto uguali a delle normali member functions quindi si tratta solo di aggiungere la parola chiave slots dopo public;

ATTENZIONE: Uno slot è anche una member functions quindi puo' essere usata come invocazione di metodo, ma non il contrario (se un metodo non è dicharato come slot allora non è possibile utilizzarlo come slot)

A differenza dei segnali, gli slot devono sempre essere implementati;

#### Signals connected to slots

![SignalsConnectedToSlots](../../assets/SignalsConnectedToSlots.png)

L'implementazione nel nostro esempio è molto semplice: l'eroe attacca il mostro ed aggiorna i punti ferita del mostro, il mostro attacca l'eroe ed aggiorna l'interfaccia;

Avere segnali e slot non significa che siano connessi automaticamente (perche Qt non ha idea di cosa vogliamo connettere a cosa), ma starà a noi utilizzare la member function connect() presente nelle nostre classi in quanto ereditate da QWidget.
Quello che dobbiamo fare nella classe della battaglia è dire che il segnale attack nell'heroPanel andrà connesso allo slot playerAttacks di battle

La member function connect() ha bisogno di 4 argomenti:

connect(source_widget, signal, destination_widget, slot)

1.  L'oggetto che potrà emettere il segnale che ci interessa
2.  Il segnale che ci interessa gestire rappresentato tramite puntatore a funzione
3.  Oggetto che riceverà e gestirà quel segnale
4.  Lo slot che risponderà a quel segnale o un altro segnale (se utilizziamo relay di segnali), anche questo rappresentato tramite puntatore a funzione

(puntatore a funzione:  &NomeClasse::memberFunction)

#### Signals connected to signals

![SignalsConnectedToSignals](../../assets/SignalsConnectedToSignals.png)

Abbiamo pero' detto che bisogna anche connettere la pressione del pulsante attack con l'emissione da parte di heroPanel del segnale attack, quindi per fare questo dobbiamo utilizzare un altro segnale (per fare un relay di segnale) e lo possiamo fare nel costruttore di heroPanel.

Alla riga 11 c'è la connessione che ci interessa: quello che deve succedere è che il pulsante attack, alla pressione (Qt sa che quando un QPushButton è premuto verrà emesso il segnale "pressed" senza bisogno di controllarlo manualmente), a gestire questo segnale sarà il widget stesso (quindi this) e dovrà propagare il segnale tramite il segnale attack;

#### Self connected signals and self connected slots

![SelfConnected](../../assets/SelfConnected.png)

Con segnali e slot possiamo creare infinite combinazioni, alcuni esempi nella figura precedente.

1.  Un singolo segnale puo essere connesso a piu' slot e/o piu segnali (nessun vincolo) (per fare cio' basta chiamare la connect() tante volte, una per ogni connessione che si vuole effettuare)
2.  Autoconnessione: il widget 5 emette un segnale 1 che si connette al suo stesso slot 1 (comodo a volte in caso di relay di segnali)
3.  Input multipli su un singolo slot, da prestare attenzione perche i segnali sono indipendenti e si attiverà lo slot O tramite segnale 1 di widget 1 O tramite segnale 1 di widget 3 (possiamo vederlo come un OR), non possiamo richiedere concorrenza, ne ordinamento (ad esempio lo slot 1 si attiva solo se riceve prima widget 3 che widget 1 o viceversa ecc..): SI PUO FARE TRAMITE ESCAMOTAGE DA NOI SVILUPPATI, MA NON NATIVAMENTE 


## Argomenti propagati per tramite segnali

![SignalArguments](../../assets/SignalArguments.png)

I segnali possono portare con loro argomenti e parametri essendo dichiarati come dei metodi; 
A livello di connessione, segnali e slot, possono essere tra loro connessi SOLO quando hanno lo stesso numero di parametri E dello stesso tipo;

Nell'esempio segnale 2 di widget 1 puo esere connesso a slot 2 di widget 2 in quanto vengono passati 2 interi ed attesi 2 interi, al contrario slot 1 di widget 3 che si aspetta una stringa non potrà essere connesso a segnale 2 di widget 1.

Funziona esattamente allo stesso modo del passaggio dei parametri per funzioni;







