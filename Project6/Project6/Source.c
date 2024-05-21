#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void matrica(int n) {
	int i;
	int j;
	int k;
	for ( i = 0; i <=n; i++)
	{
		printf("*");
		printf(" ");
	}
	printf("\n");
	for ( j = 0; j <= n-1; j++)
	{
		printf(" *");
		printf(" ");
	}
	printf("\n");
	for ( k = 1; k <j-1; k++)
	{
		printf("   *");
		printf(" ");
	}
}

void main() {
	//matrica(3);
	int i;
	int j;
	int k;
	for ( i = 0; i <3; i++)
	{
		printf("*");
		printf("/");
	}
	
}
