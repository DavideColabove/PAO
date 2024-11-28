# Descrizione

Si consideri il seguente modello di realtá concernente i file audio memorizzati in un riproduttore digitale iZod

## Richieste

#### (A)  
Si definisca la seguente gerarchia di classi:

1. Definire una classe base polimorfa astratta FileAudio i cui oggetti rappresentano un file audio memorizzabile  in un iZod. Ogni FileAudio é caratterizzato dal titolo (una stringa) e dalla dimensione in MB. La classe é astratta in quanto prevede i seguenti metodi virtuali puri:  
    1. Un metodo di "clonazione": FileAudio* clone()  
    2. Un metodo bool qualita() con il seguente contratto: f->qualita() ritorna true se il file audio *f é considerato di qualitá, altrimenti ritorna false  

2. Definire una classe concreta Mp3 derivata da FileAudio i cui oggetti rappresentano un file audio in formato mp3. Ogni oggetto Mp3 é caratterizzato dal proprio bitrate espresso in Kbit/s. La classe Mp3 implementa i metodi virtuali puri di FileAudio come segue:  
    1. Per ogni puntatore p a Mp3.p->clone() ritorna un puntatore ad un oggetto Mp3 che é una copia di *p  
    2. Per ogni puntatore p a Mp3.p->qualita() ritorna true se il bitrate di *p é >= 192 Kbit/s, altrimenti ritorna false  

3. Definire una classe concreta WAV derivata da FileAudio i cui oggetti rappresentano un file audio in formato WAV. Ogni oggetto WAV é caratterizzato dalla propria frequenza di campionamento espressa in kHz e dall'essere lossless oppure no (cioé con compressione senza perdita oppure con perdita). La classe WAV implementa i metodi virtuali di FileAudio come segue:  
    1. Per ogni puntatore p a WAV.p->clone() ritorna un puntatoread un oggetto WAV che é una copia di *p  
    2. Per ogni puntatore p a WAV.p->qualita() ritorna true se la frequenza di campionamento di *p é >= 96 kHz, altrimenti ritorna false   

#### (B)  
Definire una classe iZod i cui oggetti rappresentano i barni memorizzati in un iZod. La classe iZod deve soddisfare le seguenti specifiche:

1. É definita una classe annidata Brano i cui oggetti rappresentano un brano memorizzato nell'iZod. Ogni oggetto Brano é rappresentanto da un puntatore polimorfo ad un FileAudio:    
    1. La classe Brano deve essere dotata di un opportuno costruttore Brano(FileAudio*) con il seguente comportamento: Brano(p) costruisce un oggetto Brano il cui puntatore poliomorfo punta ad una copia dell'oggetto *p    
    2. La calsse Brano ridefinisce costruttore di copia profonda, assegnazione profonda e distruttore profondo  

2. Un oggetto di iZodd é quindi caratterizzato da un vector di oggetti di tipo Brano che contiene tutti i brani memorizzati nell'iZod

3. La classe iZod rende disponibili i seguenti metodi:  
    1. Un metodo vector<Mp3> mp3(double,int) con il seguente comportamento: una invocazione iz.mp3(dim,br) ritorna un vector di oggetti Mp3 contenente tutti e soli i file audio in formato mp3 memorizzati nell'iZod iz che: hanno una dimensione >= dim e hanno un bitrate >= br    
    2. Un metodo vector<FileAudio*> braniQual() con il seguente comportamento: una invocazione iz.braniQual() ritorna il vector dei puntatori ai FileAudio memorizati nell'iZod iz che: sono considerati di qualitá e se sono dei file audio WAV allora devono essere lossless  
    3. Un metodo void insert(Mp3*) con il seguente comportamento: una invocazione iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani memorizzati nell'iZod iz se il file audio mp3 *p non é giá memorizzato in iz, mentre se il file audio *p risulta giá memorizzato non provoca alcun effetto  
