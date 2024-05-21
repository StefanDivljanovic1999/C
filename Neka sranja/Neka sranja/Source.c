#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ubaci_u_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}
void ispisi_niz(int niz[], int n) {
	printf("\nElementi niza:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int postoji_u_nizu(int niz[], int n, int el) {
	int i;
	for ( i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
	}
	return 0;
}
void razlika_nizova(int niz[], int n, int niz1[], int n1, int niz2[], int* n2) {
	for (int i = 0; i < n; i++)
	{
		if (postoji_u_nizu(niz, n, niz1[i])==1) {
			ubaci_u_niz(niz2, n2, niz1[i]);
		}
	}
}
void ispisi_matricu(int mat[][3], int m) {
	printf("\nElementi matrice:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		} 
		printf("\n");
	}
}
void napravi_nizove_od_kolona_i_glavne(int mat[][3], int m, int niz[], int* n, int niz1[], int* n1, int kolona) {
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (i == j) {
				ubaci_u_niz(niz, n, mat[i][j]);
			}
			if (j == kolona) {
				ubaci_u_niz(niz1, n1, mat[i][j]);
			}
		}
	}
}
void presek_glavne_i_kolone(int niz[], int* n, int niz1[], int n1, int niz2[], int n2) {
	int i;
	for ( i = 0; i < n1; i++)
	{
		if (postoji_u_nizu(niz1, n1, niz2[i]) == 1) {
			ubaci_u_niz(niz, n, niz2[i]);
		}
	}
}

void main() {
	int mat[][3] = { {1,2,3}, {4,5,6}, {7,8,2} };
	ispisi_matricu(mat,3);
	int niz[100];
	int n = 0;
	int glavna[100];
	int gl = 0;
	int kolona[100];
	int k = 0;
	
	napravi_nizove_od_kolona_i_glavne(mat, 3, glavna, &gl, kolona, &k, 1);
	ispisi_niz(glavna, gl);
	ispisi_niz(kolona, k);
	presek_glavne_i_kolone(niz, &n, glavna, gl, kolona, k);
	ispisi_niz(niz, n);
}