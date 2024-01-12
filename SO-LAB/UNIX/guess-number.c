/*

Scrivere un programma che realizzi un semplice gioco. Il programma seleziona un numero casuale tra 0
e argv[1] (il primo argomento passato a riga di comando), e l’utente deve indovinare questo numero. Per fare questo, viene
realizzato un ciclo in cui il programma legge da tastiera un numero inserito dall’utente:
 se il numero è stato indovinato, il gioco finisce;
 se il numero è maggiore o minore di quello estratto casualmente, viene stampato a video la scritta “maggiore” o “minore”,
rispettivamente.
Se il giocatore non indovina entro argv[2] secondi (da realizzare con alarm e gestendo il segnale SIGALRM), il programma stampa
a video “tempo scaduto”, ed esce.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <strings.h> 
#include <unistd.h>

int interrupt = 0;

void signal_handler(int signal){
	if(signal == SIGALRM){
		interrupt = 1;
	}else{
		fprintf(stderr, "Qualcosa di strambo è successo\n");
	}
}

int main(int argc, char* argv[]){

	if(argc != 3){
		fprintf(stderr, "Argomenti non sufficienti\n");
	}
	
	int estremo = strtol(argv[1], NULL, 10);
	int timeout = strtol(argv[2], NULL, 10);
	int number, guess;
	srand(getpid());
	number = rand() % (estremo + 1);
	struct sigaction sa;
	
	bzero(&sa, sizeof(sa));
	sa.sa_handler = signal_handler;
	sigaction(SIGALRM, &sa, NULL);
	
	alarm(timeout);
	
	while(!interrupt){
		scanf("%u", &guess);
		if(guess == number){ 
			printf("Numero indovinato\n");
			exit(0);
		} else if(guess > number){
			printf("Riprova: il numero indovinato è maggiore del numero da indovinare\n");
		} else {
			printf("Riprova: il numero indovinato è minore del numero da indovinare\n");
		} 
	}
	printf("Tempo scaduto! :(\n");
	exit(0);
	
}
