#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ispisi_matricu(int mat[5][5], int m) {
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void unesi_u_matricu(int mat[3][3], int m) {
	int i, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			printf("Unesite [%d][%d] element: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}
void ispisi_niz(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int palindrom_red(int mat[3][3], int m, int red) {
	int i;
	int niz[10];
	for (int j = 0; j < m; j++)
	{
		niz[j] = mat[red][j];
		
	} printf("\n");
	for (i = 0; i < m / 2; i++) {
		if (niz[i] == niz[m - i - 1]) {
			return 1;
		}
	}
	return 0;
}
int postoji_u_nizu(int niz[], int m, int el) {
	int i;
	for ( i = 0; i < m; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
	}
	return 0;
}
void razlika_redova(int mat[3][3], int m, int red1, int red2) {
	int niz1[100];
	int niz2[100];
	int niz3[100];
	int j;
	for ( j = 0; j < m; j++)
	{
		niz1[j] = mat[red1][j];
		niz2[j] = mat[red2][j];
	
		if (postoji_u_nizu(niz2, m, niz1[j]) == 0) {
			
			niz3[j] = niz1[j];
		}

	}
	printf("\nElementi niza koji predstavljaju razliku redova je:\n");
	ispisi_niz(niz3, m);
}
void sortiraj_red(int mat[3][3], int m, int red) {
	int j;
	for ( j = 0; j < m; j++)
	{
		if (mat[red][j] < mat[red][j++]) {
			int tmp = mat[red][j];;
			mat[red][j] = mat[red][j++];
			mat[red][j++] = tmp;
		}
		
	}
	ispisi_matricu(mat, 3);
}
void unesi_u_niz(int niz[], int* m, int el) {
	niz[(*m)++] = el;
}
int ima_podniz_parnih(int niz[], int n) {
	int max_index, max_velicina = 0;
	int t_index, t_velicina = 0;
	int i = 0;
	while (i < n) {
		while (niz[i] % 2 != 0 && i < n) {
			i++;
	 }
		t_index = i;
		t_velicina = 0;
		while (niz[i] % 2 == 0 && i < n) {
			t_velicina++;
			i++;
		}
		if (max_velicina < t_velicina) {
			max_index = t_index;
			max_velicina = t_velicina;
		}
	} 
	max_velicina++;
	//printf("Velicina najduzeg podniza parnih brojeva je: %d\n", max_velicina-1);

	if ((max_velicina - 1) >= 2) {
		return 1;
	}
	return -1;
}
void prebaci_obod_u_niz(int mat[3][3], int m, int niz[], int* n) {
	*n = 0;
	int i=0, j;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (i == 0 || j==0 || i==m-1 || j==m-1) {
				unesi_u_niz(niz, n, mat[i][j]);
			}
		}
	}
}
int da_li_postoji(int niz[], int n, int element) {
	int i;
	for ( i = 0; i < n; i++)
	{
		if (niz[i] == element) {
			return 1;
		}
	}
	return 0;
}
int broj_ponavljanja_u_nizu(int niz[], int n, int element) {
	int i,brojac = 0;
	for ( i = 0; i < n; i++)
	{
		if (niz[i] == element) {
			brojac++;
		}
	}
	return brojac;
}
void unija_kolona(int mat[5][5],int k1, int k2, int niz[], int* n) {
	int i, j;
	*n = 0;
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			if ((j == k1 || j == k2 ) && postoji_u_nizu(niz,*n,mat[i][j])==0) {
				unesi_u_niz(niz, n, mat[i][j]);
			}
		}
	}
	
}
void presek_glavne_i_kolone(int mat[5][5], int m, int kolona, int niz[], int* n) {
	int i, j;
//	*n = 0;
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (i == j) {
				unesi_u_niz(niz, n, mat[i][j]);
		    }
			
		}
	}
	for ( i = 0; i < m; i++)
	{
		for ( j = 0; j < m; j++)
		{
			if (postoji_u_nizu(niz, n, mat[kolona][j]) = 1) {
				unesi_u_niz(niz, n, mat[kolona][j]);
			}
		}
	}
}

void main() {
	int niz[100];
	int n=0;
	int mat[][5] = { {1,2,2,4,5},{6,7,7,9,10},{11,2,13,14,15},{16,17,23,19,20},{21,22,23,24,2} };
	ispisi_matricu(mat, 5);
	
	printf("\n");
	presek_glavne_i_kolone(mat, 5, 2, niz, &n);
	ispisi_niz(niz, n);
	
}