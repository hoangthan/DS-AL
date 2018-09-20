#include "conio.h"
#include "stdio.h"


void merge(int a[], int l, int mid, int r)
{
	int i=l,j=mid+1,k=0;
	int temp[r-l+1];
	while(i <= mid && j<=r)
	{
		if(a[i] < a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	if(i<=mid)
		for(i;i<=mid;i++) temp[k++] = a[i];
	if(j<=r)
		for(j;j<=r;j++) temp[k++] = a[j];
	for(i=l;i<=r;i++)
		a[i] = temp[i-l];
}

void split(int a[], int l, int r)
{
	if(l<r)
	{
		int mid = (l+r)/2;
		split(a,l,mid);
		split(a,mid+1,r);
		merge(a,l,mid,r);
	}
}


void main()
{
	int n,i;
	printf("Number of elements : ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("a[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	split(a,0,n-1);
	printf("Sorted array : ");
	for(i=0;i<n;i++)
	printf("  %d  ",a[i]);
}
