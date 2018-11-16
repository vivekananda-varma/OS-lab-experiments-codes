// THIS CODE BELONGS TO 17BCI0104
#include<stdio.h>

int fcfs(int n,int* bt)
{
    printf("/////FIRST COME FIRST SERVE////\n");
    int i,j,k,wt[n],tat[n],avgwt=0,avgtat=0;
    wt[0]=0;
    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];
    printf("Process burst_time wt_time tat_time\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avgwt=avgwt+wt[i];
        avgtat=avgtat+tat[i];
        printf("p%d\t %d\t  %d\t   %d",i+1,bt[i],wt[i],tat[i]);
        printf("\n");
    }
    printf("Average wait time:%f\n",(float)avgwt/(float)n);
    printf("Average tata time:%f\n",(float)avgtat/(float)n);
    printf("\n\n\n");

   return avgwt;
}

int sjf(int n,int* bt)
{
      printf("/////SHORTEST JOB FIRST////\n");
     int i,j,wt[n],tat[n],avgwt=0,avgtat=0,p[n],temp,pos;
     for(i=0;i<n;i++)
         p[i]=i+1;
     for(i=0;i<n;i++){
         pos=i;
     for(j=i+1;j<n;j++){
        if(bt[pos]>bt[j]){
            pos=j;
        }
        temp=bt[pos];
        bt[pos]=bt[i];
        bt[i]=temp;

        temp=p[pos];
        p[pos]=p[i];
        p[i]=temp;
    }
}
     wt[0]=0;
     for(i=1;i<n;i++)
         wt[i]=wt[i-1]+bt[i-1];
     printf("Process burst_time wt_time tat_time\n");
     for(i=0;i<n;i++){
         tat[i]=bt[i]+wt[i];
         avgwt=avgwt+wt[i];
         avgtat=avgtat+tat[i];
         printf("p%d\t %d\t  %d\t   %d",p[i],bt[i],wt[i],tat[i]);
         printf("\n");
    }
     printf("Average wait time:%f\n",(float)avgwt/(float)n);
     printf("Average tata time:%f\n",(float)avgtat/(float)n);
     printf("\n\n\n");

  return avgwt;
}

int priority(int n,int* bt,int* pri)
{
      printf("/////PRIORITY////\n");
     int i,j,wt[n],tat[n],avgwt=0,avgtat=0,p[n],temp,pos;
     for(i=0;i<n;i++)
         p[i]=i+1;
     for(i=0;i<n;i++){
         pos=i;
     for(j=i+1;j<n;j++){
        if(pri[pos]>pri[j]){
            pos=j;
        }

        temp=pri[pos];
        pri[pos]=pri[i];
        pri[i]=pri[pos];

        temp=bt[pos];
        bt[pos]=bt[i];
        bt[i]=temp;

        temp=p[pos];
        p[pos]=p[i];
        p[i]=temp;
    }
}
     wt[0]=0;
     for(i=1;i<n;i++)
         wt[i]=wt[i-1]+bt[i-1];
     printf("Process burst_time wt_time tat_time\n");
     for(i=0;i<n;i++){
         tat[i]=bt[i]+wt[i];
         avgwt=avgwt+wt[i];
         avgtat=avgtat+tat[i];
         printf("p%d\t %d\t  %d\t   %d",p[i],bt[i],wt[i],tat[i]);
         printf("\n");
    }
     printf("Average wait time:%f\n",(float)avgwt/(float)n);
     printf("Average tata time:%f\n",(float)avgtat/(float)n);
     printf("\n\n\n");

    return avgwt;
}

int rr(int n,int* bt,int q)
{
    printf("/////ROUND ROBIN////\n");
   int wt[n],tat[n],avgwt=0,avgtat=0,p[n],t=0;
   int dbt[n],i,j,flag=0;
   for(i=0;i<n;i++){
      dbt[i]=bt[i];
      p[i]=i+1;
}
   while(1){
      flag=0;

      for(i=0;i<n;i++){
          if(dbt[i]>0){
               flag=1;
               if(dbt[i]>q){
                    t=t+q;
                    dbt[i]=dbt[i]-q;
    }
               else{
                    t=t+dbt[i];
                    wt[i]=t-bt[i];
                    dbt[i]='\0';
    }
 }

}
   if(flag==0)
      break;
}
   for(i=0;i<n;i++)
       tat[i]=bt[i]+wt[i];

   printf("Process burst_time wt_time tat_time\n");
   for(i=0;i<n;i++){
      avgwt=avgwt+wt[i];
      avgtat=avgtat+tat[i];
      printf("p%d\t %d\t  %d\t   %d",p[i],bt[i],wt[i],tat[i]);
      printf("\n");
    }
    printf("Average wait time:%f\n",(float)avgwt/(float)n);
    printf("Average tata time:%f\n",(float)avgtat/(float)n);
    printf("\n\n\n");

  return avgwt;
}

void main()
{
int n,a,b,c,d,q;
printf("Enter the no. of processes:");
scanf("%d",&n);
int bur[n],pri[n],i,j,k;
for(i=0;i<n;i++)
{
  printf("p%d",i+1);
  printf("\n");
  printf("Enter burst time");
  scanf("%d",&bur[i]);
  printf("\n");
  printf("Enter priority");
  scanf("%d",&pri[i]);
  printf("\n");
}
printf("Enter quantum:");
scanf("%d",&q);
printf("\n");
a=fcfs(n,bur);
b=sjf(n,bur);
c=rr(n,bur,q);
d=priority(n,bur,pri);
if(a<b && a<c && a<d)
    printf("Best Cpu Schedulling is FCFS!!!");
else if(b<a && b<c && b<d)
    printf("Best Cpu Schedulling is SJF!!!");
else if(c<b && c<a && c<d)
    printf("Best Cpu Schedulling is RR!!!");
else if(d<b && d<c && d<a)
    printf("Best Cpu Schedulling is priority!!!");
else
    printf("More than one are good for schedulling");
}
