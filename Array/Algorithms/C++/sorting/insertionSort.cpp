#include <iostream>
using namespace std;
  
void insertionSort(int arr[], int n) 
{ 
    int i, j, num; 
    for (i = 1; i < n; i++)
    { 
        num = arr[i]; 
        j = i - 1; 
  
        while (j >= 0 && arr[j] > num)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = num; 
    } 
} 
  

int main() 
{ 
    int arr[] = { 88, 64, 1, 4, 98 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    insertionSort(arr, n); 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
  
    return 0; 
} 
