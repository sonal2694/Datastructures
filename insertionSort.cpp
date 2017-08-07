#include <iostream>
#include <stdio.h>

using namespace std;

int a[10]= {3,1,5,11,2,8,7,4,10,6};
int binaryInsertion(int begin, int end, int i)
{
	int mid= (begin+end)/2;
	//int temp;

	if (end <= begin)
        return (a[i] > a[end])?  (end + 1): end;

	if(a[i]>= a[mid] && a[i]<=a[mid+1])
	{
		return mid+1;
		/*temp= a[i];
		a[i]= a[mid+1];
		a[mid+1]= temp;*/
	}
	else if(a[i]> a[mid])
	{
		begin= mid+1;
		return binaryInsertion(begin, end, i);
	}
	
	return binaryInsertion(begin, mid, i);
	
}

int main()
{
	int i,j,temp;
	int begin;
	int loc, item;

	for(i=1; i<10; i++)
	{
		begin= 0;
		j= i-1;
		item= a[i];
		loc= binaryInsertion(begin, j, i);

		while(j>= loc)
		{
			a[j+1]= a[j];
			j--;
		}
		a[j+1]= item;
		/*for(j=0; j<=i-1; j++)
		{
			if(a[j]>a[i])
			{
				temp= a[i];
				a[i]= a[j];
				a[j]= temp;
			}
		}*/
	}
	cout<<"The sorted array is\n";
	for (i = 0; i < 10; i++)
	{
		cout<<a[i]<< " ";
	}
	return 0;
}
