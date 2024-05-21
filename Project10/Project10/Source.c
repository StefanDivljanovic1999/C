#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct student{
	char ime[50];
	char prezime[50];
	int godina;
	double prosek;
}STUDENT;

void skrati_za_1(char s[]) {
	s[strlen(s) - 1] = '\0';
}

STUDENT kreiraj_novog_studenta() {
	STUDENT s;
	puts("Unesite ime studenta:");
	fgets(s.ime, 50, stdin);
	skrati_za_1(s.ime);
	puts("Unesite prezime studenta:");
	fgets(s.prezime, 50, stdin);
	skrati_za_1(s.prezime);
	puts("Unesite godinu na kojoj je student: ");
	scanf("%d", &s.godina);
	puts("Unesite prosek:");
	scanf("%lf", &s.prosek);
	return s;
}

void ispisi_studenta(STUDENT s) {
	printf("Ime i prezime: %s %s\n", s.ime, s.prezime);
	printf("Godina studija: %d\n", s.godina);
	printf("Prosek: %.2lf\n",s.prosek);
	
}

void test() {
	/*char s[100];
	char str[100];

	puts("Unesi neki tekst: ");
	fgets(s, 100, stdin);
	skrati_za_1(s);
	sprintf(s, "%s.", s);
	puts(s);

	fgets(str, 100, stdin); */

	STUDENT s1 = kreiraj_novog_studenta();
	ispisi_studenta(s1);
}

void zadatak_sa_FILE_IO() {
	FILE* fajl = fopen("studenti.txt", "r");
	FILE* izlaz = fopen("izlaz.txt", "w");
	//	char s[100];
	STUDENT st;

	int brojaci[10] = { 0,0,0,0 };
	double sume[10] = { 0,0,0,0 };
	if (fajl == NULL) {
		puts("Fajl nije pronadjen!");
		return;
	}
	while (1) {
		if (fgets(st.ime, 100, fajl) == NULL) {
			//ovo cita jedan red fajla
			break;
		}		skrati_za_1(st.ime);

		fgets(st.prezime, 100, fajl);
		skrati_za_1(st.prezime);

		fscanf(fajl, "%d\n", &st.godina);

		fscanf(fajl, "%lf\n", &st.prosek);

		ispisi_studenta(st);
		for (int i = 1; i <= 4; i++)
		{
			if (st.godina == i) {
				brojaci[i]++;
				sume[i] += st.prosek;
			}
		}
	}
	fprintf(izlaz, "Godina\tBroj\tProsek\n");
	for (int i = 1; i <= 4; i++) {
		if (brojaci[i] != 0) {
			fprintf(izlaz, "%d.\t%d\t%.2lf\n", i, brojaci[i], (double)(sume[i] / brojaci[i]));
		}
		else {
			fprintf(izlaz, "%d.\t%d\tN/A\n", i, brojaci[i]);
		}
	}

	fclose(fajl);

	fclose(izlaz);
}

void domacI() {
	FILE* fajl = fopen("obradjenTekst.txt", "w");
	char s[1000];
	char tekst[1000];
	puts("Unesite cele brojeve odvojene znakom ; u jednom redu");
	fgets(s, 1000, stdin);
	puts("Unesite neki tekst: ");
	fgets(tekst, 1000, stdin);
	skrati_za_1(tekst);
	fprintf(fajl, "%s\n", s);
	
	char* token = strtok(s, ";");
	int brojevi[1000];
	int n = 0;

	while (token != NULL) {
		brojevi[n++] = atoi(token);
		token = strtok(NULL, ";");

	}
	char* reci = strtok(tekst, " ,?.");
	while (reci != NULL) {
		for (int i = 0; i < n; i++) {
			if (brojevi[i] == strlen(reci)) {
				fprintf(fajl, "%s(%d)\n", reci,strlen(reci));
			}
		}
		reci = strtok(NULL, " ,?.");
	}
}

void main() {
	domacI();
	
	

	


	
}