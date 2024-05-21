#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiMatricu(int mat[10][20],int m,int n) {
	int  i, j;
	

	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			printf(" %d\t ", mat[i][j]);
		}
		printf("\n");
	}
}

void unesiUMatricu(int mat[10][20]) {
	int m, n, i, j;
	printf("Unesite broj redova i kolona u formatu mxn:\n");
	scanf("%dx%d", &m, &n);

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("Unesite [%d][%d] element:\n",i,j);
			scanf("%d", &mat[i][j]);
		}
		printf("\n");
	}
}

void unesiPoPoziciji(int mat[10][20],int m, int n,  int red, int kolona, int vrednost) {
	int i, j;
	
	mat[red][kolona] = vrednost;
		
		
	
}

void sporednaDiagonala(int mat[10][20], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for ( j = 0; j < n; j++)
		{
			if (j == (n-1) - i) {
				printf("%d\t",mat[i][j] );
			}
		}
	}
}
void maxNeparanElMatrice(int matp[10][20], int m, int n) {
	int i, j;
	int max = 0;

	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (matp[i][j] > max && matp[i][j] % 2 != 0) {
				max = matp[i][j];
			}
		}
	}
	printf("Najveci neparni element unete matrice je: %d\n", max);
}
void simetricnaMatrica(int mat[10][20], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			int c;
			if (i > j) {
				c = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = c;
			}
		}
	}
	ispisiMatricu(mat, 3, 3);
}

void main() {
	int mat[10][20];
	unesiUMatricu(mat);
	//unesiPoPoziciji(mat, 4, 3, 0, 2, 5);
	ispisiMatricu(mat,3,3);
	printf("\n");
	sporednaDiagonala(mat, 3, 3);
	printf("\n");
	ispisiMatricu(mat, 3, 3);
	printf("\n");
	maxNeparanElMatrice(mat, 3, 3);
	simetricnaMatrica(mat, 3, 3);
	printf("\n");
	//ispisiMatricu(mat, 3, 3);
}