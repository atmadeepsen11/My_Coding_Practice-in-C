#include<stdio.h>
#define INFINITY 100000

//count the number of set bits
int countSetBits(int n) 
{ 
    int count = 0; 
    while (n) 
    { 
        count += n & 1; 
        n >>= 1; 
    } 
    return count; 
} 
  
int findNth(int x){
    int i = 0;
    int n = 3;
    while(n < INFINITY){
		//check if the number has 2 bits set
        if(countSetBits(n) == 2){
                i++;
                if(i == x)
                    break;
        }
        n++;
 //       printf("i = %d, n = %d \n", i, n);
    }
    printf("%d", n);
    return n;
}
 int main()
 {
    int num = 8;
    findNth(num);

}