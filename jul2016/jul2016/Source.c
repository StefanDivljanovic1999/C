#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct cvor CVOR;
typedef struct cvor* PCVOR;
struct cvor {
	int broj;
	PCVOR sledeci;
};


void ispisi_matricu(int mat[10][10], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void ucitaj_matricu(char* naziv, int mat[10][10], int *n) {
	FILE* fajl = fopen(naziv, "r");
	
	if (fajl == NULL) {
		printf("Trazena datoteka nije pronadjena!!!");
		return;
	}
	int k;
	fscanf(fajl, "%d", &k);
	*n= (int)sqrt(k) ;
	printf("%d\n", *n);
	
	
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			fscanf(fajl, "%d", &mat[i][j]);
		}
	}
	
	

	fclose(fajl);
}
int izracunaj_zbir_kolone(int j, int mat[10][10], int n){
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += mat[i][j ];
	}
	return suma;
	}
int izracunaj_zbir_reda(int i, int mat[10][10], int n) {
	int suma = 0;
	for (int j = 0; j < n; j++)
	{
		suma += mat[i][j];
	}
	return suma;
}
void dodaj_zbirove(int mat[10][10], int* n) {
	for (int i = 0; i < *n+1; i++)
	{
		mat[i][*n] = izracunaj_zbir_reda(i, mat, *n);
		for (int j = 0; j < *n+1; j++)
		{

			
			mat[*n][j] = izracunaj_zbir_kolone(j, mat, *n);
			
		}
	}

	(*n)++;
}
void prikazi(int mat[10][10], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == n - 2) {
				printf("%d\t|", mat[i][j]);
			}
			
			else {
				printf("%d\t", mat[i][j]);
			}
		}
		printf("\n");
	}
	
}
void dodaj_na_pocetak(int broj, PCVOR* glava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->broj = broj;
	novi->sledeci = *glava;
	*glava = novi;
}
void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	printf("Elementi liste su:\n");
	while (pom != NULL) {
		printf("%d\t", pom->broj);
		pom = pom->sledeci;
	}
}
void prebaci_zbirove(int mat[10][10], int n, PCVOR* glava) {
	for (int i = 0; i < n; i++)
	{
		dodaj_na_pocetak(mat[i][n - 1], glava);
		}
		for (int j = n-2; j >=0; j--)
		{
			
			dodaj_na_pocetak(mat[n-1][j], glava);
		}
	
}
int br_ponavljanja(PCVOR glava, int el) {
	PCVOR pom = glava;
	int br = 0;
	while (pom != NULL) {
		if (pom->broj == el) {
			br++;
		}
		pom = pom->sledeci;
	}
	return br;
}
int sve_razliciti(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		if (br_ponavljanja(glava, pom->broj) > 1) {
			return 0;
		}

		pom = pom->sledeci;
	}
	return 1;
}
int postoji_u_listi(PCVOR glava, int el) {
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->broj == el) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}
void prebaci_na_pocetak(int broj, PCVOR* glava) {
	if (!postoji_u_listi(*glava, broj)) {
		dodaj_na_pocetak(broj, glava);
	}
	else {
		PCVOR pom = *glava;
		while (pom->broj != broj) {
			pom = pom->sledeci;
		}
		
		(*glava)->sledeci = pom->sledeci;
	
		*glava = pom;

	}
}

void main() {
	PCVOR glava = NULL;
	int mat[10][10];
	int n = 0;
	ucitaj_matricu("ulaz.txt", mat, &n);
	dodaj_zbirove(mat, &n);
	prebaci_zbirove(mat, n, &glava);
	ispisi_listu(glava);
	printf("\nSvi razliciti: %d\n", sve_razliciti(glava));
	//prebaci_na_pocetak(5, &glava);
	//prebaci_na_pocetak(18, &glava);
	prebaci_na_pocetak(47, &glava);
	ispisi_listu(glava);
}