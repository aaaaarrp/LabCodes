
#include <iostream>
#include <ctime>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(int arr[], int n){
    int i,j;
    bool swapped = false;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false)
            break;
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
    bubbleSort(array, n);
    finish = clock();

    cout << "Sorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Bubble Sort:";
    printf("%lf", runTime);
    cout << "\n\n";
    
}
