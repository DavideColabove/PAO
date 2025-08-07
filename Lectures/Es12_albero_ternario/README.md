# Descrizione esercizio

Definire un template di classe albero<T> i cui oggetti rappresentano un albero 3-ario in cui i nodi memorizzano dei valori di tipo T ed hanno 3 figli.

## Richieste

Il template albero<T> deve soddisfare i seguenti vincoli:
1. costruttore di default che costruisce l'albero vuoto;

2. gestione della memoria senza condivisione;

3. metodo void insert(const T&): in una chiamata a.insert(t), inserisce nell'albero a una nuova radice che memorizza il valore t, ed avente come figli 3 copie di a;

4. metodo bool search(const T&): in una chiamarta a.search(t) ritorna ture se il valore t occorre nell'albero a, altrimenti ritorna false;

5. overloading dell'operatore di uguaglianza;

6. overloading dell'operatore di output;
