#include <stdio.h>

int count = 0;
int caoticSeq(int n){
	int num = count;
	if(n == 1){
		printf("%d\n", n);
		count++;
	}else{
		if(n % 2 == 0){
			printf("%d ", n);
			caoticSeq(n / 2);
			count++;
		}else{
			printf("%d ", n);
			caoticSeq(3*n + 1);
			count++;
		}
	}
	return count - num;
}

int main(){
	int n;
	printf("Immettere un numero:\n");
	scanf("%d", &n);
	printf("\n");
	for(int i = 1; i <= n; i++){
		printf("caoticSeq(%d) length: %d\n", i, caoticSeq(i));
	}
}
