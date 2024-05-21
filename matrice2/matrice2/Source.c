#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiMatricuOdBrojeva(int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)
		{
			printf(" %di  %dj ", i, j);
		}		printf("\n");
		
	}
}

void ispisiMat(int mat[10][20],int m, int n) {
	int i, j;
	printf("Elementi matrice su: \n");
	for (i = 0; i <m; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d\t ", mat[i][j]);
			//printf("\n");
		}
		printf("\n");
	}
}
void unesidimenzijeMat(int* m, int* n) {
	do {
		printf("Unesi dimenzije matrice u formatu mxn , u intervalu od 1 do 200\n");
		scanf("%dx%d", m, n);
	} while (*m<1 || *m>200 || *n<1 || *n>200);
	}
void unesiUMat(int mat[10][20],int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("Unesite [%d][%d]element: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	ispisiMat(mat, m, n);
}

void vratiNajveciEl(int mat[10][20], int m, int n) {
	int i, j;
	int max = 0;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (mat[i][j] > max) {
				max = mat[i][j];
			}
		}
	}
	printf("Najveci element matrice je: \n%d\n", max);
}
void glavnaDijagonala(int mat[10][20], int m, int n) {
	int i, j;
	int suma = 0;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (i != j){
				mat[i][j] = 0;

	}suma += mat[i][j];
		}
	}
	
	//ispisiMat(mat, m, n);
	printf("Suma elemenata na glavnoj diagonali: \n%d\n",suma);
}


void main() {
	int mat[10][20];
	
	
	unesiUMat(mat,4,3);
	vratiNajveciEl(mat, 4, 3);
	glavnaDijagonala(mat, 4, 3);
	

	
}