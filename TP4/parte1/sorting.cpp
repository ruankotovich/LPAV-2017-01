#include <vector>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>

using namespace std;

struct SortingAnalytics{
  unsigned long comparsions;
  unsigned long movements;
  double time;
  string algorithmName;

  SortingAnalytics(string name){
    algorithmName = name;
    comparsions = 0;
    movements = 0;
    time = 0.0f;
  }

  void printAnalytics(){
    cout << setprecision(10) << '\n' << fixed;
    cout << "Analytics for " << algorithmName << ": \n";
    cout << "Comparsions : " << comparsions << '\n';
    cout << "Movements : " << movements << '\n';
    cout << "Time : " << (double)time << '\n';
  }
};

struct Sorting{
private:
  int size;
  vector<int> currentArray;

  void _merge(SortingAnalytics* analytics, int start, int middle, int end){
    int i, j, k, *w = (int*) malloc(sizeof(int)*(end-start));
    i = start;
    j = middle;
    k = 0;

    while (i < middle && j < end) {

      analytics->comparsions++;
      analytics->movements++;

      if (currentArray[i] < currentArray[j]) {
        w[k] = currentArray[i];
        i++;
      }else{
        w[k] = currentArray[j];
        j++;
      }

      k++;

    }


    while (i < middle) {
      analytics->movements++;
      w[k] = currentArray[i];
      i++;
      k++;
    }

    while (j < end) {
      analytics->movements++;
      w[k] = currentArray[j];
      j++;
      k++;
    }

    for (i = start; i < end; i++){
      analytics->movements++;
      currentArray[i] = w[i-start];
    }


    free(w);
  }

  void _mergesort (SortingAnalytics* analytics ,int start, int end){
    if (start < end-1) {
      int middle = (start + end)/2;
      _mergesort (analytics,start, middle);
      _mergesort (analytics, middle, end);
      _merge (analytics,start, middle, end);
    }
  }


  void _quickSort(SortingAnalytics* analytics ,int start,int end){
    int i,j,aux,eixo;
    if(end>start){
      i = start;
      j = end;
      eixo = currentArray[(end+start)/2];

      while(i<=j){

        while(currentArray[i] < eixo) {i++;analytics->comparsions++;}
        while(currentArray[j] > eixo) {j--;analytics->comparsions++;}

        if(i<=j){
          aux = currentArray[i];
          currentArray[i] = currentArray[j];
          currentArray[j] = aux;
          i++;j--;
          analytics->movements++;
        }
      }
      _quickSort(analytics,i,end);
      _quickSort(analytics,start,j);
    }
  }

public:

  SortingAnalytics* quickSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Quick Sort");

    clock_t start = clock();
    _quickSort(analytics, 0, size);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;

    return analytics;
  }

  SortingAnalytics* mergeSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Merge Sort");

    clock_t start = clock();
    _mergesort(analytics, 0, size);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;


    return analytics;
  }


  Sorting(int arraySize){
    size = arraySize;
    currentArray.reserve(size);
    srand( (unsigned)time(NULL) );
    for(int i=0;i < size;i++){
      currentArray[i] = (rand() % INT_MAX);
    }
  }

  void printArray(){
    for(int i=0;i < size;i++){
      cout << currentArray[i] << ',';
    }
  }
};
