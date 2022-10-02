#include <iostream>

using namespace std;

// Merging Subarrays
void MergeArr(int arr[], int start, int middle, int end)
{
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int i, j, k;

    int p[n1], q[n2];

    for (i = 0; i < n1; i++)
    {
        p[i] = arr[start + i];
    }

    for (j = 0; j < n2; j++)
    {
        q[j] = arr[middle + 1 + j];
    }

    // Initial Index of Sub Arrays
    i = 0, j = 0, k = start;

    while ((i < n1) && (j < n2))
    {
        if (p[i] <= q[j])
        {
            arr[k] = p[i];
            i++;
        }
        else
        {
            arr[k] = q[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = p[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = q[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int middle = (start + end) / 2;

        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);

        MergeArr(arr, start, middle, end);
    }
}

int main()
{
    int a[] = {21, 9, 16, 45, 76, 89};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    MergeSort(a, 0, n - 1);

    cout << "After Sorting: ";

    // Printing Sorted Array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}