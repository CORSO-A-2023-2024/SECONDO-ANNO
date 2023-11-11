#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 64
#define MIN_AGE 0
#define MAX_AGE 100

typedef struct {
		char * name;
		int age;
} record;

void rec_free(record * p, int n){
	for(int i = 0; i < n; i++){
		free(p[i].name);
	}
	free(p);
}

void rec_sort(record * p, int n){
	record swap;
	for(int i = 0; i < (n-2); i++){
		for(int j = i+1; j < (n-1); j++){
			if(p[j].age < p[i].age){
				swap = p[j];
				p[j] = p[i];
				p[i] = swap;
			}
		}
	}
}

void rec_print(record * p, int n){
	printf("[\n");
	for(int i = 0; i < n; i++){
		printf("{\nname: %s;\nage: %d;\n}\n\n", p[i].name, p[i].age);	
	}
	printf("]\n\n");
}

record * rec_rand_create(int n){
	record * p = malloc(n*sizeof(*p));
	char * alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	int alphLen = 0;
	for(; alphabet[alphLen] != '\0'; alphLen++);
	for(int j = 0; j < n; j++){
		int nameLen = rand() % MAX_LEN;
		p[j].name = malloc(nameLen * sizeof(*p[j].name));
		for(int i = 0; i < nameLen - 1; i++){
			p[j].name[i] = alphabet[rand() % alphLen];
		}
		p[j].name[nameLen-1] = '\0';
		
		p[j].age = rand() % MAX_AGE;
	}
	printf("size of array of records: %d\n", sizeof(*p));
	return p;
	
}

int main(){
	int num;
	printf("Metti un numero: ");
	scanf("%d", &num);
	record * r = rec_rand_create(num);
	printf("Prima di rec_sort():\n");
	rec_print(r, num);
	rec_sort(r, num);
	printf("Dopo rec_sort():\n");
	rec_print(r, num);
	rec_free(r, num);
}
