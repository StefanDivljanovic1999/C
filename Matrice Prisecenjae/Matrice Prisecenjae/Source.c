#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1500
void ispisiMatricu(int mat[10][20], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void dodajUMat(int mat[10][20]) {
	int m, n;
	printf("Unesite dimenzije matrice:\n");
	scanf("%dx%d", &m, &n);
	for (int i = 0; i <m; i++)
	{
		for (int j = 0; j <n; j++)
		{
			printf("Unesite [%d][%d] element matrice:\n", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	ispisiMatricu(mat, m, n);
}

void ispisiGlavnuDijagonalu(int mat[10][20],int m,int n) {
	int i, j;
	for ( i = 0; i <m; i++)
	{
		for ( j = 0; j <n; j++)
		{
			if (i != j) {
				mat[i][j] = 0;
			}
		}
	}
	ispisiMatricu(mat,m,n);
}
void zbirElMatrice(int mat[10][20], int m,int n) {
	int suma = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <n ; j++)
		{
			suma += mat[i][j];
		}
	}
	printf("Zbir elemenata u matrici je: %d", suma);
}

void ispisiNajveciINajmanjiEL(int mat[10][20], int m, int n) {
	
	int najveci = 0;
	int najmanji =MAX;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] > najveci) {
				najveci = mat[i][j];
			}
			if (mat[i][j] < najmanji) {
				najmanji = mat[i][j];
			}
		}
	}
	printf("Najveci element matrice je: %d\n", najveci);
	printf("Najmanji element matrice je:%d\n", najmanji);
}
void glavna(int mat[10][20], int m, int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) {
				mat[i][j] = 1;
			}
			if (i < j) {
				mat[i][j] = 2;
			}
			if (i > j) {
				mat[i][j] = 3;
			}
		}
	}
	ispisiMatricu(mat, m, n);
}

void transponuj(int mat[10][20], int m, int n) {
	int i, j;
	for ( i = 0; i < m; i++) {
		for ( j = 0; j < i; j++) {
		
				int c = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = c;
			}
		
	}
	ispisiMatricu(mat, m, n);
}

void neparniIParniJ(int mat[10][20], int m, int n) {
	int i, j;
	int suma = 0;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (i % 2 != 0 && j % 2 == 0) {
				suma += mat[i][j];
			}
		}
	}
	printf("Suma elemenata na neparnim i mestima i parnim j mestima je:%d", suma);
}

void dodajUNiz(int niz[100], int* kapac, int n) {
	niz[(*kapac)++] = n;

}
ispisiNiz(int niz[100], int kapac) {
	for (int i = 0; i < kapac; i++) {
		printf("%d\t", niz[i]);
	}
}



void main() {
	int mat[10][20];
	dodajUMat(mat);
	//ispisiGlavnuDijagonalu(mat,3,3);
	//
	//zbirElMatrice(mat, 3, 3);
	printf("\n");
	//ispisiNajveciINajmanjiEL(mat, 3, 3);

	//glavna(mat, 3, 3);
	//transponuj(mat, 3, 3);
	//ispisiMatricu(mat, 3, 3);
	//neparniIParniJ(mat, 3, 3);
	  
	
}