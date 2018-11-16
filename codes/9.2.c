#include<stdio.h>

void main()
{
  int pno,bno;
  printf("Enter no. of processes: ");
  scanf("%d",&pno);
  printf("Enter no. of blocks: ");
  scanf("%d",&bno);
  int p[pno],b[bno],i,j;
  printf("Enter size of each process: ");
  for(i=0;i<pno;i++)
    scanf("%d",&p[i]);
    printf("enter size of each block");
  for(i=0;i<bno;i++)
    scanf("%d",&b[i]);
  int all[bno];
  for(i=0;i<bno;i++)
    all[i]=-1;
   int flag;
  for(i=0;i<pno;i++)
  {
      flag=-1;
    for(j=0;j<bno;j++)
    {
       if(b[j]>=p[i])
       {
         if(flag==-1)
                flag=j;
         else if(b[flag]<b[j])
            flag=j;
       }
    }
    if(flag!=-1)
    {
      all[i]=flag;
      b[flag]=b[flag]-p[i];
    }
  }

  printf("process no\tprocess size\tblock no\n");
  for(i=0;i<pno;i++)
  {
     printf("%d\t%d\t",i+1,p[i]);
     if(all[i]!=-1)
        printf("%d",all[i]+1);
     else
        printf("not allocated");
     printf("\n");
  }











}
