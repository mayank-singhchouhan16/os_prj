#include<stdio.h>
void ms(int n,int rt[10],int Time,int At[10]);
int main()
{
 int count,j,n,time,remain,flag=0,time_quantum,x=1;
  int wait_time=0,turnaround_time=0,At[10],bt[10],rt[10];
  printf("Enter total number of process: ");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for Process%d\n",count+1);
    scanf("%d",&At[count]);
    scanf("%d",&bt[count]);
    rt[count]=bt[count];
  }
  printf("Enter Time Quantum: ");
  scanf("%d",&time_quantum);
 for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
        rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      wait_time+=time-At[count]-bt[count];
      turnaround_time+=time-At[count];
      flag=0;
    }
    if(count==n-1)
    {
        x++;
			if(x==2){
				count=0;
				time_quantum=6;
			}
			else
				break;
    }
    else if(At[count+1]<=time)
      count++;
    else
      count=0;
  }
  ms(n,rt,time,At);
}
