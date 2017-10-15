#include <stdio.h>
#include <iostream>

using namespace std;

void max_heapify(int a[], int i, int n)
{
	int lchild= 2*i+1;
	int rchild= 2*i+2;
	int temp, largest;

	if(lchild<n && a[lchild]>a[i])
		largest= lchild;
	else
		largest= i;
	if(rchild<n && a[rchild]>a[largest])
		largest= rchild;

	if(largest != i)
	{
		temp= a[largest];
		a[largest]= a[i];
		a[i]= temp;
		max_heapify(a, largest, n);
	}
}
void build_max_heap(int a[], int n)
{
	for(int i= n/2-1; i>=0; i--)
	{
		max_heapify(a, i, n);
	}
	int j;
	cout<<"Built heap: \n";
	for(j=0; j<n; j++)
		cout<<a[j]<<" ";
	cout<<"\n";

}
void heapsort(int a[], int n)
{
	if(n>0)
	{
		cout<<a[0]<<" ";
		int temp=a[0];
		a[0]=a[n-1];
		a[n-1]=temp;
		n--;
		max_heapify(a, 0, n);
		heapsort(a,n);
	}	
}
int main()
{
	int n=10;
	int a[n]= {3, 1, 11, 8, 4, 2, 9, 5, 14, 7};
	int i;
	build_max_heap(a, n);
	cout<<"Sorted heap: \n";
	heapsort(a,n);
	return 0;
}