#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct cvor* PCVOR;
typedef struct cvor
{
	int podatak;
	PCVOR sledeci;
}CVOR;

void ubaci_prvi(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(int));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
}
void ubaci_poslednji(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	PCVOR pom = *pglava;
	novi->podatak = p;
	
	

		while (pom->sledeci != NULL) {
			pom = pom->sledeci;

		}

		if (pom->sledeci == NULL)
			pom->sledeci = novi;

		novi->sledeci = NULL;
	}

void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
	
}
void izbaci_iz_liste(PCVOR* pglava) {
	int p;
	PCVOR pom = *pglava;
	*pglava = (*pglava)->sledeci;
	p = pom->podatak;
	free(pom);
	
}

void main() {
	PCVOR glava=NULL;
	ubaci_prvi(&glava, 15);
	//izbaci_iz_liste(&glava);
	ubaci_prvi(&glava, 18);
	ubaci_prvi(&glava, 1999);
	ubaci_prvi(&glava, 2003);
	ubaci_poslednji(&glava, 156);
	ubaci_poslednji(&glava, 156);
	//izbaci_iz_liste(&glava);
	ispisi_listu(glava);
	printf("Brbrbbrb");
}