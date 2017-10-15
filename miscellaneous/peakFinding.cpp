#include <iostream>
#include <stdio.h>

using namespace std;

void peak(int begin, int end, int a[])
{
	int mid = (begin+end)/2;

	if( a[mid] >= a[mid-1] && a[mid]>=a[mid+1]){
		printf("Peak Exists at %d\n", mid );
	}

	else if (a[mid-1] > a[mid])
	{
		end = mid;
		peak(begin, end, a);
	}
	else if (a[mid+1] > a[mid])
	{
		begin= mid+1;
		peak(begin, end, a); 
	}
	else
		printf("%s\n","No Peak" );	

}

int main()
{
	int a[8]= {0,1,2,5,3,2,3,1};
	int begin= 0;
	int end= 7;
	peak (begin, end, a);
	return 0;
}

