#ANNO ACCADEMICO: 2012/2013
#CORSO DI STUDIO: Informatica 2^o anno, Sistemi operativi
#NOME PROGETTO: Progetto 2:Threads 
#COMPONENTI:
#Dellagiacoma Daniele	Matricola: 152027
#Lissoni Davide	        Matricola: 151855
#Carli Luca	        Matricola: 152011
 
CC=gcc
CFLAGS=-c 
MAIN=Threads_main.c Threads.h
FUNCTION=Threads.c Threads.h
MAINOBJ=Threads_main.o
FUNCTIONOBJ=Threads.o

Progetto: $(MAINOBJ) $(FUNCTIONOBJ)
	$(CC) Threads.o Threads_main.o -lpthread

Threads_main.o: $(MAIN)
	$(CC) $(CFLAGS) Threads_main.c -lpthread

Threads.o: $(FUNCTION)
	$(CC) $(CFLAGS) Threads.c -lpthread
