#include <stdio.h>
#include <stdlib.h>
int SieveOfEratosthenes(int n) 
{ 
    int prime[n+1]; 
    int i, count = 0;
    
    for(i=0; i<=n; i++){
        prime[i] = 1;
    }

    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == 1) 
        { 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = 0; 
        } 
    } 
  
    for (int p=2; p<=n; p++){ 
       if (prime[p]){ 
            printf("%d \n", p);
            count++;
        }
    }
    return count;
}

int main() 
{ 
    int n = 14; 
    int c = SieveOfEratosthenes(n);
    printf("\n %d", c);
    return 0; 
}   