#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct student {
	char ime_prezime[100];
	int godina;
	double prosek;
	char broj_indeksa[100];
}STUDENT;

void prikazi_studenta(STUDENT s) {
	printf("Ime i prezime: %s, Godina: %d,Prosek: %.2lf, Broj indeksa: %s\n", s.ime_prezime, s.godina, s.prosek, s.broj_indeksa);
}

void dodaj_studenta(STUDENT s) {
	FILE* fajl = fopen("svi_studenti.bin", "wb");
	fwrite(&s, sizeof(STUDENT), 1, fajl);

	fclose(fajl);
}
STUDENT vratiItogStudenta(int i) {
	STUDENT s;
	FILE* fajl = fopen("svi_studenti.bin", "rb");
	fseek(fajl, i*sizeof(STUDENT), SEEK_SET);
	fread(&s, sizeof(STUDENT), 1, fajl);
	
	fclose(fajl);
	return s;
}
void sortiraj_fajl() {
	STUDENT si,sj,tmp;
	FILE* fajl = fopen("svi_studenti.bin", "a+b");
	int n;
	fseek(fajl, 0, SEEK_END);
	n = ftell(fajl)/sizeof(STUDENT);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j <n; j++)
		{
			fseek(fajl, i * sizeof(STUDENT), fajl);
			fread(&si, sizeof(STUDENT), 1, fajl);
			fseek(fajl, j * sizeof(STUDENT), fajl);
			fread(&sj, sizeof(STUDENT), 1, fajl);
			if (si.prosek > sj.prosek) {
				fseek(fajl, i * sizeof(STUDENT), fajl);
				fwrite(&sj, sizeof(STUDENT), 1, fajl);
				fseek(fajl, j * sizeof(STUDENT), fajl);
				fwrite(&si, sizeof(STUDENT), 1, fajl);
			}
		}
	}
	fclose(fajl);
}

void ucitaj_i_ispisi() {
	FILE* fajl = fopen("svi_studenti.bin", "rb");
	STUDENT s;
	while (1) {
		fread(&s, sizeof(STUDENT), 1, fajl);
		prikazi_studenta(s);
		if (fread(&s, sizeof(STUDENT), 1, fajl) == 0) {
			break;
		}
	}

	fclose(fajl);
}

void main() {
	STUDENT s;
	char ime_prezime[] = "Stefan Divljanovic";
	char broj_indeksa[] = "2018/0247";
	strcpy(s.ime_prezime, ime_prezime);
	strcpy(s.broj_indeksa, broj_indeksa);
	s.godina = 4;
	s.prosek = 7.5;
	STUDENT s1 = { "Marko Vukosavljevic",4,8.67,"2018/0247" };

	dodaj_studenta(s);
	dodaj_studenta(s1);

	STUDENT s2=vratiItogStudenta(1);
	printf("%s",s2.ime_prezime);
}