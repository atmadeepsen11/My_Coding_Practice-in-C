#include <stdio.h>
#include <stdlib.h>

void decToHexa(int n) 
{    
    // char array to store hexadecimal number 
    char hexaDeciNum[100]; 
      
    // counter for hexadecimal number array 
    int i = 0; 
    while(n!=0) 
    {    
        // temporary variable to store remainder 
        int temp  = 0; 
          
        // storing remainder in temp variable. 
        temp = n % 16; 
          
        // check if temp < 10 
        if(temp < 10) 
            hexaDeciNum[i] = temp + 48; 
        else
            hexaDeciNum[i] = temp + 55;  
        
        n = n/16;
		i++;
    } 
      
    // printing hexadecimal number array in reverse order 
    for(int j=i-1; j>=0; j--) 
        printf( "%d\n",hexaDeciNum[j]); 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n = 2545; 
      
    decToHexa(n); 
      
    return 0; 
} 