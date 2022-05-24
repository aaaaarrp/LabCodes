
#include <iostream>
#include <ctime>
using namespace std;

void insertionSort(int arr[], int n){
    
    for(int i = 1; i < n; i++){
        int value = arr[i];
        int j = i-1;
        while( j >= 0 && arr[j] > value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

}

int main(){

    clock_t start, finish;
    double runTime;

    int n;
    cout << "\nEnter the size of the array:";
    cin >> n;
    int array[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    start = clock();
    insertionSort(array, n);
    finish = clock();

    cout << "Sorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Insertion Sort:";
    printf("%lf", runTime);
    cout << "\n\n";
    
}
