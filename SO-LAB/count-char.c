#include <stdio.h>
#include <stdlib.h>

int countChar(char c, int len, char * v){
	int count = 0;
	for(int e = 0; e < len && v[e] != '\0'; e++){
		if(v[e] == c){count++;}
	}
	return count;
}

int main(){
	char v [200];
	int len;
	
	fgets(v, sizeof(v), stdin);
	
	for(int i = 0; i < sizeof(v) && v[i] != 10; i++){
		if(v[i] != v[i+1]){
			printf("%d, %c\n", countChar(v[i], sizeof(v), v), v[i]);
		}
	}
	
}
