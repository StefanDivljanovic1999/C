#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor* PCVOR;

typedef struct cvor {
	int podatak;
	PCVOR sledeci;
}CVOR;

void ubaciPrvi(PCVOR *pglava, int podatak) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = podatak;
	novi->sledeci = *pglava;
	*pglava = novi;

}
void ispisiListu(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		printf("%d ", pom->podatak);
		pom = pom->sledeci;
	}
}

void dodajNaKrajListe(PCVOR* pglava, int p) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = NULL;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
		//sada je pom pokazivac na sledeci!
		pom->sledeci = novi;
	}
}

void main() {
	PCVOR glava=NULL;
	
	ubaciPrvi(&glava, 159);
	ubaciPrvi(&glava, 753);
	ubaciPrvi(&glava, 852);
	ubaciPrvi(&glava, 456);
	ubaciPrvi(&glava, 963);
	ubaciPrvi(&glava, 147);
	//dodajNaKrajListe(&glava, 1999);
	
	ispisiListu(glava);

}

