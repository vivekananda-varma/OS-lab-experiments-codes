#include<stdio.h>
#include<stdlib.h>
void main()
{
  int i,j,k,st,len,count,f[50];
  for(i=0;i<50;i++)
    f[i]=0;
  x:
      count=0;
      printf("Enter starting block: ");
      scanf("%d",&st);
      printf("Enter length: ");
      scanf("%d",&len);
      for(i=st;i<(st+len);i++)
        if(f[i]==0)
          count++;
      if(count==len)
      {
        for(j=st;j<(st+len);j++)
        {
          if(f[j]==0){
          f[j]=1;
          printf("%d-->%d \n",j,f[j]);
          }

        }
        if(j==(st+len))
            printf("File is allocated!!");

      }
      else
        printf("not allocated due to lack of space.");
      printf("For more allocation press 1 or else press 0: ");
      int ch;
      scanf("%d",&ch);
      if(ch==1)
        goto x;
      else
        exit(1);
}
