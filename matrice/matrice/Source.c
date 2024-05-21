#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisimat(int mat[][200], int m, int n) {
	int i,j;
	for ( i = 0; i < m-1; i++)
	{
		for (j = 0; j < n-1; j++) {
			printf(" %d ", mat[i][j]);
		}
			printf("\n");
		
	}
}

void unesiDimenzije(int mat[][200],int* m, int* n) {

}


void main() {
	int mat[4][4];
	mat[0][0] = 3;
	mat[0][1] = 6;
	mat[0][2] = 5;
	mat[1][0] = 3;
	mat[1][1] = 8;
	mat[1][2] = 1;
	mat[2][0] = 9;
	mat[2][1] = 9;
	mat[2][2] = 9;
	ispisimat(mat, 3, 3);
}