#include<stdio.h>

void main()
{
   int i,j,fr,n;
   printf(" Enter frame size: ");
   scanf("%d",&fr);
   printf(" Enter reference string size: ");
   scanf("%d",&n);
   printf(" Enter reference string: ");
   int ref[n];
   for(i=0;i<n;i++)
       scanf("%d",&ref[i]);
   int page[fr];
   for(i=0;i<fr;i++)
    page[i]=ref[i];
   printf("First page table reference: %d %d %d\n",page[0],page[1],page[2]);
   int flag=0,k,d[fr];
   for(i=fr;i<n;i++)
   {
       flag=0;
     for(j=0;j<fr;j++)
     {
       if(page[j]==ref[i])
          flag=1;
     }
     if(flag==0)
     {
        for(j=0;j<fr;j++)
        {
          for(k=i+1;k<n;k++)
          {
            if(page[j]==ref[k])
            {
              d[j]=k-i;
              break;
            }

          }

        }
       int max=d[0],p=0;
       for(j=1;j<fr;j++)
       {
         if(max<d[j]){
            p=j;
            max=d[j];
       }
       }
       page[p]=ref[i];
     }
      if(flag==0)
       printf("page reference table is: %d %d %d\n",page[0],page[1],page[2]);
     else
        printf("page hit!!!\n");





   }

}
