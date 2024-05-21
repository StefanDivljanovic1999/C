#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
	char br_indeksa[100];
	char ime_prezime[100];
}STUDENT;

typedef struct predmet  {
	int sifra_predmeta;
	char naziv_predmeta[1000];
}PREDMET;

typedef struct prijava {
	char br_indeksa[100];
	int sifra_predmeta;
	int ocena;
}PRIJAVA;

struct cvor {
	int podatak;
	struct cvor* sledeci;
}CVOR;

typedef struct cvor* PCVOR;

void unesi_prijavu(PCVOR* pglava, char br_indeksa[], int sifra, int ocena) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	
}
int zbir_cifara(int broj) {
	int cifra;
	int zbir = 0;
	while (broj != 0) {
		cifra= broj % 10;
		zbir += cifra;
		broj /= 10;
		
	}
	return zbir;
}
void dodaj_u_niz(int niz[], int br, int*n) {
	niz[(*n)++] = br;
}
int n_brojeva_max_zbir_cif() {
	int broj;
	int n;
	int brojac = 0;
	int max = -15030;
	
	printf("Unesite koliko brojeva zelite da unesete: ");
	scanf("%d", &n);
	while (brojac < n) {
		printf("Unesite %d. broj: ", brojac + 1);
		scanf("%d", &broj);
		printf("Zbir cifara:%d\n", zbir_cifara(broj));
		int tmp = broj;
		if (tmp > max) {
			max = tmp;
		}
		brojac++;
	}

	return max;
}
int max_list(PCVOR glava) {
	int max = -25000;
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak > max) {
			max = pom->podatak;
		}
		pom = pom->sledeci;
	}
	return max;
}
void ubaci_na_kraj(PCVOR* pglava, int p) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));

	if (*pglava == NULL) {
		if (*pglava == NULL) {
			novi->podatak = p;
			novi->sledeci = *pglava;
			*pglava = novi;
			return;
		}
	}
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
	novi->podatak = p;
	novi->sledeci = NULL;
}
void ubaci_u_sortiranu(PCVOR* pglava, int p) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*pglava == NULL) {
		novi->podatak = p;
		novi->sledeci = *pglava;
		*pglava = novi;
		return;
	}
	if (max_list(*pglava) < p) {
		novi->podatak = p;
		novi->sledeci = *pglava;
		*pglava = novi;
		return;
	}
	while (pom->sledeci->podatak > p) {
		pom = pom->sledeci;
	}
	novi->sledeci = pom->sledeci;
	pom->sledeci = novi;
	
novi->podatak = p;
}
void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	printf("Elementi liste su:\n");
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}
void parni_trocifr_u_listu(PCVOR* pglava, int br) {
	for (int i = 100; i <=999; i++)
	{
		if (i % 2 == 0 && zbir_cifara(i)==br) {
			ubaci_u_sortiranu(pglava,i);
		}
	}
}
int stotina(int broj) {
	return broj / 100;
}
void ubaci_u_tu_stotinu(int broj) {
	
		
		char s[10];
		for (int i = 100; i <= 999; i += 100)
		{
			sprintf(s, "%d.txt", i);
			FILE* fajl = fopen(s, "w");
			for (int j =i; j <i+100; j+=2) {

				if (j % 2 == 0 && zbir_cifara(j) == broj) {
					fprintf(fajl, "%d;", j);
				}
			}
			fclose(fajl);
		}
	
		
}
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza su: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void niz_fajl(int niz[],int *n, int niz1[], int* n1) {
	char s[100];
	FILE* fajl = fopen("ulaz.txt", "r");
	*n =atoi(fgets(s, 100, fajl));
	printf("%d", *n);
	*n = 0;
	char* token = strtok(fgets(s, 100, fajl), ";");
	while (token != NULL) {
		int c = atoi(token);
		niz[(*n)++] = c;
		token = strtok(NULL, ";");
	}
	*n1 = atoi(fgets(s, 100, fajl));
	printf("%d", *n);
	*n1 = 0;
	char* token1 = strtok(fgets(s, 100, fajl), ";");
	while (token1 != NULL) {
		int c = atoi(token1);
		niz1[(*n1)++] = c;
		token1 = strtok(NULL, ";");
	}
}
void dodaj_pre_prvog_veceg(int niz[], int* n, int el) {
	int i=0;
	while (niz[i] < el) {
		i++;
	}
}
void procitaj_podatke() {
	long brojac = 0;
	FILE* fajl = fopen("uki.txt", "r");
	char slovo;
	while (((slovo = fgetc(fajl)) != EOF) && slovo!='A') {
		if (slovo >= 'a' && slovo <= 'e') {
			printf("%c\t", slovo);
			brojac++;
		}
	}
	printf("Broj odogovarajucih je: %d\n", brojac);
}

void ASCII() {
	for (int i = 0; i < 256; i++)
	{
		printf("%d\t%c\n", i, i);
	}
}


void main() {
	int i;
	printf("Unesite neki broj: ");
	scanf("%d", &i);
	switch (i)
	{
	case(1):printf("Pondeljak");
		break;
	case(2):printf("Utorak");
		break;
	case(3):printf("Sreda");
		
	case(4):printf("Cetvrtak");
	case(5):printf("Petak");
	case(6):printf("Subota");
	default:printf("Nedelja");
		break;
	}
}
 