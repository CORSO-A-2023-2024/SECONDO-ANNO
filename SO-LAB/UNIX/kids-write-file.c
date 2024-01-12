#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void writing_in_file(FILE * file, int n){
	for(int i = 0; i < n; i++){
		fprintf(file, "%d, %d\n", getpid(), getpid());
	}
}

void generating_kids(int n_kids, int n_writes, FILE * file){
	#ifdef NO_BUFFERING
	setvbuf(file, NULL, _IONBF, 0);
	#endif
	
	for(int i = 0; i < n_kids; i++){
		if(!fork()){
			writing_in_file(file, n_writes);
			break;
		}
	}
}

int main(int argc, char * argv[]){
	FILE * file_write;
	char * ptr;
	
	file_write = fopen(argv[1], "w");
	int n_kids = strtol(argv[2], &ptr, 10);
	int n_writes = strtol(argv[3], &ptr , 10);
	
	generating_kids(n_kids, n_writes, file_write);
	
	printf("n_kids: %d\nn_writes: %d\n", n_kids, n_writes);
}
