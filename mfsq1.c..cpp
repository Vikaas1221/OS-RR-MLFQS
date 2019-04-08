#include<stdio.h>
#include<stdlib.h>
int burst[4];
int rem[4],n;
int time, timeQuantum1, timeQuantum2, count = 0,totalProcess;

void RR1()
{
	timeQuantum1 = 8;
	for (count = 0; count < totalProcess; count++)
	{
		if (rem[count] <= timeQuantum1 && rem[count] > 0)
		{
			time = time + rem[count];
			rem[count] = 0;
			printf("----------\n");
			printf("P[%d] completed in 1st RoundRobin algorithm. \nTurn around time is %d \nWaiting time is %d.\n", count, time, time - burst[count]);
		}
		else if (rem[count] > 0)
		{
			rem[count] = rem[count] - timeQuantum1;
			time = time + timeQuantum1;
		}
	}


}
int main()
{
	
printf("enter number of process");
scanf("%d",&n);
int rem[n],burst[n],p;

for(count=0;count<totalProcess;count++)
{
	printf("enter burst time for process%d",count+1);
	scanf("%d",burst[count]);
	rem[count]=burst[count];
}
for(count=0;count<totalProcess;count++)
{
	printf("p[%d]\t\tBurst time %d",count+1,burst[count+1]);
}

	printf("\n");

	RR1(); 
	
	system("pause");
	return 0;
}
