#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct cvor* PCVOR;

typedef struct cvor {
	int podatak;
	struct cvor* sledeci;
}CVOR;

void ubaciNaPrvoMesto(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
}

void ispisiListu(PCVOR glava) {
     PCVOR pom = glava;
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}

int dodajNaPrvoPokazivac(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
	return novi;
}
void dodajNaPoslednjeMesto(PCVOR* pglava, int p) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = NULL;
	while (pom->sledeci !=NULL) {
		pom = pom->sledeci;
		}
	pom->sledeci = novi;
}
void sortirajListu(PCVOR *pglava) {
	
}

void main() {
	//printf("Ides za kanadu");
	PCVOR glava = NULL;
	ubaciNaPrvoMesto(&glava,1999);
	ubaciNaPrvoMesto(&glava, 2003);
	ubaciNaPrvoMesto(&glava, 1954);
	dodajNaPrvoPokazivac(&glava, 1957);
	ubaciNaPrvoMesto(&glava, 1959);
	//dodajNaPoslednjeMesto(&glava, 1987);
	ispisiListu(glava);
	dodajNaPoslednjeMesto(&glava, 1987);
	printf("\nElementi liste\n");
	ispisiListu(glava);
}