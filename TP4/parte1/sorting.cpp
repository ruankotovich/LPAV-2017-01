#include <vector>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>

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
    cout << setprecision(6) << '\n' << fixed;
    cout << "Analytics for " << algorithmName << ": \n";
    cout << "Comparsions : " << comparsions << '\n';
    cout << "Movements : " << movements << '\n';
    cout << "Time : " << (double)time << " s\n";
  }
};

struct Sorting{
private:
  int size;
  vector<int> vec;

  void _merge(SortingAnalytics* analytics, vector<int> &v,int start, int middle, int end){
    int i, j, k, *w = (int*) malloc(sizeof(int)*(end-start));
    i = start;
    j = middle;
    k = 0;

    while (i < middle && j < end) {

      analytics->comparsions++;
      analytics->movements++;

      if (v[i] < v[j]) {
        w[k] = v[i];
        i++;
      }else{
        w[k] = v[j];
        j++;
      }

      k++;

    }


    while (i < middle) {
      analytics->movements++;
      w[k] = v[i];
      i++;
      k++;
    }

    while (j < end) {
      analytics->movements++;
      w[k] = v[j];
      j++;
      k++;
    }

    for (i = start; i < end; i++){
      analytics->movements++;
      v[i] = w[i-start];
    }


    free(w);
  }

  void _mergesort (SortingAnalytics* analytics,vector<int> &v ,int start, int end){
    if (start < end-1) {
      int middle = (start + end)/2;
      _mergesort (analytics,v,start, middle);
      _mergesort (analytics,v, middle, end);
      _merge (analytics, v,start, middle, end);
    }
  }


  void _quickSort(SortingAnalytics* analytics ,vector<int> &v ,int start,int end){
    int i,j,aux,eixo;
    if(end>start){
      i = start;
      j = end;
      eixo = v[(end+start)/2];

      while(i<=j){

        while(v[i] < eixo) {i++;analytics->comparsions++;}
        while(v[j] > eixo) {j--;analytics->comparsions++;}

        if(i<=j){
          aux = v[i];
          v[i] = v[j];
          v[j] = aux;
          i++;j--;
          analytics->movements++;
        }
      }
      _quickSort(analytics,v,i,end);
      _quickSort(analytics,v,start,j);
    }
  }

  void _insertionSort(SortingAnalytics* analytics, vector<int> &v) {
    int i,j;
    int  pivot;

    for(i = 1; i < size ; i++)  {
      pivot = v[i];
      j = i-1;
      while((j >=0) && (v[j] > pivot)) {
        analytics->movements++;
        analytics->comparsions++;
        v[j+1] = v[j];
        j--;
      }
      analytics->movements++;
      v[j+1] = pivot;
    }
  }

  void _selectionSort(SortingAnalytics* analytics, vector<int> &v){
    for(int ind=0;ind<size;ind++){
      int next=ind;

      for(int i=ind;i<size;i++){
        analytics->comparsions++;
        if(v[next] > v[i]){
          next = i;
        }
      }

      if(next != ind){
        analytics->movements++;
        int aux = v[next];
        v[next] = v[ind];
        v[ind] = aux;
      }

    }

  }

  void _bubbleSort(SortingAnalytics *analytics, vector<int> &v){
    bool changed;
    do{
      changed = false;
      for(int i=0; i< size-1;i++){
        analytics->comparsions++;
        if (v[ i ] > v[ i + 1 ]){
          analytics->movements++;
          int backup = v[ i ];
          v[i] = v[i + 1];
          v[i+1] = backup;
          changed = true;
        }
      }
    }while(changed);
  }


  void _makeHeap(SortingAnalytics *analytics, vector<int> &v, int i, int N){
    while ( (i<<1) + 1 < N ) {
      int son = (i<<1) + 1;

      if ((son + 1 < N) && (v[son] < v[son+1])){ son++; analytics->comparsions++;}

      if (v[i] < v[son]) {
        analytics->comparsions++;
        analytics->movements++;
        int backup = v[son];
        v[son] = v[i];
        v[i] = backup;
        i = son;
      }
      else
      return;
    }
  }

  void _heapSort(SortingAnalytics *analytics, vector<int> &v, int sLen){
    for (int k = sLen>>1; k >= 0; k--) {
      _makeHeap(analytics,v, k, sLen);
    }

    while (sLen > 1) {
      analytics->movements++;
      int backup = v[sLen-1];
      v[sLen-1] = v[0];
      v[0] = backup;
      _makeHeap(analytics,v, 0, sLen-1);
      sLen--;
    }
  }

public:


  SortingAnalytics* heapSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Heap Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }

    clock_t start = clock();
    _heapSort(analytics, vect2, size);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;

    return analytics;
  }

  SortingAnalytics* quickSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Quick Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }

    clock_t start = clock();
    _quickSort(analytics, vect2,0, size);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;
    return analytics;
  }

  SortingAnalytics* mergeSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Merge Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }

    clock_t start = clock();
    _mergesort(analytics,vect2, 0, size);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;


    return analytics;
  }

  SortingAnalytics* insertionSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Insertion Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }

    clock_t start = clock();
    _insertionSort(analytics,vect2);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;


    return analytics;
  }

  SortingAnalytics* selectionSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Selection Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }

    clock_t start = clock();
    _selectionSort(analytics,vect2);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;

    return analytics;
  }

  SortingAnalytics* bubbleSort(){
    SortingAnalytics* analytics = new SortingAnalytics("Bubble Sort");

    vector<int> vect2;
    for(int v:vec){
      vect2.push_back(v);
    }
    clock_t start = clock();
    _bubbleSort(analytics,vect2);
    clock_t end = clock();

    analytics->time = (double)(end - start)/CLOCKS_PER_SEC;

    return analytics;
  }

  Sorting(int arraySize){
    size = arraySize;
    vec.reserve(size);
    srand( (unsigned)time(NULL) );
    for(int i=0;i < size;i++){
      vec.push_back((rand() % INT_MAX));
    }
  }
};
