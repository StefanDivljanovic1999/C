#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiNiz(int niz[], int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		printf(" %d ", niz[i]);
	}
}
void unesiElUNiz(int niz[], int* n,int brEl) {
	int element;
	do {
		printf("Unesite neki element: ");
		scanf("%d", &element);
	} while (brEl !`= n);
	niz[*n++] = element;
}


void main() {
	int niz[200];
	int n = 0;
	unesiElUNiz(niz, &n,5);
	ispisiNiz(niz, 5);
}