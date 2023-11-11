#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 513
#define ASCII_0 48
#define ASCII_A 65


int my_strtoi(char * s, int base){
	int res, digit, len, exp, ascii, cond;
	if(base <= 10){
		ascii = ASCII_0;
		cond = ASCII_0 + base;
	}else{
		ascii = ASCII_0 + 7;
		cond = ASCII_A + base;
	}
	res = 0;
	for(len = 0; s[len] != '\n' && cond; len++){
		if(s[len] < cond && (s[len] >= 58 && s[len] <= 64)){
			cond = 0;
			printf("Numero non accettato per questa base\n");
			return -1;
			
		}
	}
	for(int i = 0; s[i] != '\n'; i++){
		exp = len - i;
		digit = ((int) s[i] - ascii);
		for(int j = 0; j < exp - 1; j++){
			digit *= base;
		}
		res += digit;
	}
	printf("\n");
	return res;
}

int my_bstrtoi(char * s, int base){
	return my_strtoi(s, base);
}

int main(){
	int base, cond;
	char * str = malloc(MAX_LEN * sizeof(*str));
	char * num = malloc(MAX_LEN * sizeof(*num));
	int res;
	printf("Scrivi un numero compreso tra 2 e 36\n");
	fgets(num, MAX_LEN, stdin);
	base = atoi(num);
	cond = base >= 2 && base <= 36;
	while(!cond){
		printf("Valore non valido! Riprovare\n");
		printf("Scrivi un numero compreso tra 2 e 36\n");
		fgets(num, MAX_LEN, stdin);
		base = atoi(num);
		cond = base >= 2 && base <= 36;
	}
	free(num);
	printf("Scrivi un numero:\n");
	fgets(str, MAX_LEN, stdin);
	res = my_bstrtoi(str, base);
	printf("res: %d\n", res);
	free(str);
}
