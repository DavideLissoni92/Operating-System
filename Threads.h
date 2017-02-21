/*
 ANNO ACCADEMICO: 2012/2013
 CORSO DI STUDIO: Informatica 2^o anno, Sistemi operativi
 NOME PROGETTO: Progetto 2:Threads 
 COMPONENTI:
 Dellagiacoma Daniele		Matricola: 152027
 Lissoni Davide			Matricola: 151855
 Carli Luca			Matricola: 152011
 */

#ifndef THREADS
#define THREADS
#include <pthread.h>

//struttura condivisa, un buffer fatto a coda ed i semafori
typedef struct {
	char **elem;
	int size;
	int mas;
	int testa;
	int coda;
	int attuale;
	pthread_mutex_t lock;
	pthread_cond_t notempty;
	pthread_cond_t notfull;
}prodcons;
//dichiarazione buffer
prodcons buffer;

//dichiarazione funzioni
void *Trbody(void *arg);
void *Tebody(void *arg);
void *Tdbody(void *arg);
void *Twbody(void *arg);

void dataora(int nthread);
char * top(prodcons *b);
void dequeue(prodcons *b);
void enqueue(char  *S,prodcons *b);
void inserisci (prodcons *b);
char* estrai (prodcons *b);
void deinit();
void init(prodcons *b, int opzione);
int ctrlS(char* d);

#endif
