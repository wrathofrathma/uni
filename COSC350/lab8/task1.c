/* Concurrrent CAlculation
 *
 * Write a C porgram which accepts an integer argument and calculate sum up and factorial (1 + 2 + 3 + ... + n, and 1 * 2 * 3 * ... * n). Instead of calling sequence of two functions, twothreads will be created and each thread works for different task concurrently */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void err(char *m){
  printf("[ ERROR ] %s\n", m);
  exit(1);
}

struct values {
  long long fact;
  long long sum;
  int n;
};

void sumton(void *vals){
  struct values *v = (struct values *)vals;
  long long n = v->n;
  v->sum = (n*(n+1))/2;
}

void factorial(void *vals){
  struct values *v = (struct values *)vals;
  int n = v->n;
  int i=1;
  long long f=1;
  for(i=1; i<=n; i++)
    f*=i;
  v->fact = f;
}

int main(int argc, char **argv){
  if(argc!=2)
    err("Please use the syntax ./task1 integer");
  int n = atoi(argv[1]);

  //Creating our storage container and setting n
  struct values *v = malloc(sizeof(struct values));
  v->n = n;

  //Creating our threads
  pthread_t sum_t;
  pthread_t fact_t;
  int sum_prval = pthread_create(&sum_t, NULL, sumton, (void *) v);
  int fact_prval = pthread_create(&fact_t, NULL, factorial, (void *) v);
  if((sum_prval | fact_prval)!=0)
    err("One of our threads didn't create properly");

  if(pthread_join(sum_t, NULL)!=0)
    err("Sum thread broke");
  if(pthread_join(fact_t, NULL)!=0)
    err("Factorial thread broke");
  printf("Sum to n: %lld\n", v->sum);
  printf("Factorial of n: %lld\n", v->fact);

  free(v);
  return 0;
}
