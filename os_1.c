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
