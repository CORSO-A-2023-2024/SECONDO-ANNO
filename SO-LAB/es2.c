#include <stdio.h>
#include <stdlib.h>
#define LEN 7

int main(){
	char a [2000];
	char c;
	int nums [LEN];
	printf("%s\n", "Inserisci un numero e premi invio: ");
	for(int i = 0; i < LEN; i++){
		fgets(a, sizeof(a), stdin);
		nums[i] = strtol(a, NULL, 10);
	}
	printf("%s ", "Lista di numeri:");
	for(int j = 0; j < LEN; j++){
		if(j % 2 != 0)
			printf("%i ", nums[j]);
	}
	for(int l = 0; l < LEN; l++){
		if(l % 2 == 0)
			printf("%i ", nums[l]);
	}
	printf("\n");

}
