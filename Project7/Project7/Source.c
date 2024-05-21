#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cvor* PCVOR;

typedef struct cvor {
	int podatak;
	PCVOR sledeci;
}CVOR;

void ubaciElement(PCVOR* pglava, int p) {
	PCVOR novi=(PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
}

void ispisiListu(PCVOR glava) {
	PCVOR pom = glava;
	while (pom !=  NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}
void brojElListe(PCVOR glava) {
	PCVOR pom = glava;
	int brojac = 0;
	while (pom != NULL) {
		pom = pom->sledeci;
		brojac++;
	}
	printf("Broj elemenata u listi je jenak: %d", brojac);
}
void ubaciNaPoslednjeMesto(PCVOR* pglava, int p) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = NULL;

	if (*pglava == NULL) {
		*pglava = novi;
		return;
	}

	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
}

int izbaciPrvi(PCVOR* pglava) {
	int p;
	PCVOR pom = *pglava;
	if (pom == NULL) {
		printf("Lista je prazna!!!");
		return;
	}
	*pglava = (*pglava)->sledeci;
	p = pom->sledeci;
	free(pom);
	return p;
}


void ubaciNaPrvoMesto(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
}

void ispisi(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}

void ubaciNaZadnje(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = NULL;
	PCVOR pom = *pglava;
	
	
	if (*pglava == NULL) {
		*pglava = novi;
		return;
	}
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	
	pom->sledeci = novi;
}

void main() {
 //lista je pokazivac na prvi element te liste!
	PCVOR glava=NULL;
	/*ubaciNaPrvoMesto(&glava, 9500);
	ubaciNaPrvoMesto(&glava, 1682);
	ubaciNaPrvoMesto(&glava, 1435);
	ubaciNaPrvoMesto(&glava, 7536);*/
	ubaciNaZadnje(&glava, 1999);
	
	ispisi(glava);
	

	

  
}