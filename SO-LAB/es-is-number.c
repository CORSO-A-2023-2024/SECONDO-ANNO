#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 257

int isNumber(char * s, long * start, long * end){
	printf("*start: %d\n*end: %d\n", *start, *end);
	int i = 0;
	char * endptr;
	int res;
	for(; i < (int) *end; i++){
		if(i < *start){
			s[i] = 0;
		}
	}
	s[i] = 0;
	res = strtol(s, &endptr, 10);
	if(*endptr == '\0'){
		printf("La sottotringa %s è un numero\n",s);
	}else{
		printf("La sottotringa %s non è un numero\n",s);
	}
	return *endptr == '\0';
}

int main(){
	char string [STR_LEN];
	char num [STR_LEN];
	long a, b;
	int len, cond, res;
	char * endptr;
	printf("Scrivi la stringa:\n");
	fgets(string, STR_LEN, stdin);
	for(len = 0; string[len] != 10; len++);
	len--;
	printf("Immetti un numero da 0 a %d:\n", len);
	fgets(num, STR_LEN, stdin);
	a = strtol(num, &endptr, 10);
	cond = (a >= 0 && a <= len);
	while(!cond){
		printf("Valore non valido\n");
		fgets(num, STR_LEN, stdin);
		a = strtol(num, &endptr, 10);
		cond = (a >= 0 && a <= len);
	}
	printf("Immetti un numero da %d a %d:\n", a, len);
	fgets(num, STR_LEN, stdin);
	b = strtol(num, &endptr,10);
	cond = (b >= a && b <= len);
	while(!cond){
		printf("Valore non valido\n");
		fgets(num, STR_LEN, stdin);
		b = strtol(num, &endptr, 10);
		cond = (b >= a && b <= len);
	}
	res = isNumber(string, &a, &b);
} 
