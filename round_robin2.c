#include<stdio.h> 
void round_robin(int n)
{
	int i,j,time,remain_process,time_quantum; 
	remain_process=n;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10]; 
  
  
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
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,i=0;remain_process!=0;) // while burst time is greater than 0 it will process
  { 
    if(rt[i]<=time_quantum && rt[i]>0) // burst time is less than time_quantum
    { 
      time=time+rt[i]; // increases value of time i.e how much time process is processed
      rt[i]=0; // as the remaining burst time is complte so make it zero
      //m=1;
    }  
    else if(rt[i]>0) // if burst_time is greater than 0 ,process are left
    { 
      rt[i]=rt[i]-time_quantum; // decrease the burst time by time quantum
      time=time+time_quantum; // how much time a process has proceesd
    } 
    if(rt[i]==0) 
    { 
      remain_process--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      wait_time=wait_time+time-at[i]-bt[i]; 
      turnaround_time=turnaround_time+time-at[i]; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
}
int main() 
{ 
int n,remain_process; 
  printf("Enter number of Process:\t "); 
  scanf("%d",&n); 
    
 round_robin(n);
}
