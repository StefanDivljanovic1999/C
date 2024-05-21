#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char ime[50];
	char prezime[50];
	int godina;
	double prosek;
}STUDENT;
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
}
	STUDENT vratiItogStudenta(int i) {
		STUDENT s;
		FILE* fajl = fopen("svi_studenti.bin", "rb");
		fseek(fajl, i * sizeof(STUDENT), SEEK_SET);
		fread(&s, sizeof(STUDENT), 1, fajl);

		fclose(fajl);
		return s;
	}

	void dodajStudenta(STUDENT s) {
		FILE* fajl = fopen("svi_studenti.bin", "ab");
		fwrite(&s, sizeof(STUDENT), 1, fajl);


		fclose(fajl);
	}

	void sortirajFajl() {
		int i, j;
		STUDENT si, sj, tmp;
		int n;
		FILE* fajl = fopen("svi_studenti.bin", "a+b");
		fseek(fajl, 0, SEEK_END);
		n = ftell(fajl) / sizeof(STUDENT);
		//sa n se dobija broj studenata u fajlu, ako je fajl 400kb, a student je 80kb imamo 5 studenata
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n; j++)
			{
				fseek(fajl, i * sizeof(STUDENT), fajl);
				fread(&si, sizeof(STUDENT), 1, fajl);

				fseek(fajl, j * sizeof(STUDENT), fajl);
				fread(&sj, sizeof(STUDENT), 1, fajl);

				if (sj.prosek > si.prosek) {
					fseek(fajl, i * sizeof(STUDENT), fajl);
					fwrite(&sj, sizeof(STUDENT), 1, fajl);

					fseek(fajl, j * sizeof(STUDENT), fajl);
					fwrite(&si, sizeof(STUDENT), 1, fajl);
				}
			}

		}


		fclose(fajl);
	}

void prikaziStudenta(STUDENT s) {
	char tmp[2000];
	sprintf(tmp, "Informacije o studentu:\n Ime i prezime:%s %s\n Godina studija:%d\nProsek:%.2lf", s.ime, s.prezime, s.godina, s.prosek);
	puts(tmp);
}
void ucitajIIspisi() {
	FILE* fajl = fopen("svi_studenti.bin", "rb"); 
	STUDENT s;
		while (fread(&s,sizeof(STUDENT),1,fajl)!=0) 
			prikaziStudenta(s);
		
		fclose(fajl);
}

void main() {
	STUDENT s=kreirajNovogStudenta();
	STUDENT s1 = kreirajNovogStudenta();
	STUDENT s2 = kreirajNovogStudenta();

	STUDENT s3 = kreirajNovogStudenta();
	STUDENT s4 = kreirajNovogStudenta();
	sortirajFajl();
	dodajStudenta(s1);
	dodajStudenta(s);
	dodajStudenta(s2);
	dodajStudenta(s3);
	dodajStudenta(s4);

	ucitajIIspisi();
}