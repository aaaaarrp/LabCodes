
// Heap Sort in C++
// Build Max heap >> heapify >> put root at last-swap >> repeat
  
#include <iostream>
#include<ctime>
using namespace std;
  
void heapify(int arr[], int n, int i) {
// Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
}
  
// main function to do heap sort
void heapSort(int arr[], int n) {
    // Build max heap  >> bottom up >> first index of a non-leaf node = n/2-1
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}
  
// Print an array
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    clock_t start, finish;
    double runTime;

    int array[] = { 12, 11, 13, 1, 0, 7, 23, 4, 2 };
    int n = sizeof(array) / sizeof(array[0]);

    cout << "\nGiven array: ";
    printArray(array, n);

    start = clock();
    heapSort(array, n);
    finish = clock();

    cout << "\nSorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Heap Sort:";
    printf("%lf", runTime);
    cout << "\n\n";

    return 0;
}