#include "conio.h"
#include "stdio.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r)
{
    int i=l-1;
    int j=l;
    int pivot = a[r];
    for(j;j<r;j++) if(a[j]<pivot)
    {
        i++;
        swap(&a[i],&a[j]);
    }
    swap(&a[r],&a[i+1]);
    return i+1;
}

void quickSort(int a[], int l, int r){
    if(l<r)
    {
        int flag = partition(a,l,r);
        quickSort(a,l,flag-1);
        quickSort(a,flag+1,r);
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
    quickSort(a,0,n-1);
    printf("Sorted array : ");
    for(int i=0;i<n;i++) printf("   %d   ",a[i]);
}