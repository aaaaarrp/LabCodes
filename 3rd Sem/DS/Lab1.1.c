
// C program to sort numbers using Bubble sort  

#include <stdio.h>
void bubble_sort(long [], long);

int main()
{
  long array[100], n, c;

  printf("\nEnter number of elements\n");
  scanf("%ld", &n);

  printf("\nEnter %ld numbers\n", n);

  for (c = 0; c < n; c++)
    scanf("%ld", &array[c]);

  bubble_sort(array, n);

  printf("\nSorted array: ");

  for (c = 0; c < n; c++)
    printf("%ld ", array[c]);
  printf("\nLargest number: %ld", array[n-1]);
  printf("\n");
  return 0;
}

void bubble_sort(long list[], long n)
{
  long c, d, t;

  for (c = 0 ; c < n - 1; c++) {
    for (d = 0 ; d < n - c - 1; d++) {
      if (list[d] > list[d+1]) {
        /* Swapping */
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}