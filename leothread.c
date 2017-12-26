#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"

int g = 0;
void* leonardo(void* pointer)
{
  int t = g;
  g++; 
  int* pointer_num = pointer;
  int input = *pointer_num;
   
  if (input == 0 || input == 1)
    {
      *pointer_num = 1;
      printf("[%d]\n", t);
      return NULL;
    }
  else{
    int num1 = input - 1;
    int num2 = input - 2;

    pthread_t tid1;
    pthread_t tid2;
    int x =t;
    printf("(%d\n",x);
    pthread_create(&tid1, NULL, leonardo, &num1); 
    pthread_join(tid1, NULL) ;
    
    pthread_create(&tid2, NULL, leonardo, &num2); 
    pthread_join(tid2, NULL); 
    printf("%d)\n",x);
    *pointer_num = num1 + num2;
  }

  return NULL;
}

int main(int argc, const char* argv[])
{
  int value = atoi(argv[1]);
  pthread_t tid;

   
  int result = pthread_create(&tid, NULL, leonardo, &value);

  if (result != 0)
    {
      perror("pthread_create");
      return 1;
    }
    

  pthread_join(tid, NULL);

  return 0;
}
