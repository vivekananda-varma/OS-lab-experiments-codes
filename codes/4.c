#include<stdio.h>

void main()
{
  int p,r;
  printf("Enter no. of processes :");
  scanf("%d",&p);
  int tp=p;
  printf("Enter no. of resources: ");
  scanf("%d",&r);
  int i,j,maxr[r],alloc[p][r],max[p][r],avail[r],need[p][r];
  printf("Enter max reosurces: ");
  for(i=0;i<r;i++)
    scanf("%d",&maxr[i]);
    printf("Enter allocated resources: ");
  for(i=0;i<p;i++){
        printf("\n");
    for(j=0;j<r;j++){
        scanf("%d",&alloc[i][j]);
    }
  }
  printf("Enter maximum resources: ");
  for(i=0;i<p;i++){
        printf("\n");
    for(j=0;j<r;j++){
        scanf("%d",&max[i][j]);
    }
  }
  for(i=0;i<r;i++)
    scanf("%d",&avail[i]);
  for(i=0;i<p;i++){
    for(j=0;j<r;j++){
        need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  int count=0,finish[p],k,flag=0,safe[p];
  for(i=0;i<p;i++)
  finish[i]=0;
  while(count!=tp){
    for(i=0;i<p;i++){
        if(finish[i]==0){
                flag=0;
            for(j=0;j<r;j++){
                if(need[i][j]<=avail[j]){
                    flag++;
                }

            }
            if(flag==3)
            {
              for(j=0;j<r;j++)
              {
                avail[j]=avail[j]-need[i][j];
                avail[j]=avail[j]+max[i][j];
              }
              printf("P[%d] is executed!!",i+1);
              finish[i]=1;
              safe[count++]=i;
            }
        }

    }






  }
  printf("Safe sequence is:  ");
  for(i=0;i<p;i++){
    printf("<P(%d)>",safe[i]);
  }









}
