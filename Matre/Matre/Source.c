#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiMatricu(int mat[10][20], int m, int n) {
	printf("\nElementi matrice su: \n");
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf(" %d\t ", mat[i][j]);
		}
		printf("\n");
	}
}
int dodajElemente(int mat[10][20], int m, int n) {
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf("Unesite [%d][%d] element: ", i, j);
			scanf("%d", &mat[i][j]);
		}
		
	}
	return mat[i][j];
}
void proizvodElIspodGlavne(int mat[10][20], int m, int n) {
	int proizvod = 1;
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j= 0; j < n; j++)
		{
			if (i>j ) {
				proizvod *= mat[i][j];
			}
		}
	}
	
		printf("Proizvod elemenata ispod glavne dijagonale je jednak: \n%d\n", proizvod);
	
}
void dodajUNiz(int niz[], int* k) {
	int brEl;
	int el;

	printf("Koliko elemenata zelite da unesete? \n");
	scanf("%d", &brEl);
	
	
	do {
		printf("\nUnesite neki element:\n");
		scanf("%d", &el);
		niz[(*k)++] = el;
	} while (brEl > *k);
	
}
void ispisiNiz(int niz[],int k) {
	int i;
	for ( i = 0; i < k; i++)
	{
		printf(" %d\t", niz[i]);
	}
}
void pretvoriMatricuUNiz(int mat[10][20], int k, int niz[200]) {
}

int nizUMatricu(int mat[10][20], int niz[], int k) {
	int i, j;
	int a = 0;
	dodajElemente(mat, k, k);
	for ( i = 0; i < k; i++)
	{
		for ( j = 0; j < k; j++)
		{
			niz[a++] = mat[i][j];
			return niz[a];
		}
		
	}
	//printf("Niz koji se sastoji od elemenata matrice: \n%d\n", niz[a]);
}


void main() {
	//zvezdice 
	int n, i, j, k;
	n = 5;
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n - i; j++)			printf(" ");
		for (k = 0; k < i; k++)		printf(" * ");

		printf("\n ");
	}
}
