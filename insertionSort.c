#include <stdio.h>

void insertionSort(int a[], int n)
{
    int i,j;
    int temp;
    int pos;
    for(i=1;i<n;i++)
    {
        if(a[i]<=a[0])
        {
            temp = a[i];
            for(j=i;j>0;j--) a[j] = a[j-1];
            a[0] = temp;
        }
        else if(a[i]>=a[i-1]) continue;
        else
        {
            temp = a[i];
            for(pos=0;pos<n;pos++)
                if(a[pos] > a[i]) break;
            for(j=i;j>pos;j--)
                a[j] = a[j-1];
            a[pos] = temp;
        }
    }
}

void execute()
{
    printf("Number elements of the array:: ");
    int n; scanf("%d",&n);
    int a[n];

    for(int i=0;i<n;i++)
    {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("Sorted array : ");
    for(int i=0;i<n;i++) printf("  %d  ",a[i]);
}

void main()
{
    execute();
}
