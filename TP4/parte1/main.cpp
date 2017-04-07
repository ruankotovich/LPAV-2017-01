#include "sorting.cpp"

int main(){
  Sorting *sorting = new Sorting(1000);
  SortingAnalytics * current;

  current = sorting->quickSort();
  current->printAnalytics();
  delete(current);

  current = sorting->mergeSort();
  current->printAnalytics();
  delete(current);

  return 0;
}
