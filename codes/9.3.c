#include<stdio.h>

void main()
{
 int pno,bno;
 printf("Enter no. of processes: ");
 scanf("%d",&pno);
 printf("Enter no. of blocks: ");
 scanf("%d",&bno);
 int i,j,k,p[pno],b[bno];
 printf("Enter size of each process: ");
 for(i=0;i<pno;i++)
    scanf("%d",&p[i]);
 printf("Enter size of each block: ");
 for(i=0;i<bno;i++)
    scanf("%d",&b[i]);
 int all[bno];
 for(i=0;i<bno;i++)
    all[i]=-1;
 for(i=0;i<pno;i++)
 {
    for(j=0;j<bno;j++)
    {
        if(p[i]<=b[j])
        {
           all[i]=j;
           b[j]=b[j]-p[i];
           break;
        }


    }

 }
printf("process no\tprocess size\tblock no");
 for(i=0;i<pno;i++)
 {
   printf("%d\t%d\t",i+1,p[i]);
   if(all[i]==-1)
    printf("not allocated");
   else
   {
     printf("%d",all[i]+1);
   }
   printf("\n");



 }





}
