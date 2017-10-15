#include <iostream>
#include <stdio.h>

using namespace std;

void merge(int l[], int nL, int r[], int nR, int a[])
{
	int i= 0;
	int j= 0;
	int k= 0;

	while(i<nL && j<nR)
	{

		if(l[i]<= r[j])
		{
			a[k]= l[i];
			i++;
		}
		else
		{
			a[k]= r[j];
			j++;
		}
		k++;
	}
	while(i<nL)
	{
		a[k]= l[i];
		i++;
		k++;
	}
	while(j<nR)
	{
		a[k]= r[j];
		j++;
		k++;
	}

}

void mergeSort(int a[], int n)
{
	int i,j, nL, nR;

	if(n<2)
		return;

	int mid= n/2;
	nL= mid;
	nR= n-mid;
	int left[nL];
	int right[nR];

	for(i=0; i< mid; i++)
		left[i]= a[i];

	for(i=mid; i<n; i++)
		right[i-mid]= a[i];
	
	mergeSort(left, nL);
	mergeSort(right, nR);
	merge(left, nL, right, nR, a);
}

int main()
{
	int n;
	int i;
	int a[20];
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];

	mergeSort(a, n);
	cout<< "Sorted array is:\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<< " ";
		/* code */
	}
}
