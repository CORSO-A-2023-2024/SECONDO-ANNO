#include <stdio.h>
#define MASK 0x7ff0000000000000

int main(){
	double num;
	unsigned long * p; 
	scanf("%lf", &num);
	p = (unsigned long *) &num;
	*p &= MASK;
	*p >>= 52;
	*p -= 1023;
	printf("number: %d\n", num);
	printf("exp: %ld\n:", *p); 

}
