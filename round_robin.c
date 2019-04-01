#include<stdio.h> 
void round_robin(int n)
{
	int i; 
  int at[10],bt[10],rt[10]; 
  
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time for process %d :",i+1); 
    scanf("%d",&at[i]); 
    printf("Enter Burst Time for process %d :",i+1);
    scanf("%d",&bt[i]);
	
    rt[i]=bt[i]; 
  }
  printf("  ArrivalTime   BurstTime  Priority\n");
  for(i=0;i<n;i++)
  {
  	
	printf("%d            %d           %d\n",at[i],bt[i]);
  }
}
int main() 
{ 
int n,remain_process; 
  printf("Enter number of Process:\t "); 
  scanf("%d",&n); 
    
 round_robin(n);
}
