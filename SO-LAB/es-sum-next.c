#include <stdio.h>
#include <stdlib.h>
#define LEN 10

int main(){
	char a [2000];
	int nums [LEN];
	int v2 [LEN] = {0};
	
	/*Ciclo for per la lettura degli interi*/
	for(int i = 0; i < LEN; i++){
		fgets(a, sizeof(a), stdin);
		nums[i] = strtol(a, NULL, 10);
	}
	
	printf("%s ", "Questi sono i numeri inseriti:");
	for(int l = 0; l < LEN; l++){
		printf("%d ", nums[l]);
	}
	printf("\n");
	
	printf("%s ", "Questo è v2 prima:");
	for(int h = 0; h < LEN; h++){
		printf("%d ", v2[h]);
	}
	printf("\n");
	
	/*Ciclo for per la costruzione di v2*/
	printf("%s ", "Questo è v2:");
	for(int j = 0; j < LEN; j++){
		for(int k = j; k < LEN; k++){
			v2[j] += nums[k]; 
		}
		printf("%d ", v2[j]);
	}
	printf("\n");
	
	
}
