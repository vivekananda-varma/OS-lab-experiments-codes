#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

#define N 5
#define thinking 2
#define hungry 1
#define eating 0
#define left (pnum+4)%N
#define right (pnum+1)%N

sem_t mutex;
sem_t S[N];

int phil[5]={0,1,2,3,4};
int state[5];

void test(int pnum)
{
  if(state[pnum]==hungry && state[left]!=eating && state[right]!=eating)
     state[pnum]=eating;
  printf("philosiphor %d picked up %d fork and %d fork",pnum+1,left+1,right+1);
  printf("philosiphor %d started eating!",pnum+1);
  sem_post(&S[pnum]);

}



void take_fork(int pnum)
{
   sem_wait(&mutex);
   state[pnum]=hungry;
   printf("philosiphor %d is hungry",pnum+1);
   test(pnum);
   sem_post(&mutex);
   sem_wait(&S[pnum]);
}

void put_fork(int pnum)
{
  sem_wait(&mutex);
  state[pnum]=thinking;
  printf("philosiphor %d dropped down %d fork and %d fork",pnum+1,left+1,right+1);
  printf("philosiphor %d thinking!",pnum+1);
 test(left);
 test(right);

  sem_post(&mutex);
}









void* philosiphor(int* pnum)
{

while(1){
 int* i=pnum;
 take_fork(*i);
 put_fork(*i);
}
}






void main()
{
    int i;
pthread_t p_id[5];
sem_init(&mutex,0,1);
for(i=0;i<5;i++)
    sem_init(&S[i],0,0);
for(i=0;i<5;i++){
    pthread_create(&p_id[i],NULL,philosiphor,&phil[i]);
   printf("philosiphor %d is thinking!",i+1);
}
for(i=0;i<5;i++)
    pthread_join(p_id[i],NULL);


}







