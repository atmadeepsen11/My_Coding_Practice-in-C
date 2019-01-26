#include <stdio.h>
#include <stdlib.h>

int sums(int a[], int start, int end);

int eq(int a[], int n){
    int i = 0, j = 2;
    int sumL, sumR;
    int mid = 1;
    while(sumR != sumL){
        sumR = sums(a, j, n);
        sumL = sums(a, i, mid);
        printf("sumL %d == sumR %d \n", sumL, sumR);
        j++;
        mid++;
    }
    return mid-1;
}


int sums(int a[], int start, int end){
    
    int i;
    int sum=0;
    for(i=start; i<end; i++){
        sum+=a[i];
    }
    return sum;
}

int main()
{
    int a[] = {1,7,3,6,5,6};
    int n = sizeof(a)/sizeof(a[0]);
    printf("max sum is %d \n", eq(a, n));

    return 0;
}