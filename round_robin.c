#include<stdio.h> 
void round_robin(int n)
{
	int i,c; 
  int at[10],bt[10],rt[10],pt[10]; 
  
  for(c=0;c<n;c++) 
  { 
    printf("Enter Arrival Time for process %d :",c+1); 
    scanf("%d",&at[c]); 
    printf("Enter Burst Time for process %d :",c+1);
    scanf("%d",&bt[c]);
    printf("Enter Priority of process for process %d :",c+1);
	scanf("%d",&pt[c]);
	
    rt[c]=bt[c]; 
  }
  printf("  ArrivalTime   BurstTime  Priority\n");
  for(c=0;c<n;c++)
  {
  	
	printf("%d            %d           %d\n",at[c],bt[c],pt[c]);
  }
}
int main() 
{ 
int n,remain_process; 
  printf("Enter number of Process:\t "); 
  scanf("%d",&n); 
    
 round_robin(n);
}
