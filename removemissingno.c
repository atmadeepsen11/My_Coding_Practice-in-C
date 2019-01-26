#include <stdio.h>
#include <stdlib.h>

int missingNumber(int a[], int length){
	
	if(length <= 1)
		return 0;
	int i,j;
	int x = a[0];
	int y = 1;
	for(i=1; i<length; i++)
		x = x^a[i];
	printf("after 1st loop ---> %d \n", x);

	for(j=2; j<=length+1; j++)
		y = y^j;
	printf("after 2nd loop ---> %d \n", y);
	return x^y;
}

int main(){
	int a[] = {1,2,3,4,5,6,7,9,10};
	int l = 9;
	int miss = missingNumber(a, l);
	printf("missing number in the sequence is %d \n", miss);
	return 0;
}


