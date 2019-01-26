#include <stdio.h>


/*
int divide(int dividend, int divisor) {
    int c = 0;
    int i, flag;
    int sum = dividend;

    if(dividend < 0 && divisor > 0 ){
        if(divisor == 1)
            return dividend;
        while((sum += divisor)<=0){
            flag = 0;
            c++;
        }
    }
    else if (dividend > 0 && divisor < 0){
        if(divisor == -1)
            return -dividend;
        while((sum += divisor)>=0){
            flag = 0;
            c++;
        }
    }
    else if(dividend > 0 && divisor > 0){
        if(divisor == 1)
            return dividend;
        while((sum -= divisor)>=0){
            flag = 1;
            c++;
        }
    }
    else if(dividend < 0 && divisor < 0){
        if(divisor == -1)
            return -dividend;
        while((sum -= divisor)<=0){
            flag = 1;
            c++;
        }
    }
    if(flag == 1)
        return c;
    else
        return -c;
}
*/


int main()
{
    int n = divide(-100, -1);
    printf("\n %d \n", n);

    return 0;
}