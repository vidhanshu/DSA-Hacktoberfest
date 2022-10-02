#include<iostream>
using namespace std;


int partition(int *a,int start,int end)
{
	int pivot,pindex,temp;
	pivot=a[end];
	pindex=start;
	for(int i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			temp=a[i];
			a[i]=a[pindex];
			a[pindex]=temp;
			pindex++;
		}
	}
	temp=a[end];
	a[end]=a[pindex];
	a[pindex]=temp;
	return pindex;
}


void quicksort(int *a,int start,int end)
{
	if(start<end)
	{
		int pindex=partition(a,start,end);
		quicksort(a,start,pindex-1);
		quicksort(a,pindex+1,end);
	}
}



int main()
{
	int n;
	cout<<"Enter number of elements";
	cin>>n;
	int a[n];
	cout<<"Enter elements";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	return 0;
}