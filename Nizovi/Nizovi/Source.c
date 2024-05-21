#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main() {
	int i;
	int niz[10];
	for ( i = 0; i < 10; i++)
	{
		scanf("%d", &niz[i]);
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d", &niz[i]);
	}
	system("pause");
}