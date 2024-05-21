#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct student
{
	char ime[50];
	char prezime[50];
	int godina;
	double prosek;
}STUDENT;
typedef struct automobil
{
	char marka[50];
	char model[50];
	int kubikaza;
	int godiste;
}AUTOMOBIL;
void skrati_za_jedan(char s[]) {

	s[strlen(s) - 1] = '\0';

}
void priprema() {
	int kraj;
	char s[1000];
	char str[100];
	puts("UNesite neki tekst:");
	fgets(s, 1000, stdin);
	skrati_za_jedan(s);
	sprintf(s, "%s.", s);
	puts(s);

	fgets(str, 100, stdin);
	sscanf(str, "%d", &kraj);
	kraj++;

	sprintf(str, "Broj uvecan za jedan je:%d", kraj);
	puts(str);
}
STUDENT kreiraj_studenta() {
	char tmp[250];
	STUDENT s;

	puts("Ime?");
	fgets(s.ime, 50, stdin);
	skrati_za_jedan(s.ime);

	puts("Prezime?");
	fgets(s.prezime, 50, stdin);
	skrati_za_jedan(s.prezime);

	puts("Godina? ");
	fgets(tmp, 4, stdin);
	skrati_za_jedan(tmp);
	sscanf(tmp, "%d", &s.godina);

	puts("Prosek? ");
	fgets(tmp, 10, stdin);
	skrati_za_jedan(tmp);
	sscanf(tmp, "%lf", &s.prosek);

	return s;
}
AUTOMOBIL kreiraj_automobil() {
	AUTOMOBIL a;
	char tmp[100];
	puts("Unesite marku automobila:");
	fgets(a.marka, 50, stdin);
	skrati_za_jedan(a.marka);

	puts("Unesite model automobila:");
	fgets(a.model, 50, stdin);
	skrati_za_jedan(a.model);

	puts("Unesite godiste automobila:");
	fgets(tmp, 2022, stdin);
	skrati_za_jedan(tmp);
	sscanf(tmp, "%d", &a.godiste);

	puts("Unesite kubikazu automobila:");
	fgets(tmp, 12000, stdin);
	skrati_za_jedan(tmp);
	sscanf(tmp, "%d", &a.kubikaza);

	return a;
}
void ispisi_studenta(STUDENT s) {
	char tmp[200];
	sprintf(tmp, "Ime i prezime: %s %s\n Godina studiranja: %d\n Prosek: %.2lf \n", s.ime, s.prezime, s.godina, s.prosek);
	puts(tmp);
}
void ispisi_auto(AUTOMOBIL a) {
	char tmp[250];
	sprintf(tmp, "Marka i model: %s %s\nKubikaza: %d\nGodina proizvodnje:%d\n", a.marka, a.model, a.kubikaza, a.godiste);
	puts(tmp);
}
void unesi_u_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}
void zadatak1() {
	STUDENT st;
	FILE* fajl = fopen("studenti.txt", "r");
	FILE* izlaz = fopen("izvestaj.txt", "w");
	if (fajl == NULL || izlaz==NULL) {
		printf("Ne postoji fajl");
		return;
	}
	char s[1000];
	int brojaci[] = { 0,0,0,0 };
	double sume[] = { 0,0,0,0 };

	while (1) {
		if (fgets(st.ime, 1000, fajl) == NULL){
		break;
}
		skrati_za_jedan(st.ime);

		fgets(st.prezime, 1000, fajl);
		skrati_za_jedan(st.prezime);

		fscanf(fajl, "%d\n", &st.godina);
		fscanf(fajl, "%lf\n", &st.prosek);
		skrati_za_jedan(s);

		ispisi_studenta(st);
		brojaci[st.godina-1]++;
		sume[st.godina - 1] += st.prosek;
	}
	fclose(fajl);
	fprintf(izlaz, "godina\tbroj\t\prosek\n");
	for (int i = 1; i <= 4; i++)
	{
		fprintf(izlaz, "%d\t%d\t%lf\n", i, brojaci[i], sume[i]);
	}
}
void zadatak2() {
	AUTOMOBIL a;
	char s[1000];
	int n = 0;
	int br = 0;
	int kubikaze[1000];
	FILE* fajl = fopen("automobili.txt", "r");
	FILE* izlaz = fopen("najveca.txt", "w");
	int najmanji = 2000;
//	int kubikaze[4];
	if (fajl == NULL) {
		printf("Dati fajl ne postoji!");
		return;
	}
	else {
		while (1) {
			if (fgets(a.marka, 1000, fajl) == NULL) {
				break;
			}
			skrati_za_jedan(a.marka);

			fgets(a.model, 1000, fajl);
			skrati_za_jedan(a.model);

			fscanf(fajl, "%d", &a.kubikaza);
			fscanf(fajl, "%d", &a.godiste);
			skrati_za_jedan(s);
			ispisi_auto(a);

			unesi_u_niz(kubikaze, &n, a.kubikaza);
			br++;
		}
	}
	int najmanja = 1000;
	for (int i = 0; i < br; i++)
	{
		if (najmanja > kubikaze[i]) {
			najmanja = kubikaze[i];
			sprintf(izlaz, "Najmanja kubikaza iznosi:%d\n", najmanja);
		}
	}
	
	fclose(fajl);
	fclose(izlaz);
}

void main() {
	zadatak2();
	
	
}