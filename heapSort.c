#include <stdio.h>

/*
    >> Learn more: https://www.programiz.com/dsa/heap-sort
    >> https://vi.wikipedia.org/wiki/S%E1%BA%AFp_x%E1%BA%BFp_vun_%C4%91%E1%BB%91ng
*/

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int a[], int n, int i)
{
    int root = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l<n && a[root] < a[l]) root = l;
    if(r<n && a[root] < a[r]) root = r;

    if(root!=i)
    {
        swap(&a[root],&a[i]);
        heapify(a,n,root);
	//Tại mỗi node chỉ cần quan tâm đến 2 thằng con của nó, đảm bảo thằng cha là lớn nhất trong 3 thằng.
	//Đệ quy hàm heapify để thằng con lo những thằng con của nó nếu có.
	//Vì cây là cây nhị phân đầy đủ nên mỗi nút thứ i có thể có lá là 2*i+1 và 2*i+2.
    }
}

void heapSort(int a[], int n)
{
    int i;
    for(i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

void execute()
{
    int n;
    printf("Element of the array :: "); scanf("%d",&n);
    int a[n];
    int i=0;
    for(i;i<n;i++)
    {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }

    heapSort(a,n);
    printf("Sorted array : ");
    for(i=0;i<n;i++) printf("  %d  ",a[i]);
}

void main()
{
    execute();
}
