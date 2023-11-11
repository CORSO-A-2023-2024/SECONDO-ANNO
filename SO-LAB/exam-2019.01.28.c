#include <stdio.h>
#include <stdlib.h>

int range_of_even ( int * nums , int length , int * min , int * max ) {
	int res = 0;
	int count = 0;
	printf("\ninitial *min: %d\ninital max: %d\n", *min, *max);
	for(int i = 0; i < length; i++){
		if(nums[i] % 2 == 0){
			if(count == 0){
				*min = nums[i]; 
				*max = nums[i];
			}else{
				*min = (nums[i] < *min) ? nums[i] : *min;
				*max = nums[i] > *max ? nums[i] : *max;
			}
			count++;
		}
	}
	printf("\nmin: %d\nmax: %d\n", *min, *max);
	res = count != 0 ? 1 : 0;
	return res;
}

int main(){
	int length, num, min, max,res = 0;
	printf("Metti la quantità di numeri da inserire\n");
	scanf("%d", &length);
	int nums [length];
	for(int i = 0; i < length; i++){
		printf("Metti un numero: ");
		scanf("%d", &num);
		nums[i] = num;
	}
	int * minP = &min;
	int * maxP = &max;
	
	res = range_of_even(nums, length, minP, maxP);
	printf("%d\n", res);

}
