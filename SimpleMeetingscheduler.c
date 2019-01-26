#include <stdio.h>

#define ROWS 4

void meetingTime(int scheduledTime[ROWS][2], int times){
    if(times == 0)
    {
        return;
    }
    int i, temp;
	int res[2];
    for(i=1; i<ROWS; i++)
	{
	//    int diff = scheduledTime[i][0] - scheduledTime[i-1][1];
	//    printf(" %d - %d  = %d \n", scheduledTime[i][0], scheduledTime[i-1][1], diff);
		if((scheduledTime[i][0] - scheduledTime[i-1][1]) >= times)
		{
		    
			res[0] = scheduledTime[i-1][1] + 1;
			res[1] = res[0] + times;
			printf("[ %d, %d ] \n", res[0], res[1]);
			return;
		}
		else
			continue;
	}
	printf("TOO BUSY SCHEDULE \n");
}
int main()
{
	int i;
	int schedules[ROWS][2] = { {800, 945}, {1000, 1245}, {1350, 1402}, {1449, 1500} };
    int *re s;
	meetingTime(schedules, 100);
	for(i=0; i<2; i++)
	{
		printf("[ %d, %d ] \n", res[i]);
	}
    return 0;
}