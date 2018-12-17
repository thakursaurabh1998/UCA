#include<stdio.h>
#include <pthread.h>
#define NUM_THREADS 5

void *hello(void *args)
{
  printf("Hello Thread\n");
  pthread_exit(NULL);
}

int main()
{
  pthread_t threads[NUM_THREADS];
  int i;
  for (i = 0; i < NUM_THREADS; i++)
    pthread_create(&threads[i], NULL, hello, NULL);
  for (i = 0; i < NUM_THREADS; i++)
    pthread_join(threads[i], NULL);
}