# Operating-System-2013
topic:threads c++

# Introduzione sul progetto

La scelta iniziale del nostro gruppo è stata quella di dividere subito il nostro progetto in
diversi file per avere una più chiara struttura del codice, quindi abbiamo inizialmente
creato il file denominato ‘Threads_main.c’; questo file contiene l’inizializzazione e la
creazione dei nostri quattro thread:
• Tr, un produttore di dati, ovvero stringhe prese in input dal terminale con
lunghezza arbitrariamente lunga, nel nostro caso 500 caratteri
• Te, un consumatore di dati che genera una stringa casuale e ne fa lo XOR con la
stringa inserita nel thread Tr
• Td, che fa semplicemente il decriptaggio dello XOR del thread Te, restituendo lo
XOR tra il risultato di Te e la stringa casuale•
Tw, stampa solamente il risultato del thread Td, che deve essere la stringa
inizialmente inserita dall’utente
Prima dell’inizializzazione e della creazione dei thread necessari allo sviluppo del
codice nella fase di sistemazione del progetto abbiamo aggiunto un controllo
sull’input con la getoption, infatti in fase di esecuzione il programma dovrà essere
lanciato con l’opzione –q seguita da un intero, questo intero sarà poi la dimensione del
nostro buffer fatto a coda che conterrà gli elementi che verranno inseriti in input,
qualora nell’opzione –q verrà inserito un valore non numerico o lo zero, il programma
verrà chiuso con la creazione di un messaggio d’errore, nel caso in cui il programma
fosse eseguito senza l’opzione –q viene data alla coda una dimensione di default pari a
50.
L’altro file ausiliario del nostro progetto è il file ‘Threads.h’ che è stato creato per
salvare tutte le dichiarazioni delle funzioni e della struct ‘prodcons’.
La struttura ‘prodcons’, viene dichiarata con il nome ‘buffer’ ed è stata creata per
salvare in un buffer di lettura e scrittura tutti gli elementi inseriti in input dall’utente.
Le variabili che compongono la struct ‘prodcons’ sono:
• cha elem, ovvero l’array degli elementi contenuti della nostra coda
• int testa, il primo elemento della coda
• int coda, l’ultimo elemento della coda
• int size
• int mas, il numero massimo di elementi dell’array della coda
• pthread_mutex_t lock, il semaforo che amministra il funzionamento di Tr e Te
• pthread_cond_t notempty, una condizione che modifica il mutex nel caso che la
coda sia vuota
• pthread_cond_t notfull, una condizione che modifica il mutex nel caso che la
coda sia piena
Abbiamo scelto di utilizzare un mutex in quanto è un semaforo esclusivo ed essenziale
per risolvere il problema del produttore-consumatore dei primi due thread.
Per evitare che questo file venga compilato più di una volta abbiamo incluso tutto il
codice del file ‘Threads.h’ all’interno di un #IFNDEF.
Il cuore del nostro progetto è il file ‘Threads.c’ che contiene tutte le istruzioni delle
funzioni e dei thread che vengono eseguite dal programma per arrivare al risultato
finale.
Oltre alle funzioni abbiamo creato alcune variabili che per forza di cose dovevano
essere dichiarate come globali, in quanto utilizzate in più funzioni, queste sono:
• char S[500], la variabile in cui verranno salvate le stringhe inserite dall’utente
• int controllo, la variabile che farà uscire dall’esecuzione il programma nel caso
l’utente digiti la stringa “quit”
• char R, Se, Sd, le variabili che conterranno rispettivamente la stringa random
creata nel thread Te, la stringa derivata dallo XOR tra la stringa in input e la
stringa casuale, e la stringa, che risulterà uguale ad S, che deriva dallo XOR tra
la stringa random e la stringa Se
• int lungS, la variabile che conterrà la lunghezza delle stringhe prese in input
In aggiunta alle variabili globali abbiamo aggiunto anche dei semafori globali che
gestiscono l’attesa e l’avvio dei thread Td e Tw.

Per l'intero report aprire il file report.pdf


