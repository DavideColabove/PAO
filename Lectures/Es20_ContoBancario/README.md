# Descrizione

Definire una superclasse ContoBancario e due sottoclassi ContoCorrente e ContoDiRisparmio che soddisfano le seguenti specifiche


## Richieste

1. Ogni ContoBancario é caratterizzato da un saldo e rende disponibili due funzionalitá di deposito e prelievo: double deposita(double) e doouble preleva(double) che ritornano il saldo aggiornato dopo l'operazione di deposito/prelievo

2. Ogni ContoCorrente é caratterizzato anche da una spesa fissa uguale per ogni ContoCorrente che deve essere detratta dal saldo ad ogni operazione di deposito e prelievo

3. Ogni ContoDiRisparmio deve avere un saldo non negativo e pertento non tutti i prelievi sono permessi; d'altra parete, le operazioni di deposito e prelievo non comportano costi aggiuntivi e restituiscono il saldo aggiornato.

4. Si definisca inoltre una classe ContoArancio derivata da ContoDiRisparmio. La classe ContoArancio deve avere un ContoCorrente di appoggio: quando si deposita una somma S su un ContoArancio, S viene prelevata dal ContoCorrente di appoggio; d'altra parte, i prelievi di una somma S da un ContoArancio vengono depositati nel ContoCorrente di appoggio.
