#include "sorting.cpp"

int main(){
  Sorting *sorting = new Sorting(10000);
  SortingAnalytics * current;

  current = sorting->quickSort();
  current->printAnalytics();
  delete(current);

  current = sorting->mergeSort();
  current->printAnalytics();
  delete(current);

  current = sorting->insertionSort();
  current->printAnalytics();
  delete(current);

  current = sorting->selectionSort();
  current->printAnalytics();
  delete(current);

  current = sorting->bubbleSort();
  current->printAnalytics();
  delete(current);

  return 0;
}
