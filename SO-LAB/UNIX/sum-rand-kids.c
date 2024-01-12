#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	#ifdef NUM_KIDS
	int sum, i, pid, status;
	int n;
	for(i = 0; i < NUM_KIDS; i++){
		pid = fork();
		if(!pid){
			//ramo figlio
			srand(getpid());
			n = rand() % 6 + 1;
			printf("PID: %d, n: %d\n", getpid(), n);
			exit(n);
			break;
			
		}
	}
	sum = 0;
	while(wait(&status) != -1){
		sum += WEXITSTATUS(status);
	}
	printf("the sum is: %d\n", sum);
	exit(EXIT_SUCCESS);
	#endif
	fprintf(stdout, "NUM_KIDS non è stato definito\n");
}

