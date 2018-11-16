#include<stdio.h>
void main()
{
int n,endtime,least,k=0,time,avg_wait=0,avg_tat=0;
printf("Enter the no. of processes:");
scanf("%d",&n);
int bur[n],arr[n],rem[10],i;
for(i=0;i<n;i++)
{
  printf("p%d",i+1);
  printf("\n");
  printf("Enter burst time");
  scanf("%d",&bur[i]);
  rem[i]=bur[i];
  printf("\n");
  printf("Enter arrival time:");
  scanf("%d",&arr[i]);
  printf("\n");
}
printf("Process burst_time tat_time wt_time\n");
rem[9]=9999;
for(time=0;k!=n;time++){
   least=9;
   for(i=0;i<n;i++){
      if(arr[i]<=time&&rem[i]<rem[least]&&rem[i]>0)
          least=i;
}
   rem[least]--;
   if(rem[least]==0){
       k++;
       endtime=time+1;
       printf("\nP[%d]\t|\t%d\t|\t%d\t|\t%d",least+1,bur[least],endtime-arr[least],endtime-bur[least]-arr[least]);
       avg_wait+=endtime-bur[least]-arr[least];
       avg_tat+=endtime-arr[least];
   }
}
printf("\n\nAverage waiting time = %f\n",avg_wait*1.0/n);
printf("Average Turnaround time = %f",avg_tat*1.0/5);
}
