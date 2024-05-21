#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cvor CVOR;
typedef struct cvor * PCVOR;
typedef struct pitanje {
	int redni_broj;
	char tekst_pitanja[50];
	char tacan_odgovor[20];
	int odgovoreno; //inicijalno 0,kada korisnik odgovori tacno onda ima vrednost 1
}PITANJE;
struct cvor {
	PITANJE pitanje;
	PCVOR sledeci;
};
int br_elemenata_liste(PCVOR glava) {
	PCVOR pom = glava;
	int brojac = 0;
	while (pom != NULL) {
		brojac++;
		pom = pom->sledeci;
	}
	return brojac;
}
void dodaj_u_listu(PITANJE pitanje, PCVOR * glava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*glava == NULL) {
		novi->pitanje = pitanje;
		novi->pitanje.redni_broj = 1;
		novi->sledeci = *glava;
		*glava = novi;
		return;
	}
	PCVOR pom = *glava;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
	novi->pitanje = pitanje;
	novi->pitanje.redni_broj = br_elemenata_liste(*glava);
	novi->sledeci = NULL;

}

void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		printf("%s", pom->pitanje.tekst_pitanja);
		pom = pom->sledeci;
	}
}
int ucitaj_pitanja_bin_dat(char * naziv, PCVOR * glava) {
	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL) {
		printf("Greska prilikom citanja !!!");
		return -1;
	}
	PCVOR pom = *glava;
	char s[1000];
	
	
	
	fclose(fajl);
	return 0;
}

void dodaj_pitanja(PCVOR * glava) {
	printf("Unesite pitanje:\n");


}

void main() {
	
	PCVOR glava = NULL;
	ucitaj_pitanja_bin_dat("pitanja.txt", &glava);
}