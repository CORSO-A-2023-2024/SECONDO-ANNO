#include <stdio.h>
#include <math.h>
#define MAX_LEN 513
#define ASCII_0 48
#define ASCII_9 57


int my_strtoi(char * s){
	int res, digit, len, exp;
	res = 0;
	for(len = 0; s[len] != '\n'; len++);
	for(int i = 0; s[i] != '\n'; i++){
		exp = len - i;
		digit = ((int) s[i] - ASCII_0);
		for(int j = 0; j < exp - 1; j++){
			digit *= 10;
		}
		res += digit;
	}
	return res;
}

int main(){
	char * str;
	int res;
	fgets(str, MAX_LEN, stdin);
	res = my_strtoi(str);
	printf("%d\n", res);
}
