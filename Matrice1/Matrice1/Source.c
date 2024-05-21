#define _CRT_SECURE_NO_WARNINGS
#define MIN -215009
#include <stdio.h>

void ispisi(int mat[10][10], int m, int n) {
	printf("\nElementi matrice: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%5d", mat[i][j]);
		}
		printf("\n");
	}
}
void unesi_matricu() {
	int mat[10][10];
	printf("Unesite dimenziju matrice: ");
	int m, n;
	scanf("%dx%d", &m, &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Unesite [%d][%d] element matrice: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
	ispisi(mat, m, n);
}
int suma_reda(int mat[10][10], int m, int n, int red) {
	int suma = 0;
	
		for (int j = 0; j < n; j++)
		{
			suma += mat[red - 1][j];
		}
	
	return suma;
}
void suma_svih_redova(int mat[10][10], int m, int n) {
	ispisi(mat, m, n);
	for (int i = 1; i <= m; i++)
	{
		printf("Suma %d reda: %d\n", i , suma_reda(mat, m, n, i));
	}
}
int suma_kolone(int mat[10][10], int m, int n, int kolona) {
	int suma = 0;
	for (int i = 0; i < m; i++)
	{
		suma += mat[i][kolona-1];
	}
	return suma;
}
void napravi_niz_od_matrice(int mat[10][10], int m, int n, int niz[], int* n1) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			niz[(*n1)++] = mat[i][j];
		}
	}
}
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza su:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void niz_od_el_ispod_gl_dijagonale(int mat[10][10], int m, int n, int niz[], int* n1) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j >= m) {
				niz[(*n1)++] = mat[i][j];
			}
		}
	}
}
void prikaz_iznad_gl_dijagonale(int mat[10][10], int m) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + j <= m-2) {
				printf("%d\t", mat[i][j]);
			}
		}
	}
}
int palindromski_niz(int niz[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		if (niz[i] != niz[n - 1 - i]) {
			return 0;
		}
	}
	return 1;
	
}
int da_li_je_red_palindrom(int mat[10][10], int m, int n ,int niz[], int* k) {
	int red;
	printf("Unesite red koji zelite da proverite:");
	scanf("%d", &red);

	for (int j = 0; j < n; j++)
	{
		niz[(*k)++] = mat[red][j];
	}
	
	if (palindromski_niz(niz, *k) == 1) {
		return 1;
	}
	return 0;
}
void razlika_redova(int mat[10][10], int m, int n, int red, int red1) {
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[red][j] - mat[red1][j]);
		}
	
}
int je_rastuci(int mat[10][10], int m, int n, int red) {
	
	for (int j = 0; j < n-1; j++)
	{
		for (int k = j+1; k < n; k++)
		{
			if (mat[red][j] > mat[red][k]) {
				return 0;
			}
		}
	}
	return 1;
}
int ima_podniz_parnih(int niz[], int n) {
	int i = 0;
	while (i < n) {
		if (niz[i] % 2 == 0 && niz[i + 1]%2== 0 && niz[i + 2] % 2 == 0) {
			return 1;
		}
		i++;
	}
	return 0;
}
void prebaci_obod_u_niz(int mat[10][10], int m, int n, int niz[], int* k) {
	for (int j = 0; j < n; j++)
	{
		niz[(*k)++] = mat[0][j];
	}

	for (int j = 0; j < n; j++)
	{
		niz[(*k)++] = mat[n - 1][j];
	}

	for (int i = 1; i < n-1; i++)
	{
		niz[(*k)++] = mat[i][0];
	}

	for (int i = 1; i < n-1; i++)
	{
		niz[(*k)++] = mat[i][n-1];
	}
}
void podnizovi_parnih_brojeva(int niz[], int *n)
{
	int i = 0, n1 = 0;      // n1 je indeks novog niza

	while (i < *n) {   // od pocetka do kraja niza

		// Dok tekuci nije paran
		while (niz[i] % 2 != 0)
			i++;                    // predji na sledeceg

		// Dok su i tekuci i sledeci parni
		while (niz[i] % 2 == 0 && niz[i + 1] % 2 == 0)
			niz[n1++] = niz[i++];       // tekuci stavi u niz

		// Bez ovog if-a podnizovi bi bili skraceni za jedan element
		// probaj da iskljucis taj if i videces problem:

		if (niz[i - 1] % 2 == 0) // ako je prethodni od trenutnog paran
			niz[n1++] = niz[i++];       // i njega (tekuci) stavi u niz

		i++;    // predji na sledeceg
	}

	*n = n1;    // novi broj clanova niza

	printf("\n podnizovi_parnih_brojeva \n");
	ispisi_niz(niz, *n);
}
int postoji_u_nizu(int niz[], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
	}
	return 0;
}
int ekviv_dijagonale(int mat[10][10], int n, int niz1[], int* n1, int niz2[], int* n2) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) {
				niz1[(*n1)++] = mat[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1) {
				niz2[(*n2)++] = mat[i][j];
			}
		}
	}

	for (int i = 0; i < *n2; i++)
	{
		if (postoji_u_nizu(niz1, *n1, niz2[i]) == 0) {
			return 0;
		}
	}
	return 1;
}
int najveci_neparni(int mat[10][10], int n, int kolona) {
	int max = MIN;
	for (int j = 0; j < n; j++)
	{
		if (mat[j][kolona] > max && mat[j][kolona]%2!=0) {
			max = mat[j][kolona];
		}
	}
	return max;
}
void transformisi_matricu(int mat[10][10], int m, int n) {
	for (int i = 0; i < m; i++)
	{
			if (mat[i][8] == 0) {
				mat[i][8]= najveci_neparni(mat, n, i);
				//ovo ne znam!

			}

		
	}
}

void napravi_matricu_od_niza(int niz[], int n, int mat[10][10], int m) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			
				mat[i][j] = niz[i];
			
		}
	}
	ispisi(mat, 3, 3)
		;
}

double prosek_iznad_glavne_dijagonale(int mat[10][10], int n) {
	int suma = 0;
	
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j) {
				suma += mat[i][j];
				brojac++;
			}
		}
	}
	return (double)suma / brojac;
}

void transponuj(int mat[10][10], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			int c = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = c;
		}
	}
}




void main() {
	int mat[10][10];
	mat[0][0] = 1;
	mat[0][1] = 2;
	mat[0][2] = 3;
	mat[1][0] = 4;
	mat[1][1] = 5;
	mat[1][2] = 6;
	mat[2][0] = 7;
	mat[2][1] = 8;
	mat[2][2] = 9;
	
	
	

	ispisi(mat, 3, 3);

	
	printf("\n");
	printf("Presek elemenata iznad glavne dijagonale je: %.2lf\n", prosek_iznad_glavne_dijagonale(mat, 3));
	transponuj(mat, 3);
	ispisi(mat,3,3);
	
}