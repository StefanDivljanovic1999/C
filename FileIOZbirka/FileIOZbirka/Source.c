#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cvor {
	int podatak;
	struct cvor* sledeci;
}CVOR;
typedef struct cvor* PCVOR;

void dodaj_na_pocetak(int el, PCVOR* pglava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = el;
	novi->sledeci = *pglava;
	*pglava = novi;
	
}
void ispisi_listu(PCVOR glava, FILE* fajl) {
	PCVOR pom = glava;
	char pi[sizeof(glava)];
	fprintf(fajl,"\nElementi liste su:\n");
	while (pom != NULL) {
		sprintf(pi, "%d\t", pom->podatak);
		fprintf(fajl, pi);
		pom = pom->sledeci;
	}
}
void skrati_za_jedan(char s[]) {
	s[strlen(s) - 1] = '\0';
}
void citanje() {
	char s[1000];
	FILE* fajl = fopen("podaci.txt", "r");
	if (fajl == NULL) {
		printf("Zadati fajl nije pronadjen!!!");
		return;
	}
	while (fgets(s, 1000, fajl) != NULL) {

		printf(s);

	}
	fclose(fajl);
}
void dva_broja() {
	FILE* fajl = fopen("brojevi.txt", "r");
	if (fajl == NULL) {
		printf("Zadati fajl nije pronadjen!!!");
		return;
	}
	int broj1, broj2;
	while (fscanf(fajl, "%d %d", &broj1, &broj2) == 2) {
		printf("%d %d\n", broj1, broj2);
	}
	fclose(fajl);
}
void indeksi() {
	FILE* fajl = fopen("indeksi.txt", "r");
	int godina, broj;
	if (fajl == NULL) {
		printf("Zadati fajl nije pronadjen!!!");
		return;
	}
	while (fscanf(fajl, "%d/%d\n", &godina, &broj) == 2) {
		printf("1.Godina upisa: %d \n2.Redni broj:%d\n\n", godina, broj);
	}
	fclose(fajl);
}
void izmeni_listu(PCVOR* pglava) {
	PCVOR pom = *pglava;
	while (pom != NULL) {
		if (pom->podatak % 2 == 0) {
			pom->podatak = 0;
		}
		pom = pom->sledeci;
	}
}
void zad_list() {
	FILE* fajl = fopen("lista.txt", "w");
	PCVOR glava = NULL;
	dodaj_na_pocetak(97, &glava);
	dodaj_na_pocetak(7, &glava);
	dodaj_na_pocetak(46, &glava);
	dodaj_na_pocetak(23, &glava);
	dodaj_na_pocetak(18, &glava);
	dodaj_na_pocetak(15, &glava);


	ispisi_listu(glava, fajl);
	izmeni_listu(&glava);
	ispisi_listu(glava, fajl);
	fclose(fajl);
}
void prebacivanje_teksta_bez_taraba() {
	FILE* ulaz = fopen("fajl1.txt", "r");
	FILE* izlaz = fopen("fajl2.txt", "w");
	char s[100];
	while (fgets(s, 100, ulaz)!=NULL) {
		for (int i = 0; s[i]!='\0' ; i++)
		{
			if (s[i] == ' ') {
				s[i] = '#';
			}
		}
		fputs(s, izlaz);
	}
	
	fclose(ulaz);
	fclose(izlaz);
}
void fajl_suma() {
	
	FILE* ulaz = fopen("dat1.txt", "r");
	FILE* izlaz = fopen("dat2.txt", "w");
	char s[1000];
	int suma = 0;
	while (fgets(s, 1000, ulaz) != NULL) {
		for (int i = 0; s[i]!='\0'; i++)
		{
			if (s[i] >= 48 && s[i] <= 57) {
				fprintf(izlaz, "|%c| ",s[i]);
			}
		}
	}
	fprintf(izlaz, "\nSuma elemenata iznosi:%d\n", suma);
	fclose(ulaz);
	fclose(izlaz);
}
void bez_razmaka() {
	FILE* ulaz = fopen("ulaz.txt", "r");
	FILE* izlaz = fopen("izlaz.txt", "w");
	if (ulaz == NULL) {
		printf("Fajl nije pronadjen!!!");
		return;
	}
	char znak;
	
	while ((znak=fgetc(ulaz)) != EOF) {
		if(znak!=' ')
		fprintf(izlaz,"%c", znak);
	}

	

	fclose(ulaz);
	fclose(izlaz);
}
void sortiraj_listu(PCVOR pglava) {
	PCVOR pom = pglava;
	PCVOR pom1 = (pglava)->sledeci;

	while (pom->sledeci != NULL) {
		while (pom1 != NULL) {
			if (pom1->podatak < pom->podatak) {
				int c = pom->podatak;
				pom->podatak = pom1->podatak;
				pom1->podatak = c;
			}
			pom1 = pom1->sledeci;
		}
		pom = pom->sledeci;
		pom1 = pom->sledeci;
	}
}
void fajl_sort(PCVOR glava) {
	
	FILE* izlaz = fopen("izlaz.txt", "w");

	ispisi_listu(glava,izlaz);
	sortiraj_listu(glava);
	ispisi_listu(glava, izlaz);


	
	fclose(izlaz);

}
int sve_slova(char s[]) {
	for (int i = 0; s[i]!='\0' ; i++)
	{
		if (!(s[i]>=65 && s[i]<=90) && !(s[i]>=97 && s[i]<=122)) {
			return 0;
		}

	}
	return 1;
}
int broj_reci(char s[]) {
	char* token;
	int brojac = 0;
	token = strtok(s, " .?!,");
	while (token != NULL) {
		if (sve_slova(token)==1 && strlen(token) > 1) {
			brojac++;
		}
		token=strtok(NULL, " .?!,");
	}
	return brojac;
}


void main() {


}