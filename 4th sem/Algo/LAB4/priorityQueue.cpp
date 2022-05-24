
// Using heap Priority Queue 

#include <iostream>
#include <vector>
using namespace std;

// Function to swap position of two elements
void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

// Function to heapify the tree
void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  
  // Find the largest among root, left child and right child
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  // Swap and continue heapifying if root is not largest
  if (largest != i) {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

// Function to insert an element into the tree
void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0) {     //if no node present
    hT.push_back(newNum);
  } else {
    hT.push_back(newNum);
    // Build max heap  >> bottom up >> first index of a non-leaf node = n/2-1
    for (int i = size / 2 - 1; i >= 0; i--) {
      heapify(hT, i);
    }
  }
}

// Function to delete an element from the tree
void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++) {    //search for the element
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);    // swap with last element

  hT.pop_back();    //delete
  // Build max heap  >> bottom up >> first index of a non-leaf node = n/2-1
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(hT, i);
  }
}

// Print the tree
void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main() {

  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "\nMax-Heap array: ";
  printArray(heapTree);

  insert(heapTree, 1);

  deleteNode(heapTree, 4);

  cout << "\nAfter operations: ";

  printArray(heapTree);

  //cout << "Peek element: " << heapTree[0] << "\n";

}