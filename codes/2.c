#include<stdio.h>
void main()
{
int n;
printf("Enter the no. of processes:");
scanf("%d",&n);
int bur[n],arr[n],pri[n],p[n],i;
int min,k=1,burst=0,temp,temp1,j,wt[n],tat[n],ta=0,sum=0;
float wait_avg,tat_avg,tatsum,waitsum;
for(i=0;i<n;i++)
{
  printf("p%d",i+1);
  p[i]=i+1;
  printf("\n");
  printf("Enter burst time");
  scanf("%d",&bur[i]);
  printf("\n");
  printf("Enter priority");
  scanf("%d",&pri[i]);
  printf("\n");
  printf("Enter arrival time");
  scanf("%d",&arr[i]);
  printf("\n");
}

for(i=0;i<n;i++){
  for(j=0;j<n;j++)
     {
      if(arr[i]<arr[j]){

            temp=p[j];
            p[j]=p[i];
            p[i]=temp;

            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;

            temp1=bur[j];
            bur[j]=bur[i];
            bur[i]=temp1;
         }
    }
}


for(j=0;j<n;j++){
     burst=burst+bur[j];
    min=bur[k];
    for(i=k;i<n;i++){
       min=pri[k];
       if (burst>=arr[i]){
           if(pri[i]<min){

                temp=p[k];
                p[k]=p[i];
                p[i]=temp;

                temp=arr[k];
                arr[k]=arr[i];
                arr[i]=temp;

                temp1=bur[k];
                bur[k]=bur[i];
                bur[i]=temp1;

                temp=pri[k];
                pri[k]=pri[i];
                pri[i]=temp;

            }
       }
   }
   k++;
}
  wt[0]=0;
  for(i=1;i<n;i++){
      sum=sum+bur[i-1];
      wt[i]=sum-arr[i];
  }
  for(i=0;i<n;i++){
       waitsum=waitsum+wt[i];
 }
   wait_avg=waitsum/n;
   for(i=0;i<n;i++){
       ta=ta+bur[i];
       tat[i]=ta-arr[i];
 }
   for(i=0;i<n;i++){
     tatsum=tatsum+tat[i];
 }
   tat_avg=tatsum/n;

  printf("Process\tburst_time\twt_time\ttat_time\n");
  for(i=0;i<n;i++)
  {
  printf("\np%d\t%d\t %d\t  %d",p[i],bur[i],wt[i],tat[i]);
  }
printf("\nAVERAGE WAITING TIME:-  %f ms",wait_avg);
printf("\nAVERAGE TURN AROUND TIME:-  %f ms" ,tat_avg);










}
