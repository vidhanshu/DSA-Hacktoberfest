#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_indx = i;
	  for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;
    
      if(min_indx!=i)
			swap(&arr[min_indx], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	for (int i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {43, 72, 28, 83, 47};
	int sz = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, sz);
	cout << "Sorted array after performing selection sort: \n";
	printArray(arr, sz);
	return 0;
}
