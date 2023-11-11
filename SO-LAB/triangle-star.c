#include <stdio.h>

int main(){
	int b, h;
	printf("Metti la base:\n");
	scanf("%d", &b);
	printf("Metti l'altezza:\n");
	scanf("%d", &h);
	printf("\n");
	for(int i = 1; i <= h; i++){
		for(int j = 0; j < ((b-1)*i+h-b)/(h-1); j++){
			printf("*");
		}
		printf("\n");
	}
}
