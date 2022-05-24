
#include <iostream>
#include <ctime>
using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    for(int i=0; i < n-1; i++){
        int min = i;
        for(int j=i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
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
    cout << "Enter the size of the array:";
    cin >> n;
    int array[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    start = clock();
    selectionSort(array, n);
    finish = clock();

    cout << "Sorted array: ";
    printArray(array, n);

    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for Selection Sort:";
    printf("%lf", runTime);
    cout << "\n";
    
}
