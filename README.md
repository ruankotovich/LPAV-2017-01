# LPAV-2017-01
# Student : RUAN GABRIEL G BARROS

---

## TP4 - Sorting Algorithms
In this homework, I compare the movements number, comparisons number and the execution time of each algorithm

### Algorithms
 * Quick Sort
 * Merge Sort
 * Heap Sort
 * Insertion Sort
 * Selection Sort
 * Bubble Sort


#### Input

To perform a test, just execute the compiled source file inputting the test instances length into the <b>char **argv</b> :

##### ./test 10 100 1000
It will test all these algorithms using the vector size on 10, 100 and 1000.

**Output:**
```
 - Sorting on instance length 10
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]

 - Sorting on instance length 100
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]

 - Sorting on instance length 1000
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]

<html>
<head><meta charset='UTF-8'><title>Sorting Algorithm Test - 08/04/2017 -16:43:58</title></head>
<body>
<center><table border='1' style='text-align:center;vertical-align:middle;'>
<tr><td colspan='2' style='border:0px'></td><td colspan='6'><center>Aleatórios</center></td></tr>
<tr><td>**Métrica**</td><td>**Algoritmo**</td><td> **10** </td><td> **100** </td><td> **1000** </td></tr>

<tr><td rowspan='6'>Número de Comparações</td>
<td>Bubble Sort</td><td>81</td><td>9009</td><td>982017</td></tr>
<tr><td>Selection Sort</td><td>55</td><td>5050</td><td>500500</td></tr>
<tr><td>Insertion Sort</td><td>32</td><td>2422</td><td>253516</td></tr>
<tr><td>Heap Sort</td><td>19</td><td>715</td><td>12177</td></tr>
<tr><td>Merge Sort</td><td>24</td><td>538</td><td>8740</td></tr>
<tr><td>Quick Sort</td><td>15</td><td>460</td><td>7833</td></tr>

<tr><td rowspan='6'>Número de Trocas</td>
<td>Bubble Sort</td><td>32</td><td>2422</td><td>253516</td></tr>
<tr><td>Selection Sort</td><td>10</td><td>100</td><td>1000</td></tr>
<tr><td>Insertion Sort</td><td>41</td><td>2521</td><td>254515</td></tr>
<tr><td>Heap Sort</td><td>24</td><td>572</td><td>9038</td></tr>
<tr><td>Merge Sort</td><td>68</td><td>1344</td><td>19952</td></tr>
<tr><td>Quick Sort</td><td>11</td><td>184</td><td>2560</td></tr>

<tr><td rowspan='6'>Número de Trocas</td>

<td>Bubble Sort</td><td>0.000003 seg</td><td>0.000187 seg</td><td>0.021415 seg</td></tr>
<tr><td>Selection Sort</td><td>0.000002 seg</td><td>0.000074 seg</td><td>0.004245 seg</td></tr>
<tr><td>Insertion Sort</td><td>0.000002 seg</td><td>0.000049 seg</td><td>0.004216 seg</td></tr>
<tr><td>Heap Sort</td><td>0.000003 seg</td><td>0.000041 seg</td><td>0.000566 seg</td></tr>
<tr><td>Merge Sort</td><td>0.000005 seg</td><td>0.000040 seg</td><td>0.000466 seg</td></tr>
<tr><td>Quick Sort</td><td>0.000002 seg</td><td>0.000021 seg</td><td>0.000264 seg</td></tr>

</table></center>
</body>
```


###### ./test 10 100 1000 > test.html
It will test all these algorithms using the vector size on 10, 100 and 1000 and will redirect the output to an html file.

**Output:**
```
 - Sorting on instance length 10
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]

 - Sorting on instance length 100
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]

 - Sorting on instance length 1000
	 Performing BUBBLE SORT... [DONE]
	 Performing SELECTION SORT... [DONE]
	 Performing INSERTION SORT... [DONE]
	 Performing HEAP SORT... [DONE]
	 Performing MERGE SORT... [DONE]
	 Performing QUICK SORT.. [DONE]
```
---
