#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex,empty,full;

int buf[5],r,f;
void *produce(void* arg)
{
int i;
for(i=0;i<10;i++)
{
   sem_wait(&empty);
   sem_wait(&mutex);
   printf("item produced is: %d",i);
   buf[(++r)%5]=i;
   sem_post(&mutex);
   sem_post(&full);
   printf("full %u",full);


}
void *consume(void *arg)
{
int i,item;
for(i=0;i<10;i++)
{
  sem_wait(&full);
  printf("full is %u",i);
  item=buf[(++f)%5];
printf("product consuumed is %d",item);
sem_post(&mutex);
sem_post(&empty);
}

}



}




void main()
{
  int i;
  pthread_t pid1,pid2;
  sem_init(&mutex,0,1);
  sem_init(&full,0,1);
  sem_init(&empty,0,5);
  pthread_create(&pid1,NULL,produce,NULL);
  pthread_create(&pid2,NULL,consume,NULL);
  pthread_join(pid1,NULL);
  pthread_join(pid2,NULL);


}




