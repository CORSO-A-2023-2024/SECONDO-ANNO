#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char * argv []){
	long timeout = strtol(argv[1], NULL, 10); //alarm's timeout in seconds
	long n_iter = strtol(argv[2], NULL, 10); //number of iterations for the cycle
	alarm(timeout);
	for(int i = 0; i < n_iter; i++);
}
