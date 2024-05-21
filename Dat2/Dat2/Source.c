#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct student
{
	char ime_prezime[100];
	int godina;
	int broj;
}STUDENT;
void zadatak1() {
	char s[1000];
	FILE* fajl = fopen("podaci.txt", "r");
	if (fajl == NULL) {
		printf("Fajl nije pronadjen!");
		return;
	}
	else {
		while (fgets(s, 1000, fajl) != NULL) {
			printf("%s", s);
		}
	}
}
void zadatak2() {
	FILE* fajl = fopen("brojevi.txt", "r");
	char s[1000];
	int  broj1, broj2;
	if (fajl == NULL) {
		printf("Fajl ne postoji!!!");
		return;
	}
	else {
		while (fscanf(fajl, "%d %d\n", &broj1, &broj2) == 2) {
			printf("%d\t%d\n", broj1, broj2);
		}
	}
	fclose(fajl);
}
void skrati_za_1(char s[]) {
	s[strlen(s) - 1] = '\0';
}
void ispisi_studenta(STUDENT s) {
	char mtp[100];
	sprintf(mtp,"Ime i prezime:%s\nBroj indeksa: %d/%d\n", s.ime_prezime, s.godina, s.broj);
	puts(mtp);
}
void zadatak3() {
	FILE* fajl = fopen("studenti.txt", "r");
	char s[1000];
	int broj, godina;
	if (fajl == NULL) {
		printf("NE");
		return;
	}
	else {
		while (fgets(s, 1000, fajl) != NULL) {
			fscanf(fajl, "%d/%d", &godina, &broj);
			printf("Ime i prezime:\n %s \n Broj indeksa:\n%d\%d", s, godina, broj);
		}
	}
}
int postoji(int niz[], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
	}
	return 0;
}
void obradi_string() {
	FILE* fajl = fopen("obradjenString.txt", "w");
	char duzine[1000];
	int niz[100];
	char tekst[1000];
	int n = 0;
	char* token;
	puts("Unesite niz celih brojeva odvojenih znakom ; ");
	fgets(duzine, 1000, stdin);
	token = strtok(duzine, ";\n");
	while (token != NULL) {
		sscanf(token, "%d", &niz[n]);
		n++;
		token = strtok(NULL, "\n;");
	}
	puts("Unesi neki tekst:");
	fgets(tekst, 1000, stdin);
	token = strtok(tekst, " \n");
	while (token != NULL) {
		if (postoji(niz, n, strlen(token)) == 1) {
			fprintf(fajl, "%s(%d)\n", token, strlen(token));
			token = strtok(NULL, " \n");
		}
	}

	fclose(fajl);
}
void obradi() {
	FILE* fajl = fopen("obradjen.txt", "w");
	int niz[100];
	int n = 0;
	char duzine[100];
	char tekst[100];

	puts("Unesite brojeve odvojene znakom ;");
	fgets(duzine, 1000, stdin);
    char* token;
	token = strtok(duzine, ";\n");
	while (token != NULL) {
		sscanf(token, "%d", &niz[n++]);
		token = strtok(NULL, ";\n");
	}
	puts("Unesi neki tekst:");
	fgets(tekst, 1000, stdin);
	token = strtok(tekst, " \n");
	while (token != NULL) {
		if (postoji(niz, n, strlen(token))) {
			fprintf(fajl, "%s(%d)\n", token, strlen(token));
			token = strtok(NULL, " \n");
		}
	}
	fclose(fajl);
}
void unesi_brojeve_u_fajl() {
	int niz[100];
	int duzine[100];
	int najmanji = 2000;
	int najveci = 0;
	int n = 0;
	int broj;
//	while (broj >= 0) {
		puts("Unesi broj:");
		fgets(duzine, 100, stdin);
		char* token = strtok(duzine, ";\n");
		while (token != NULL) {
			sscanf(token, "%d", &niz[n++]);
			token = strtok(NULL, ";\n");
		}
    
	for (int i = 0; i < n; i++)
	{
		if (najveci < niz[i]) {
			najveci = niz[i];
		}
		if (niz[i] < najmanji) {
			najmanji = niz[i];
		}
		
    }
	FILE* fajl = fopen("minMax.txt", "w");
	fprintf(fajl, "Najmanji broj u nizu je: %d, dok je najveci broj u nizu jednak: %d", najmanji, najveci);
	fclose(fajl);
}

void zadatak_moj() {
	STUDENT s;
	FILE* fajl = fopen("studenti.txt", "r");
	char s1[1000];
	int godine[10];
	int najveca = 0;
	int n = 0;
	while (fgets(s.ime_prezime, 1000, fajl) != NULL) {
		//skrati_za_1(s1);
		fgets(s1, 1000, fajl);
		char* token = strtok(s1, "/\n");
		sscanf(token, "%d", &s.godina);

		token = strtok(NULL, "/\n");
		sscanf(token, "%d", &s.broj);

		ispisi_studenta(s);
		godine[(n)++] = s.godina;
		
    }
	for (int i = 0; i < n; i++)
	{
		if (najveca<godine[i]) {
			najveca = godine[i];
		}
		
	}
	
	FILE* izlaz = fopen("izlaz.txt", "w");
	fprintf(izlaz, " Najveca godina je: %d", najveca);
}

void main() {
	zadatak_moj();
}