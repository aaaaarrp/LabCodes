//Iterative method
#include <iostream>
#include <ctime>
using namespace std;
int binarySearch(int array[], int x, int low, int high)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == x)
            return mid;
        if (array[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main()
{
    clock_t start, finish;
    double runTime;
    int i, n, x;
    cout << "Enter the size of the array:";
    cin >> n;
    int array[n];
    cout << "Enter array elements:\n";
    for (i = 0; i < n; ++i)
    {
        cin >> array[i];
    }
    cout << "Enter element to search:";
    cin >> x;

    start = clock();
    int result = binarySearch(array, x, 0, n - 1);
    finish = clock();

    (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
    runTime = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << "\nTime for binary search:";
    printf("%lf", runTime);
    cout << "\n";
}
