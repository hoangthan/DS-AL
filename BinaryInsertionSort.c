#include <stdio.h>

/*
    Binary insertion sort is an improvement of insertion sort algorithm.
    Using binary searching to find the position where to insert instead of using linear search.
*/

int Search(int a[], int n, int i)
{
	int l = 0, r = n;
	int mid;
	while(l<r)
	{
		mid = (l+r)/2;
		if(i==a[mid]) return mid;
		else if( i < a[mid]) r= mid-1;
		else l= mid+1;
	}
	if(i>a[l]) return l+1;
	return l;
}

void Sort(int a[], int n)
{
	int i,j;
	int temp;
	int pos;

	for(i=1;i<n;i++)
	{
		if(a[i] >= a[i-1]) continue;

		else if(a[i] <= a[0])
		{
			temp = a[i];
			for(j=i;j>0;j--) a[j] = a[j-1];
			a[0] = temp;
		}

		else
		{
			pos = Search(a,n-1,a[i]);
			temp = a[pos];
			for(j=i;j>pos;j--) a[j] = a[j-1];
			a[pos] = temp;
		}

	}
}

void execute()
{
	printf("Number of elements in the array :: ");
	int n;   scanf("%d",&n);
	int a[n];

	for(int i=0;i<n;i++)
	{
		printf("a[%d]= ",i+1);
		scanf("%d",&a[i]);
	}

	Sort(a,n);

	printf("Sorted array : ");
	for(int i=0;i<n;i++) printf("  %d  ",a[i]);
}

void main()
{
	execute();
}
