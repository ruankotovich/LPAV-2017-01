#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define null NULL
#define K 1024

int *vk;


typedef struct quicksort_paramethers_t{
  int inicio;
  int fim;
}QuicksortParamethers_t;

void swap(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

QuicksortParamethers_t *create_paramethers(int start, int end){
  QuicksortParamethers_t* paramethers = malloc(sizeof(QuicksortParamethers_t));
  paramethers->fim = end;
  paramethers->inicio = start;
  return paramethers;
}

void* quickSort(void* q){
  int inicio = ((QuicksortParamethers_t*)q)->inicio;
  int fim = ((QuicksortParamethers_t*)q)->fim;
  int i, j, eixo;
  if(fim>inicio){
    i = inicio;
    j = fim;
    eixo = vk[(fim+inicio)/2];

    while(i<=j){

      while(vk[i] < eixo) i++;
      while(vk[j] > eixo) j--;

      if(i<=j){
        swap(&vk[i], &vk[j]);
        i++;j--;
      }
    }
    quickSort(create_paramethers(i,fim));
    quickSort(create_paramethers(inicio,j));

  }
  return null;
}

void recopyBackup(int *v, int len){
  for(int i=0;i < len; i++){
    vk[i] = v[i];
  }
}

int main(int argc, char *argv[]){
  int length = atoi(argv[1]);
  int threshold = atoi(argv[2]);

  double sumptr = 0;

  int *backupVector = malloc(sizeof(int)*2048*K);
  vk = malloc(sizeof(int)*2048*K);

  srand(time(null));

  for(int i = 0; i < length; i++){
    backupVector[i] = rand() % 500;
  }

  for(int i=0; i < threshold; i++){

    recopyBackup(backupVector, length);

    clock_t ping = clock();

    QuicksortParamethers_t *parametros = malloc(sizeof(QuicksortParamethers_t));
    parametros->inicio = 0;
    parametros->fim = length-1;
    quickSort(parametros);

    clock_t pong = clock();

    sumptr += ((double)(pong-ping));
  }

  if(length <= 1000){
    for(int i=0; i<length; i++){
      printf("[%d]\n", vk[i]);
    }
  }

  printf("%.6lf;", (sumptr/(threshold*CLOCKS_PER_SEC)));
}
