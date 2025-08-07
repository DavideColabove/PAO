# Descrizione

Discussione riguardo i 5 principi della buona programmazione ad oggetti (S.O.L.I.D.)


## S.O.L.I.D.

S   Single responsability    
O   Open-closed    
L   Liskov substitution    
I   Interface segregation  
D   Dependency inversion  

Lo scopo é di scrivere buon codice che sia manutenibile ed estensibile nel tempo  

1. Single responsability: una classe dovrebbe avere una singola responsabilitá (risolvere un singolo problema)

2. Open-closed: Aperto per le estensioni (la classe deve poter essere estesa, ad esempio definendone un sottotipo), ma Chiuso alle modifiche (utilizzare il private per i campi dati il piú possibile)

3. Liskov substitution principle: se nel codice c'é un punto che non torna con la regola del subtyping probabilmente c'é un bug logico 

4. Interface segregation principle: piú interfacce specifiche sono meglio di una sola interfaccia general-purpose

5. Dependency inversion: disaccoppiamento dei tipi, i piani alti non devono dipendere dai piani bassi