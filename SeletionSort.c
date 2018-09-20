#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int a[], int n)
{
    int pos;
    for(int i=0;i<n-1;i++)
    {
        pos = i;
        for(int j=i+1;j<n;j++) if(a[j] < a[pos]) pos = j;
        swap(&a[pos],&a[i]);
    }
}

void execute()
{
    int n;
    printf(" Number elements of array:  ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    SelectionSort(a,n);
    printf("\nSorted array : ");
    for(int i=0;i<n;i++) printf("  %d  ",a[i]);
}

void main()
{
    execute();
}
