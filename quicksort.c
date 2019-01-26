#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int p, int r);

void quicksort(int a[], int p, int r)
{
	int q;
	if(p<r)
	{
		q = partition(a, p, r);
		quicksort(a, p, q-1);
		quicksort(a, q+1, r);
	}
}

int partition(int a[], int p, int r)
{
	int x = a[r];
	int i = p-1;
	int j;
	for(j=p; j<r; j++)
	{
		if(a[j] <= x){
			i++;
		    swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[r]);
	return i+1;
}	

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int i;
	int a[] = {3,12,9,14,1};
	int n = sizeof(a)/a[0];
	quicksort(a, 0, n-1);
	for(i=0; i<n; i++){
		printf("%d \n", a[i]);
	}
	return 0;
}


