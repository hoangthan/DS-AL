#include <stdio.h>

void show(int a[], int n)
{
    for(int i=0;i<n;i++) printf("  %d ",a[i]);
    printf("\n");
}

void gen(int a[], int n)
{
    int i=n-1;
    show(a,n);
    while(i>=0)
    {
        if(a[i]==0)
        {
            a[i] = 1;
            for(int j=i+1;j<n;j++) a[j] =0;
            show(a,n);
            i = n-1;
        }
        else i--;
    }
}

void execute()
{
    printf("Length :: ");
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) a[i] = 0;
    gen(a,n);
}

void main()
{
    execute();
}
