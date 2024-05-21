#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct karta {
	int napad;
	int izdrzljivost;
	char naziv[50];

} KARTA;
typedef struct cvor CVOR;
typedef CVOR* PCVOR;
struct cvor {
	KARTA info;
	PCVOR sledeci;
};
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza su:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void ispisi_matricu(int mat[10][10], int m, int n) {
	printf("Elementi matrice su:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void invertuj_niz(int niz[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		int tmp = niz[i];
		niz[i] = niz[n - i - 1];
		niz[n - i - 1] = tmp;
	}
}
void niza(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		niz[i] = niz[i];
	}
}
void lanac(int niz[], int n, int razlika) {
	int br = 0;
	do {
		int tmp = niz[n - 1];

		for (int i = n - 1; i > 0; i--)
			niz[i] = niz[i - 1];

		niz[0] = tmp;
		br++;
	} while (br != razlika);

}
void prebaciUMatricu(int niz[], int n, int mat[10][10], int m) {
	int i, j;
	int s = 0;
	//invertuj_niz(niz, n);
	


		for (i = 0; i < m; i++)
		{

			for (j = 0; j < m; j++)
			{

				mat[i][j] = niz[j];

			}
			lanac(niz, n, n - m);
		}
	
	ispisi_matricu(mat, m, m);
}
void zadatak1(int* niz, int n, int mat[10][10], int m) {
	prebaciUMatricu(niz, n, mat, m);
	ispisi_matricu(mat, m, m);
}
int proveriKartu(KARTA karta) {
	if (karta.napad < 0 || karta.napad>10) {
		return 0;
	}
	if (karta.izdrzljivost < 1 || karta.izdrzljivost>12) {
		return 0;
	}
	if (!(karta.naziv[0] >= 65 && karta.naziv[0] <= 90)) {
		return 0;
	}
	return 1;
}
int broj_karata(PCVOR spil) {
	int br = 0;
	PCVOR pom = spil;
	while (pom != NULL) {
		br++;
		pom = pom->sledeci;
	}
	return br;
}
int dodajKartu(KARTA karta, PCVOR * spil) {
	if (broj_karata(*spil) < 10 && proveriKartu(karta) == 1) {
		PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
		novi->info = karta;
		novi->sledeci = *spil;
		*spil = novi;
		return 1;
	}
	else {
		return 0;
	}
}
void ispisi_kartu(KARTA k) {
	printf("Naziv: %s, izdrzljivost:%d, napad:%d\n", k.naziv, k.izdrzljivost, k.napad);
}
void ispisi_karte(PCVOR spil) {
	
	PCVOR pom = spil;
	while (pom != NULL) {
		ispisi_kartu(pom->info);
		pom = pom->sledeci;
	}
	
}
void ucitajKarte(char* naziv, PCVOR* spil) {
	char ime_prezime[100];
	int izdrzljivost;
	int napad;
	KARTA k;
	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL) {
		printf("Fajl nije prondjen!!!");
		return;
	}
	char s[1000];
	while (1) {
		strcpy(ime_prezime, fgets(s, 1000, fajl));
		fscanf(fajl, "%d,%d", &napad, &izdrzljivost);
		printf("%s\t%d\t%d\n", ime_prezime, napad, izdrzljivost);
		strcpy(k.naziv, ime_prezime);
		k.napad = napad;
		k.izdrzljivost = izdrzljivost;
		dodajKartu(k, spil);
		if (fgets(s, 1000, fajl) == NULL || fscanf(fajl, "%d,%d", &napad, &izdrzljivost)==EOF) {
			break;
		}
}
	fclose(fajl);
}
int odigrajNapad(KARTA karta1, KARTA karta2) {
	if (karta1.napad > karta2.izdrzljivost && karta2.napad<karta1.izdrzljivost) {
		return 1;
	}
	else if (karta1.napad<karta2.izdrzljivost && karta2.napad>karta1.izdrzljivost) {
		return -1;
	}
	else {
		return 0;
	}
}
void izbaciKartu(PCVOR * spil) {
	PCVOR pom = *spil;
	pom = pom->sledeci;
	*spil = pom;
}

void main() {
	
	PCVOR spil = NULL;
	ucitajKarte("fudbaleri.txt", &spil);
	ispisi_karte(spil);
	izbaciKartu(&spil);
	ispisi_karte(spil);
}