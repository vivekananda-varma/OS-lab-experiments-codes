
#include<stdio.h>

void main()
{
  int fr,n;
  printf("Enter no of elements in reference string: ");
  scanf("%d",&n);
  int ref[n];
  printf("Enter frame size: ");
  scanf("%d",&fr);
  printf("Enter reference string :");
  for(int i=0;i<n;i++)
    scanf("%d",&ref[i]);
  int page[fr];
  int i,j,flag,p=0,temp,d[fr],k,max,ptr;


  for(i=0;i<fr;i++)
    page[i]=ref[i];
  printf("First filled page table is: %d %d %d\n",page[0],page[1],page[2]);

  for(i=fr;i<n;i++)
  {
    flag=0;
    for(j=0;j<fr;j++)
       if(page[j]==ref[i])
          flag=1;

    if(flag==0)
    {
      for(j=0;j<fr;j++)
      {
        for(k=i-1;k>=0;k--)
        {
           if(page[j]==ref[k]){
              d[j]=i-k;
              break;
           }
        }
      }
      printf("%d %d %d\n",d[0],d[1],d[2]);
      max=d[0],ptr=0;
      for(j=1;j<fr;j++)
      {
        if(d[j]>max)
        {
          max=d[j];

          ptr=j;
        }
      }
      printf("%d\n",ptr);
      page[ptr]=ref[i];
    }
      printf("Page table is: %d %d %d\n",page[0],page[1],page[2]);









  }






}

