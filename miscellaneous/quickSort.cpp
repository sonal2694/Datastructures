#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void QuickSort(vector<int> &v, int start, int end);
int partition(vector<int> &v, int start, int end);
int main()
{
	int n,input;
	cout<<"Enter the number of elements\n";
	cin>>n;
	std::vector<int> v;
	cout<<"Enter the elements\n";
	for(int i=0; i<n;i++)
	{
		cin>>input;
		v.push_back(input);
	}
	int start= 0;
	int end= n-1;
	QuickSort(v, start, end);

	cout<<"The sorted array is\n";
	for (int i = 0; i < n; i++)
		cout<<v[i]<<" ";
}

void QuickSort(vector<int> &v, int start, int end)
{
	if(start< end)
	{
		int pIndex= partition(v, start, end);
		QuickSort(v, start, pIndex-1);
		QuickSort(v, pIndex+1, end);
	}
}

int partition(vector<int> &v, int start, int end)
{
	int pivot= v[end];
	int pIndex= start;
	int temp, i;

	for(i= start; i< end; i++)
	{
		if(v[i] <= pivot)
		{
			temp= v[i];
			v[i]= v[pIndex];
			v[pIndex]= temp;
			pIndex++;
		}
	}
	temp= v[end];
	v[end]= v[pIndex];
	v[pIndex]= temp;

	return pIndex;
}