#include <stdio.h>

int tidy_num(int num);
int pow1(int x,int n);


int tidy_num(int num)
{
    int dig, quo, prev, curr, new_num = num, count = 1;
    while(num/10 > 0)
    {
        prev = num % 10; quo = num/10;
        curr = quo % 10;
        if(prev < curr)
        {
            new_num = (quo * pow1(10, count)) - 1;
        }
        num = num/10;
        count++;
    }
    printf("%d",new_num);
}

int pow1(int x,int n)
{
    int i; /* Variable used in loop counter */
    int number = 1;

    for (i = 0; i < n; ++i)
        number *= x;

    return(number);
}

int main() {
	tidy_num(43);
	return 0;
}