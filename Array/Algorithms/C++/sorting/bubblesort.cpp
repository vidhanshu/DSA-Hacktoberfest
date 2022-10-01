#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int ar[], int n)
{
    int k = n - 1;
    while (k--)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            if (ar[i] > ar[j])
                swap(ar[i], ar[j]);
        }
    }
}
int main()
{
    int ar[] = {12, 2, 34, 5, 89, -1};
    int n = sizeof(ar) / sizeof(ar[0]);
    bubble_sort(ar, n);
    for (auto &it : ar)
        cout << it << " ";
    return 0;
}