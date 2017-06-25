#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define null NULL

pthread_mutex_t sumLock = PTHREAD_MUTEX_INITIALIZER;
int *vk;
int *vTrue;

typedef struct boundary_t{
  pthread_t thread;
  int state;
  int toVector;
  int startPosition;
  int endPosition;
}Boundary_t;

void* sumThread(void* bd){
  Boundary_t *boundary = (Boundary_t*)bd;

  for(int i = boundary->startPosition; i <= boundary->endPosition; ++i){
    vTrue[boundary->toVector] += vk[i];
  }
  return null;
}

void buildVector(int **vector, int length){
  (*vector) = malloc(sizeof(int)*length);
  do{
    length--;
    (*vector)[length] = rand() % 100;
  }while(length>=0);
}

void buildSumVector(int **vector, int length){
  (*vector) = malloc(sizeof(int)*length);
  do{
    length--;
    (*vector)[length] = 0;
  }while(length>=0);
}

void buildBoundaries(Boundary_t **tVector, int numThreads, int length){
  const int pass = length / numThreads;
  (*tVector) = malloc(sizeof(Boundary_t)*numThreads);

  for(int i=0; i < numThreads ; i++){
    (*tVector)[i].startPosition = i*(pass);
    (*tVector)[i].endPosition = ((*tVector)[i].startPosition+pass)-1;
    (*tVector)[i].toVector = i;
  }

  (*tVector)[numThreads-1].endPosition = (length-1);
}

int main(int argc, char *argv[]){
  int length = atoi(argv[1]);
  int threads = atoi(argv[2]);
  int threshold = atoi(argv[3]);

  double sumptr = 0;
  int *vector, *sumVector = null;
  Boundary_t *threadVector = null;

  srand(time(null));

  buildVector(&vector, length);
  buildBoundaries(&threadVector, threads, length);
  buildSumVector(&sumVector, threads);

  vk = vector;
  vTrue = sumVector;

  for(int i=0; i < threshold; i++){
    clock_t ping = clock();

    for(int i=0;i<threads;i++){
      threadVector[i].state = pthread_create(&threadVector[i].thread, NULL, sumThread, &threadVector[i]);
    }

    for(int i=0;i<threads;i++){
      pthread_join(threadVector[i].thread, null);
    }

    int soma = 0;

    for(int i=0;i<threads;i++){
      soma+=vTrue[i];
    }

    clock_t pong = clock();

    sumptr += ((double)(pong-ping));
  }

  printf("%.6lf;", (sumptr/(threshold*CLOCKS_PER_SEC)));
}
