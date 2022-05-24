#include <iostream>
#include <ctime>
using namespace std;

int linearSearch(int array[], int n, int x)
{
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
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
  int result = linearSearch(array, n, x);
  finish = clock();

  (result == -1) ? cout << "Element not found" : cout << "Element found at index: " << result;
  runTime = (double)(finish - start) / CLOCKS_PER_SEC;
  cout << "\nTime for linear search:";
  printf("%lf", runTime);
  cout << "\n";
}