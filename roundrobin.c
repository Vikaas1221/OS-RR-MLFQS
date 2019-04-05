#include<stdio.h> 
void round_robin(int n)
{
	int i,j,time,remain_process,time_quantum,m; 
	remain_process=n;
  int wait_time=0,turnaround_time=0,arrive_t[10],burst_t[10],rem_t[10]; 
  
  
  for(i=0;i<n;i++) 
  { 
    printf("Enter Arrival Time for process %d :",i+1); 
    scanf("%d",&arrive_t[i]); 
    printf("Enter Burst Time for process %d :",i+1);
    scanf("%d",&burst_t[i]);
	
    rem_t[i]=burst_t[i]; 
  }
  printf("Process   ArrivalTime   BurstTime  \n");
  for(i=0;i<n;i++)
  {
  	
	printf("P[%d]   %d            %d           \n",i+1,arrive_t[i],burst_t[i]);
  }
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess ArrivalTime BurstTime Turnaround_t Waiting_t \n\n"); 
  for(time=0,i=0;remain_process!=0;) 
  { 
    if(rem_t[i]<=time_quantum && rem_t[i]>0) 
    { 
      time=time+rem_t[i]; 
      rem_t[i]=0; 
      m=1;
    }  
    else if(rem_t[i]>0) 
    { 
      rem_t[i]=rem_t[i]-time_quantum; 
      time=time+time_quantum; 
    } 
    if(rem_t[i]==0&& m==1) 
    { 
      remain_process--; 
      printf("P[%d]         %d         %d         %d         %d\n",i+1,arrive_t[i],burst_t[i],time-arrive_t[i],time-arrive_t[i]-burst_t[i]); 
      wait_time=wait_time+time-arrive_t[i]-burst_t[i]; 
      turnaround_time=turnaround_time+time-arrive_t[i]; 
      m=0;
    } 
    if(i==n-1) 
      i=0; 
    else if(arrive_t[i+1]<=time) 
      i++; 
    else 
      i=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n);
}
int main() 
{ 
int n,remain_process; 
  printf("Enter number of Process:\t "); 
  scanf("%d",&n); 
    
 round_robin(n);
}
