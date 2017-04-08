#include "sorting.cpp"
#include <map>
#include <ctime>
#include <set>
#include <list>

enum AlgorithmType{
  BUBBLE, SELECTION, INSERTION, HEAP, QUICK, MERGE
};

string recoverName(AlgorithmType type){
  switch(type){
    case BUBBLE:
    return "Bubble Sort";

    case SELECTION:
    return "Selection Sort";

    case INSERTION:
    return "Insertion Sort";

    case HEAP:
    return "Heap Sort";

    case QUICK:
    return "Quick Sort";

    case MERGE:
    return "Merge Sort";
  }
}

void printComparisons(map<AlgorithmType, map<int, SortingAnalytics*> > &testMap, list<int> &instancesLength, list<AlgorithmType> &appearenceOrder){

  cout << "<tr><td rowspan='6'>Número de Comparações</td>\n";

  int count = 0;

  for(auto& type : appearenceOrder){
    count++;

    if(count>1){
      cout << "<tr><td>" << recoverName(type) << "</td>";
    }else{
      cout << "<td>" << recoverName(type) << "</td>";
    }

    auto &analytics = testMap[type];

    for(int length : instancesLength){
      cout << "<td>" << analytics[length]->comparsions << "</td>";
    }

    cout << "</tr>\n";
  }

  cout << '\n';
}

void printTrades(map<AlgorithmType, map<int, SortingAnalytics*> > &testMap, list<int> &instancesLength, list<AlgorithmType> &appearenceOrder){

  cout << "<tr><td rowspan='6'>Número de Trocas</td>\n";

  int count = 0;

  for(auto& type : appearenceOrder){
    count++;

    if(count>1){
      cout << "<tr><td>" << recoverName(type) << "</td>";
    }else{
      cout << "<td>" << recoverName(type) << "</td>";
    }

    auto &analytics = testMap[type];

    for(int length : instancesLength){
      cout << "<td>" << analytics[length]->movements << "</td>";
    }

    cout << "</tr>\n";
  }

  cout << '\n';
}

void printTime(map<AlgorithmType, map<int, SortingAnalytics*> > &testMap, list<int> &instancesLength, list<AlgorithmType> &appearenceOrder){

  cout << "<tr><td rowspan='6'>Tempo</td>\n";

  int count = 0;
  cout << setprecision(6) << '\n' << fixed;

  for(auto& type : appearenceOrder){
    count++;

    if(count>1){
      cout << "<tr><td>" << recoverName(type) << "</td>";
    }else{
      cout << "<td>" << recoverName(type) << "</td>";
    }

    auto &analytics = testMap[type];
    for(int length : instancesLength){
      cout << "<td>" << analytics[length]->time << " seg</td>";
    }

    cout << "</tr>\n";
  }

  cout << '\n';
}

void printTable(map<AlgorithmType, map<int, SortingAnalytics*> > &testMap, list<int> &instancesLength, list<AlgorithmType> &appearenceOrder){
  char date[80];

  std::time_t rawtime;
  std::tm* timeinfo;

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::strftime(date,80,"%d/%m/%Y -%H:%M:%S",timeinfo);

  cout << "<html>\n<head><meta charset='UTF-8'><title>Sorting Algorithm Test - "<< date<<"</title></head>\n<body>\n<center><table border='1' style='text-align:center;vertical-align:middle;'>\n<tr><td colspan='2' style='border:0px'></td><td colspan='6'><center>Aleatórios</center></td></tr>\n<tr><td>**Métrica**</td><td>**Algoritmo**</td>";

  for(int nextLength : instancesLength){
    cout << "<td> **" << nextLength << "** </td>";
  }

  cout << "</tr>\n\n";

  printComparisons(testMap, instancesLength, appearenceOrder);
  printTrades(testMap, instancesLength, appearenceOrder);
  printTime(testMap, instancesLength, appearenceOrder);

  cout << "</table></center>\n</body>\n";
}

int main(int argc, char** argv){
  map<AlgorithmType, map<int, SortingAnalytics*> > testMap;
  list<int> instancesLength;
  list<AlgorithmType> appearenceOrder;
  Sorting *sorting;

  appearenceOrder.push_back(BUBBLE);
  appearenceOrder.push_back(SELECTION);
  appearenceOrder.push_back(INSERTION);
  appearenceOrder.push_back(HEAP);
  appearenceOrder.push_back(MERGE);
  appearenceOrder.push_back(QUICK);

  for(int i=1;i < argc; i++){
    instancesLength.push_back(atoi(argv[i]));
  }

  for(int nextLength : instancesLength){
    sorting = new Sorting(nextLength);
    cerr << " - Sorting on instance length " << nextLength << '\n';

    cerr << "\t Performing BUBBLE SORT...";
    testMap[BUBBLE][nextLength] = sorting->bubbleSort();
    cerr << " [DONE]\n";

    cerr << "\t Performing SELECTION SORT...";
    testMap[SELECTION][nextLength] = sorting->selectionSort();
    cerr << " [DONE]\n";

    cerr << "\t Performing INSERTION SORT...";
    testMap[INSERTION][nextLength] = sorting->insertionSort();
    cerr << " [DONE]\n";

    cerr << "\t Performing HEAP SORT...";
    testMap[HEAP][nextLength] = sorting->heapSort();
    cerr << " [DONE]\n";

    cerr << "\t Performing MERGE SORT...";
    testMap[MERGE][nextLength] = sorting->mergeSort();
    cerr << " [DONE]\n";

    cerr << "\t Performing QUICK SORT..";
    testMap[QUICK][nextLength] = sorting->quickSort();
    cerr << " [DONE]\n";

    cerr << '\n';

    delete(sorting);
  }

  printTable(testMap, instancesLength, appearenceOrder);

  return 0;
}
