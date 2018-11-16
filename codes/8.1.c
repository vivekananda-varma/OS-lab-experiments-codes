#include<stdio.h>

void main()
{
  int i,j,fr,n;
  printf("Enter frame size: ");
  scanf("%d",&fr);
  printf("Enter no. of reference string: ");
  scanf("%d",&n);
  int ref[n];
  printf("enter reference string: ");
  for(i=0;i<n;i++)
    scanf("%d",&ref[i]);
  int page[fr];
  for(i=0;i<fr;i++)
    page[i]=ref[i];
  printf("first filled page table is: %d %d %d\n",page[0],page[1],page[2]);
  int flag=0,p=0;
  for(i=fr;i<n;i++)
  {
    for(j=0;j<fr;j++)
        if(ref[i]==page[j])
           flag=1;
    if(flag==0){
        page[p]=ref[i];
        p++;

    }
    if(p>2)
        p=p%3;
    if(flag==0)
        printf("page table references are: %d %d %d\n",page[0],page[1],page[2]);
    else
        printf("hit it!!!\n");
     flag=0;

  }
}
