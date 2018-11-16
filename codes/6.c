#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex;
sem_t db;

int readercount=0;
pthread_t reader1,reader2,writer1,writer2;






void *reader(void *p){
      sem_wait(&mutex);
      readercount++;
      if(readercount==1)
         sem_wait(&db);
       sem_post(&mutex);
       printf("reader %s is reading!",p);
       sem_wait(&mutex);
       readercount--;
       if(readercount==0)
        sem_post(&db);
       sem_post(&mutex);





}

void* writer(void* p){

  printf("writer is waiting!");
  sem_wait(&db);
        printf("writer is writing!");
   sem_post(&db);
   printf("writer completed writinbg");






}



void main()
{
  int i;
  sem_init(&mutex,0,1);
  sem_init(&db,0,1);

   while(1){
     pthread_create(&reader1,NULL,reader,"1");
      pthread_create(&reader2,NULL,reader,"2");
       pthread_create(&writer1,NULL,writer,"1");
        pthread_create(&writer2,NULL,writer,"2");




   }
}







