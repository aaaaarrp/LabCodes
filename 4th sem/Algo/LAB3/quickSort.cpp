
// Quick sort in C++
// divide using pivot >> sort 

#include <iostream>
#include<ctime>
using namespace std;

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// printing the array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);   // -1 initiallly

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {      // till second last element
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found, set second pointer i(increment)
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }
  
  // swap pivot with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on righ of pivot
    int pivot = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pivot - 1);

    // recursive call on the right of pivot
    quickSort(array, pivot + 1, high);
  }
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
    quickSort(array, 0, n-1);
    finish = clock();

    cout << "\nSorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Quick Sort:";
    printf("%lf", runTime);
    cout << "\n\n";

    return 0;
}

