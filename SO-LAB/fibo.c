#include <stdio.h>
#include <stdlib.h>

int * fibo(int n){
	int * v;
	v = malloc(n * sizeof(*v));
	v[0] = 0;
	v[1] = 1;
	for(int i = 2; i < n; i++){
		v[i] = v[i-2] + v[i-1];
	}
	return v;
}

int main(){
	int num = 0;
	int * p;
	printf("Inserisci il numero n:\nn = ");
	scanf("%d", &num);
	p = fibo(num);
	
	for(int i = 0; i < num; i++){
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	
}
