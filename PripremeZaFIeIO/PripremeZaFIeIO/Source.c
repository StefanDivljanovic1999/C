#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student {
	char ime[50];
	char prezime[50];
	int godina;
	double prosek;
}STUDENT;

typedef struct vozilo {
	char marka[20];
	char model[50];
	int kubikaza;
	int brojKonjskihSnaga;
	char registracija[50];
	
}VOZILO;

void skratiZa1(char s[]) {
	s[strlen(s) - 1] = '\0';
}

STUDENT kreirajNovogStudenta() {
	char tmp[100];
	STUDENT s;
	puts("Unesite ime studenta:");
	fgets(s.ime, 50, stdin);
	skratiZa1(s.ime);
	
	puts("Unesite prezime studenta:");
	fgets(s.prezime, 50, stdin);
	skratiZa1(s.prezime);

	puts("Unesite godinu studenta:");
	fgets(tmp, 4, stdin);
	skratiZa1(tmp);
	sscanf(tmp, "%d", &s.godina);
	

    puts("Unesite prosek studenta:");
	fgets(tmp, 8, stdin);
	skratiZa1(tmp);
	sscanf(tmp, "%lf", &s.prosek);

	
	return s;

	//puts(atof(s.prosek));
}
void prikaziStudenta(STUDENT s) {
	char tmp[2000];
	sprintf(tmp, "Informacije o studentu:\n Ime i prezime:%s %s\n Godina studija:%d\nProsek:%.2lf", s.ime, s.prezime, s.godina, s.prosek);
	puts(tmp);
}

VOZILO kreirajNovoVozilo() {
	VOZILO v;
	char tmp[200];
    
	puts("Unesite marku:");
	fgets(v.marka, 20, stdin);
	skratiZa1(v.marka);

	puts("Unesite model:");
	fgets(v.model, 50, stdin);
	skratiZa1(v.model);

	puts("Unesite broj kubika: ");
	fgets(tmp, 50, stdin);
	skratiZa1(tmp);
	sscanf(tmp, "%d", &v.kubikaza);

	puts("Unesite snagu motora u KS: ");
	fgets(tmp, 50, stdin);
	skratiZa1(tmp);
	sscanf(tmp, "%d", &v.brojKonjskihSnaga);

	puts("Unesite registraciju:");
	fgets(v.registracija, 20, stdin);
	skratiZa1(v.registracija);

	return v;

}
void ispisiPodatkeOVozilu(VOZILO v) {
	char tmp[200];
	sprintf(tmp, "Podaci o vozilu:\n Marka:%s\nModel:%s\nKubikaza:%d\nSnaga motora:%d KS\n Registracija:%s", v.marka, v.model, v.kubikaza, v.brojKonjskihSnaga, v.registracija);
	puts(tmp);
}

void zadatak1() {
	FILE* fajl = fopen("studenti.txt", "r");
	char s[100];
	if (fajl == NULL) {
		puts("Fajl nije pronadjen!!!");
		return;
	}
	fgets(s, 100, fajl);
	skratiZa1(s);
	puts(s);

	fgets(s, 100, fajl);
	skratiZa1(s);
	puts(s);
	
	fgets(s, 100, fajl);
	skratiZa1(s);
	puts(s);
	
	fgets(s, 100, fajl);
	skratiZa1(s);
	puts(s);

	fclose(fajl);
	
}

void main() {
	/*printf("Unesite neki tekst:");
	char s[100];
	//scanf("%s", &s);
	fgets( s, 100, stdin);
	skratiZa1(s);
	sprintf(s, "%s ajjaj.", s);
    puts(s);
	puts(".");*/

	STUDENT st=kreirajNovogStudenta();
	
	prikaziStudenta(st);
	//zadatak1();
	//puts("Ides za Beograd");
}