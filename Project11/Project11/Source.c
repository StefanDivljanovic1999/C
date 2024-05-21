#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct student {
	char ime_prezime[100];
	char broj_indeksa[100];
	double prosek;
	int godina;
}STUDENT;

typedef struct cvor {
	STUDENT s;
	struct cvor* sledeci;
}CVOR;
typedef struct cvor* PCVOR;

void dodaj_studenta(PCVOR* lista, STUDENT s) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->s = s;
	novi->sledeci = *lista;
	*lista = novi;
}
void ispisi_studenta(STUDENT s) {
	printf("<Ime i prezime: %s><Broj indeksa: %s><Prosek: %.2lf><Godina:%d>\n", s.ime_prezime, s.broj_indeksa, s.prosek, s.godina);
}
void ispisi_listu(PCVOR lista) {
	PCVOR pom = lista;
	while (pom != NULL) {
		ispisi_studenta(pom->s);
		pom = pom->sledeci;
	}
}


int br_elemenata(PCVOR lista) {
	PCVOR pom = lista;
	int br = 0;
	while (pom != NULL) {
		br++;
		pom = pom->sledeci;
	}
	return br;
}
void sortiraj_listu(PCVOR lista) {
	PCVOR pom = lista;
	PCVOR pom1 = lista->sledeci;
	STUDENT tmp;
	int n = br_elemenata(lista);
	printf("%d", n);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (pom->s.prosek < pom1->s.prosek) {
				tmp = pom->s;
				pom->s = pom1->s;
				pom1->s = tmp;
			}
			pom1 = pom1->sledeci;
			
		}
		pom = pom->sledeci;
		pom1 = pom->sledeci;
	}
	
}
void upisi_u_fajl(char* naziv, PCVOR* glava) {
	FILE* fajl = fopen(naziv, "w");
	PCVOR pom = *glava;
	while (pom != NULL) {
		fprintf(fajl, "%s\n%s\n%lf\n%d\n", pom->s.ime_prezime,pom->s.broj_indeksa,pom->s.prosek,pom->s.godina);
		pom = pom->sledeci;
	}
}
void ucitaj_listu(PCVOR* lista)                {
	STUDENT s1;
	FILE* fajl = fopen("studenti.txt", "r+");
	char s[1000];
	while (1) {
		strcpy(s1.ime_prezime, fgets(s, 1000, fajl));
		strcpy(s1.broj_indeksa, fgets(s, 1000, fajl));
		fscanf(fajl, "%lf", &s1.prosek);
		fscanf(fajl, "%d", &s1.godina);
		dodaj_studenta(lista, s1);

		if (fgets(s, 1000, fajl) == NULL || fscanf(fajl, "%lf", &s1.prosek) || fscanf(fajl, "%d", &s1.godina)) {
			break;
		}
	}
	sortiraj_listu(*lista);
	upisi_u_fajl("studenti.txt", lista); 
	fclose(fajl);
}
void meni() {
	int br;
	scanf("%d", &br);
	switch (br)
	{
	case(1):{
		
		break;
	}
	case(2): {
		printf("Burek sa sirom!");
		break;
	}
	case(3): {
		printf("Burek sa sirom!");
		break;
	}
	case(4): {
		printf("Burek sa sirom!");
		break;
	}case(0): {
		
		break;
	}
	default:
		break;
	}

}

void main() {
	
	PCVOR lista = NULL;
	ucitaj_listu(&lista);
	sortiraj_listu(lista);
	ispisi_listu(lista);
	char naziv[] = "sortirani.txt";
	upisi_u_fajl(naziv, &lista);
	meni();
}