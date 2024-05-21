#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor* PCVOR;
typedef struct cvor {
	int podatak;
	struct cvor* sledeci;
}CVOR;

int zbir_cifara(int broj) {
	int suma = 0;
	while (broj != 0) {
		suma += broj % 10;
		broj /= 10;
	}
	return suma;
}
void broj_sa_max_zbirom_cif(){
	int n;
	int broj;
	int max_broj = -1;
	do {
		printf("Unesite zeljeni broj cifara: ");
		scanf("%d", &n);
	} while (n < 0);

	int i = 0;
	while (i < n) {
		printf("Unesite [%d.] broj: ", i+1
);
		scanf("%d", &broj);
		if (zbir_cifara(broj) > zbir_cifara(max_broj)) {
			max_broj = broj;
		}
		i++;
	}
	printf("Broj sa najvecim zbirom cifara od svih unetih je: %d", max_broj);
}
int broj_parnih_trocifrenih_13() {
	int brojac = 0;
	for (int i = 100; i <= 999; i++)
	{
		if (zbir_cifara(i) == 13) {
			brojac++;
		}
	}
	return brojac;
}
void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	printf("Elementi liste su: \n");
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}
void ubaci_na_kraj(PCVOR* pglava, int el) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*pglava == NULL) {
		novi->podatak = el;
		novi->sledeci = *pglava;
		*pglava = novi;
		return;
	}
	PCVOR pom = *pglava;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
	novi->podatak = el;
	novi->sledeci = NULL;
}
int max_liste(PCVOR glava) {
	int max = glava->podatak;
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak > max) {
			max = pom->podatak;
		}
		pom = pom->sledeci;
	}
	return max;
}
int min_liste(PCVOR glava) {
	int min = glava->podatak;
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak < min) {
			min = pom->podatak;
		}
		pom = pom->sledeci;
	}
	return min;
}
void ubaci_na_pocetak(PCVOR* pglava, int el) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	
		novi->podatak = el;
		novi->sledeci = *pglava;
		*pglava = novi;
		
	}
void ubaci_u_sortiranu(PCVOR* pglava, int el) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*pglava == NULL) {
		novi->podatak = el;
		novi->sledeci = *pglava;
		*pglava = novi;
		return;
	}
	if (el >= max_liste(*pglava)) {
		ubaci_na_kraj(pglava, el);
		return;
	}

	PCVOR pom = *pglava;
	if (pom->sledeci == NULL && pom->podatak<el) {
		ubaci_na_kraj(pglava, el);
		return;
	}
	if (pom->sledeci == NULL && pom->podatak >= el) {
		ubaci_na_pocetak(pglava, el);
		return;
	}

	if (min_liste(*pglava) >= el) {
		ubaci_na_pocetak(pglava, el);
		return;
	}

	while (pom->podatak > el) {
		pom = pom->sledeci;
	}
	
	novi->podatak = el;
	novi->sledeci = pom->sledeci;
	pom->sledeci = novi;
}
void prvi_d(PCVOR* pglava,int broj) {
	for (int i = 100; i <= 999; i++)
	{
		if (i % 2 == 0 && zbir_cifara(i) == broj) {
			ubaci_u_sortiranu(pglava, i);
		}
	}
}
void prebaci() {
	FILE* fajl;
	char s[1000];
	for (int i = 100; i < 1000; i += 100)
	{
		sprintf(s, "%d.txt", i);
		fajl = fopen(s, "w");
		for (int j = i; j < i + 100; j += 2)
		{


			if (zbir_cifara(j) == 14) {
				fprintf(fajl, "%d;", j);
			}
		}
	}

	fclose(fajl);
}
void ubaci_u_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void ispisi_matr(int mat[10][20], int m) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
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
void unija_kolona(int mat[10][20],int kolona1, int kolona2, int niz[], int* n) {
	
	for (int j = 0; j < 5; j++)
	{
		if (postoji_u_nizu(niz, *n, mat[kolona1-1][j])==0) {
			ubaci_u_niz(niz, n, mat[kolona1-1][j]);
			
		}
		if (postoji_u_nizu(niz, *n, mat[kolona2 - 1][j]) == 0) {
			ubaci_u_niz(niz, n, mat[kolona2 - 1][j]);

		}
	}
	
}
void main() {
	int mat[10][20] = { {1,2,3,4,5},{2,2,9,0,6},{6,8,2,5,3},{1,5,9,7,3},{7,5,3,8,2} };

	ispisi_matr(mat, 5);
	int niz[100];
	int n = 0;
	unija_kolona(mat, 1, 3, niz, &n);
	ispisi_niz(niz, n);
	
}