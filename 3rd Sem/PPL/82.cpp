#include <iostream>
using namespace std;
template <class T>
int LinearSearch(T arr[], int n, T x) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == x)
			return i;
	}
	return -1;

}

int main() {

	int arr[50];
	
	int n, index, x;
	cout<<"Enter no of elements to be entered: ";
	cin>>n;
	cout<<"Enter elements -\n";
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	
	cout<<"Enter element to be searched: ";
	cin>>x;
	index = LinearSearch(arr, n, x);

	if (index != -1)
		cout << x << " is present in the array at position " << index << endl;
	else
		cout << x << " is not present in the array \n" << endl;
	return 0;
}