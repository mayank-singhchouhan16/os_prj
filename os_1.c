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
void ms(int n,int rt[10],int Time,int At[10])
{
float agwait,agtat;
    int m=n, w_time[10],count[10],tut_t[10],b_t[10],loc,temp,total=0;
  for(int i=0;i<m;i++)
    {
        b_t[i]=rt[i];
        w_time[i]=Time-At[i]-b_t[i];
		count[i]=i+1;
    }

    for(int i=0;i<m;i++)
    {
        loc=i;
        for(int j=i+1;j<m;j++)
        {
            if(b_t[j]<b_t[loc])
            	loc=j;
        }
        temp=b_t[i];
        b_t[i]=b_t[loc];
        b_t[loc]=temp;
        temp=count[i];
        count[i]=count[loc];
        count[loc]=temp;
    }

    for(int i=1;i<m;i++)
    {
        for(int j=0;j<i;j++)
        	w_time[i]+=b_t[j];
        total+=w_time[i];
    }
    agwait=(float)total/m;
    total=0;
    printf("\nProcess\twaiting time\tTurnaround Time");
    for(int i=0;i<m;i++)
    {
        tut_t[i]=b_t[i]+w_time[i];
        total=total + tut_t[i];
        printf("\nP[%d]\t%d\t\t%d\n",count[i],w_time[i],tut_t[i]);
    }
    agtat=(float)total/m;
    printf("\nAverage waiting time = %0.2f",agwait);
    printf("\nAverage turnaround time = %0.2f",agtat);
}

