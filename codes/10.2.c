#include<stdio.h>
#include<stdlib.h>

void main()
{
 int f[50],i,j,k,p,a;
 printf("no. of blocks which are allocated: ");
 scanf("%d",&p);
 printf("Enter blocks which are allocated: ");
 for(i=0;i<50;i++)
    f[i]=0;
 for(i=0;i<p;i++)
 {
   scanf("%d",&a);
   f[a]=1;
 }
 int st,len;
 printf("enter starting block: ");
 scanf("%d",&st);
 printf("Enter length: ");
 scanf("%d",&len);
 k=len;

if(f[st]==0){
for(i=st;i<(st+k);i++)
 {

   if(f[i]==0)
   {
     f[i]=1;
     printf("%d-->%d",i,f[i]);
   }
   else{
    printf("%d is already allocated",i);
    k++;
   }
 }
 }



}


