#include <stdio.h>

void printOut(int a[], int n)
{
    for(int i=0;i<n;i++)
        printf(" %d  ",a[i]);
    printf("\n");
}

void backTrack(int a[], int n, int i)
{
    if(i==n) printOut(a,n);
    else
    {
        for(int j=0;j<=1;j++)
        {
            a[i] = j;
            backTrack(a,n,i+1);
        }
    }
}

void main()
{
    int n;
    printf("Generate binary string with length:: ");
    scanf("%d",&n);
    int a[n];
    backTrack(a,n,0);
}

//Other method, generate binary string by loop : https://bugs.vn/12411
