/*

Scrivere un programma che genera argv[1] processi figlio. Ogni processo, compreso il processo padre
incrementa per sempre una propria variabile var da zero fino argv[2] come segue
0, 1, 2, . . . , argv[2] − 1, argv[2], 0, 1, 2, . . .
(si ricorda che sopra per argv[i] si intende l’intero scritto nella stringa, non la stringa).
 Ogni volta che var è uguale a zero, il processo figlio invia SIGUSR1 al processo padre.
 Quando il processo padre riceve tale segnale SIGUSR1, se la propria variabile var è minore o uguale a argv[3], invia un
segnale di terminazione ad un processo figlio scelto a caso.
 Il processo padre termina quando anche il suo ultimo figlio ha terminato.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <strings.h>

int received = 0;
int timeout = 0;
int killed_child = 0;

void signal_handler(int signal){
	if(signal == SIGUSR1){
		received = 1;
	}else{
		fprintf(stderr, "Qualcosa di strambo è successo :/\n");
	}
}

void alarm_handler(int signal){
	if(signal == SIGALRM){
		printf("Processi figli uccisi: %d\nVolte che il segnale è stato ricevuto: %d");
	}
}

int main(int argc, char* argv[]){
	
	if(argc != 4){
		fprintf(stderr, "Non ci sono abbastanza argomenti :/\n");
	}
	
	int n_kids, max_var, limit, i, j, var, times;
	pid_t child, father;
	struct sigaction sa, sa_alarm;
	
	//Installing handlers in each signal
	bzero(&sa, sizeof(sa));
	sa.sa_handler = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	
	bzero(&sa_alarm, sizeof(sa_alarm));
	sa_alarm.sa_handler = alarm_handler;
	sigaction(SIGALRM, &sa_alarm, NULL);
	
	//Initializing variables
	n_kids = atoi(argv[1]);
	max_var = atoi(argv[2]);
	limit = atoi(argv[3]);
	var = 0;
	times = 0;
	
	father = getpid();
	printf("PID padre: %d\n", father);
	
	pid_t * children = malloc(n_kids * sizeof(*children));
	
	//Creating n_kids child processes
	for(i = 0; i < n_kids; i++){
		children[i] = fork();
		if(children[i] == 0){
			var++;
			if(var == max_var + 1){
				var = 0;
			}
			
			if(var == 0){
				kill(father, SIGUSR1);
			}
		}
	}
		
}
