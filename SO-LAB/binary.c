#include <stdio.h>
#define NUM_BITS (sizeof(n)*8)
#define MOST_SIG_BIT1 ((unsigned long)1 << (NUM_BITS-1))

struct mask {
	unsigned long mask;
	int length;
};

struct mask rightMask(int n){
	int i = 32;
	struct mask mask = {MOST_SIG_BIT1, 0};
	for (; !(mask.mask & n); mask.mask >>= 1){
		i--;
	}
	mask.length = i;
	return mask;
}

void convertToBinary(int n){
	int copy = n;
	int * p;
	struct mask mask = rightMask(n);
	for(int i = mask.length - 1; mask.mask; i--){ 
		//I use i as offset
		copy = n;
		p = &copy;
		*p &= mask.mask;
		*p >>= i;
		mask.mask >>= 1;
		printf("%d",*p);
	}
	printf("\n");
} 

int main(){
	int n;
	scanf("%i", &n);
	printf("number: %i\n", n);
	printf("size: %d\n" ,sizeof(n));
	convertToBinary(n);
	printf("\n");
	printf("number: %i\n", n);
}
