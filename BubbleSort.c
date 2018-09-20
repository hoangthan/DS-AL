#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=n-1;j>i;j--)
            if(a[j]<a[i])
                swap(&a[i],&a[j]);
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
    BubbleSort(a,n);
    printf("\nSorted array : ");
    for(int i=0;i<n;i++) printf("  %d  ",a[i]);
}

void main()
{
    execute();
}
