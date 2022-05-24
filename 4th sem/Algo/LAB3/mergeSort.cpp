// Merge sort in C++
// divide till length 1 size >> sort while merging

#include <iostream>
#include<ctime>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  //Merging >> making sorted array
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// divides the array into two halves until we reach a stage,
// where we try to perform MergeSort on a subarray of size 1  >> end of the element >> merge
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);      
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Printing the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main()
{
    clock_t start, finish;
    double runTime;

    int array[] = { 12, 11, 13, 1, 0, 7, 23, 4, 2 };
    int n = sizeof(array) / sizeof(array[0]);

    cout << "\nGiven array: ";
    printArray(array, n);

    start = clock();
    mergeSort(array, 0, n-1);
    finish = clock();

    cout << "\nSorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Merge Sort:";
    printf("%lf", runTime);
    cout << "\n\n";

    return 0;
}