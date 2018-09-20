#include "stdio.h"
#include "stdlib.h"

// A famous puzzle about recursion : how to move n plates from tower A to tower C via middle tower B.
// In on movement you can only move only 1 plate, and the bigger plate must be put under the bigger.

void tower(int sodia, char nguon[], char trunggian[], char dich[])
{
	if(sodia==1) printf("Chuyen dia tu cot |%s| sang cot |%s|\n",nguon,dich);
	else
	{
		tower(sodia-1,nguon,dich,trunggian);
		tower(1,nguon,trunggian,dich);
		tower(sodia-1,trunggian,nguon,dich);
	}
}

void main()
{
	printf("\n\t ---- HA NOI TOWER----\n");
	printf("\n\t A :  Cot dau tien.");
	printf("\n\t B :  Cot o giua.");
	printf("\n\t C :  Cot cuoi cung.\n\n" );
	char a[10], b[10], c[10];
	int sodia;
	printf("Nhap ten cot A :  "); scanf("%[^\n]",a);
	printf("Nhap ten cot B :  "); scanf("%c",b); scanf("%[^\n]",b);
	printf("Nhap ten cot C :  "); scanf("%c",c); scanf("%[^\n]",c);
	printf("Nhap so dia : "); scanf("%d",&sodia); 
	tower(sodia,a,b,c);
}