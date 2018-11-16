#include<stdio.h>

void main()
{
  int ind;
  x:
  printf("Enter index block: ");
  scanf("%d",&ind);
  int f[50],index[50],i,j,k;
  for(i=0;i<50;i++)
    f[i]=0;
  int n,count;
  if(f[ind]!=1)
  {
    printf("enter no. of blocks needed for index: ");
    scanf("%d",&n);
  }
  else{
    printf("index is already allocated!");
    goto x;
  }
    y:
    count=0;
    for(i=0;i<n;i++)
    {
      scanf("%d",&index[i]);
      if(f[index[i]]==0)
         count++;
    }
    if(count==n)
    {
      for(j=0;j<n;j++)
         f[index[j]]=1;
         printf("allocated\n");
         printf("file indexed\n");
      for(j=0;j<n;j++)
        printf("%d-->%d: %d\n",ind,index[j],f[index[j]]);


    }
    else{
        printf("file in the index is already allocated");
        goto y;
    }











}
