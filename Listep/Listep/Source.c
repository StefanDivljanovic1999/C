#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct cvor
{
	int podatak;
	struct cvor* sledeci;

}CVOR;
typedef struct cvor* PCVOR;
typedef struct student {
	char broj_indeksa[10];
	char ime[20];
	char prezime[20];
	int ESPB;
	
}STUDENT;
typedef struct predmet {
	char sifra[10];
	char naziv[100];
	int broj_ESPB;
}PREDMET;
typedef struct prijava {
	char broj_indeksa[20];
	char sifra_predmeta[100];
	int ocena;
	char rok[20];
}PRIJAVA;

void ubaci_na_pocetak(int p, PCVOR* pglava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->podatak = p;
	novi->sledeci = *pglava;
	*pglava = novi;
}

void ispisi_listu(PCVOR glava) {
	CVOR* pom = glava;
	printf("Elementi liste su: \n");
	while (pom != NULL) {
		printf("%d\t", pom->podatak);
		pom = pom->sledeci;
	}
}

void ubaci_na_kraj(PCVOR* pglava, int p) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));

	if (*pglava == NULL) {
		novi->podatak = p;
		novi->sledeci = *pglava;
		*pglava = novi;
	}

	PCVOR pom = *pglava;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
	novi->podatak = p;
	novi->sledeci = NULL;
}

void izbaci_prvi(PCVOR* pglava) {
	PCVOR pom = *pglava;
	if (*pglava == NULL) {
		printf("Prazna lista!!!");
		return;
	}
	*pglava = (*pglava)->sledeci;
	free(pom);
}

void izbaci_poslednji(PCVOR* pglava) {
	PCVOR pom = *pglava;
	if (pom->sledeci == NULL) {
		izbaci_prvi(pglava);
		return;
	}
	while (pom->sledeci->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = NULL;
}

void sortiraj_listu(PCVOR glava) {
	PCVOR pom = glava;
	PCVOR pom1 = glava->sledeci;
	while (pom->sledeci != NULL) {
		while (pom1 != NULL) {
			if (pom->podatak > pom1->podatak) {
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

int broj_elemenata(PCVOR glava) {
	int br = 0;
	PCVOR pom = glava;
	while (pom != NULL) {
		br++;
		pom = pom->sledeci;
	}
	return br;
}

int max_element(PCVOR glava) {
	PCVOR pom = glava;
	int max = -32895829;
	while (pom != NULL) {
		if (pom->podatak > max) {
			max = pom->podatak;
		}
		pom = pom->sledeci;
	}
	return max;
}

int min_element(PCVOR glava) {
	PCVOR pom = glava;
	int min = 32895829;
	while (pom != NULL) {
		if (pom->podatak < min) {
			min = pom->podatak;
		}
		pom = pom->sledeci;
	}
	return min;
}

void ubaci_pre_prvog_veceg(PCVOR* pglava, int el) {
	PCVOR pom = *pglava;
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*pglava == NULL || min_element(*pglava)>=el) {
		ubaci_na_pocetak(el, pglava);
		return;
	}

	if (pom->sledeci == NULL && pom->podatak<el) {
		ubaci_na_kraj(pglava, el);
		return;
	}

	if (pom->sledeci == NULL && pom->podatak > el) {
		ubaci_na_pocetak(el, pglava);
		return;
	}

	if (el >= max_element(*pglava)) {
		ubaci_na_kraj(pglava, el);
		return;
	}
	
	while (pom->sledeci->podatak < el && pom->sledeci!=NULL) {
		pom = pom->sledeci;
	}

	novi->sledeci = pom->sledeci;
	pom->sledeci = novi;
	novi->podatak = el;
	

}

void napuni_listu(PCVOR* pglava) {
	int br_el;
	int element;
	int i = 1;
	do {
		printf("Unesite zeljeni broj elemenata:\n ");
		scanf("%d", &br_el);
	} while (br_el < 2);
	while (broj_elemenata(*pglava) < br_el) {
		printf("Unesite |%d.| element liste: ",i);
		scanf("%d", &element);
		ubaci_pre_prvog_veceg(pglava, element);
		i++;
	}
}

int zbir_parnih(PCVOR glava) {
	int suma = 0;
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak % 2 == 0) {
			suma += pom->podatak;
		}
		pom = pom->sledeci;
	}
	return suma;
}

int postoji(PCVOR glava, int el) {
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak == el) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}

void lista_iz_niza(int niz[], int n, PCVOR* pglava) {
	for (int i = 0; i < n; i++)
	{
		if (postoji(*pglava, niz[i])==0) {
			ubaci_na_kraj(pglava, niz[i]);
		}
	}
}

void ispisi_studenta(STUDENT s) {
	printf("\n");
	printf("Ime i prezime: %s %s\n", s.ime, s.prezime);
	printf("Broj indeksa: %s\n", s.broj_indeksa);
	printf("Ostvarenih ESPB bodova: %d\n", s.ESPB);
}

void dodaj_studenta(STUDENT s, STUDENT studenti[], int* n) {
	studenti[(*n)++] = s;
}

void ispisi_studente(STUDENT studenti[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d.", i+1);
		ispisi_studenta(studenti[i]);
	}
}

void dodaj_na_kraj_REP(PCVOR* pglava, PCVOR* prep, int el) {
	PCVOR novi =(PCVOR)malloc(sizeof(CVOR));
	novi->podatak = el;
	novi->sledeci = NULL;
	if (*pglava == NULL) {
		*pglava = novi;
		*prep = novi;
	}
	else {
		(*prep)->sledeci = novi;
		*prep = novi;

	}
}

void izbaci_neki_element(PCVOR* pglava, int el) {
	PCVOR pom = *pglava;

	if (*pglava == NULL) {
		printf("Lista je prazna!");
		return;
	}

	if (!postoji(*pglava, el)) {
		printf("Element (%d) nije deo liste!!!", el);
		return;
	}

	if (pom->podatak == el) {
		izbaci_prvi(pglava);
		return;
	}

	while (pom->sledeci->podatak!=el) {
		pom = pom->sledeci;
	}
	pom->sledeci = pom->sledeci->sledeci;
}

void dodaj_predmet(PREDMET predmeti[],int* n ,PREDMET p) {
	predmeti[(*n)++] = p;
}

void podaci_o_predmetu(PREDMET p) {
	
		printf("Sifra: %s\n", p.sifra);
		printf("Naziv: %s\n", p.naziv);
		printf("Broj ESPB: %d\n", p.broj_ESPB);
	
}

void ispisi_predmete(PREDMET predmeti[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", i);
		podaci_o_predmetu(predmeti[i]);
	}
}

int postoji_student(STUDENT studenti[],int n ,STUDENT s) {
	for (int i = 0; i <n; i++)
	{
		if (strcmp(studenti[i].ime, s.ime)==0 &&
			strcmp(studenti[i].prezime, s.prezime) == 0 &&
			strcmp(studenti[i].broj_indeksa, s.broj_indeksa) == 0 &&
			studenti[i].ESPB == s.ESPB) {
			return 1;
		}
	}
	return 0;
}

int postoji_predmet(PREDMET predmeti[],int n ,PREDMET p) {
	for (int i = 0; i < n; i++)
	{
		if (strcmp(predmeti[i].sifra,p.sifra) == 0 &&
			strcmp(predmeti[i].naziv, p.naziv) == 0 &&
			predmeti[i].broj_ESPB==p.broj_ESPB) {
			return 1;
		}
	}
	return 0;
}

void unesi_prijavu(PRIJAVA prijave[],int* n ,PRIJAVA p) {
	prijave[(*n)++] = p;
}

void ispisi_prijavu(PRIJAVA p) {
	
	printf("Broj indeksa: %s\n",p.broj_indeksa);
	printf("Sifra predmeta: %s\n", p.sifra_predmeta);
	printf("Ispitni rok: %s\n", p.rok);
	printf("Ocena: %d\n", p.ocena);
}

void ispisi_prijave(PRIJAVA prijave[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", i+1);
		ispisi_prijavu(prijave[i]);
	}
}


	

void studenti() {
	STUDENT s1 = { "2018/0247","Stefan" ,"Divljanovic",153 };
	STUDENT s2 = { "2022/0186","Uros" ,"Divljanovic",2 };
	STUDENT s3 = { "2018/0241","Marko" ,"Vukosavljevic",210 };
	STUDENT s4 = { "2018/0076","Danica" ,"Zdravkovic",240 };
	STUDENT s5 = { "2019/1234","Djura" ,"Grujic",183 };

	STUDENT studenti[100];
	int n = 0;

	dodaj_studenta(s1, studenti, &n);
	dodaj_studenta(s2, studenti, &n);
	dodaj_studenta(s3, studenti, &n);
	dodaj_studenta(s4, studenti, &n);
	dodaj_studenta(s5, studenti, &n);

	ispisi_studente(studenti, n);

	PREDMET p1 = {"01","Matematika 1", 6};
	PREDMET p2 = { "02","Ekonomija", 6 };
	PREDMET p3 = { "03","Psihologija", 4 };
	PREDMET p4 = { "04","OIKT", 6 };
	PREDMET p5 = { "05","Menadzment", 6 };
	PREDMET p6 = { "06","Matematika 2", 6 };
	PREDMET p7 = { "07","Programiranje 1", 4 };
	PREDMET p8 = { "08","Osnovi organizacije", 6 };
	PREDMET p9 = { "09","UIS", 6 };
	PREDMET p10 = { "10","Proizvodni sistemi", 5 };
	PREDMET p11 = { "11","Engleski 1", 5 };

	PREDMET predmeti[60];
	int k = 0;

	dodaj_predmet(predmeti, &k, p1);
	dodaj_predmet(predmeti, &k, p2);
	dodaj_predmet(predmeti, &k, p3);
	dodaj_predmet(predmeti, &k, p4);
	dodaj_predmet(predmeti, &k, p5);
	dodaj_predmet(predmeti, &k, p6);
	dodaj_predmet(predmeti, &k, p7);
	dodaj_predmet(predmeti, &k, p8);
	dodaj_predmet(predmeti, &k, p9);
	dodaj_predmet(predmeti, &k, p10);
	dodaj_predmet(predmeti, &k, p11);

	ispisi_predmete(predmeti, k);

	printf("\n");

	
	

}

int broj_ponavljanja(PCVOR glava, int el) {
	int br = 0;
	PCVOR pom = glava;
	while (pom != NULL) {
		if (pom->podatak == el) {
			br++;
		}
		pom = pom->sledeci;
	}
	return br;
}

void napravi_novu_BZP(PCVOR glava, PCVOR glava1, PCVOR* glava2) {
	PCVOR pom = glava;
	PCVOR pom1 = glava1;
	while (pom != NULL) {
		if(!postoji(*glava2,pom->podatak))
		ubaci_na_kraj(glava2, pom->podatak);
		pom = pom->sledeci;
	}

	while (pom1 != NULL) {
		if (!postoji(*glava2, pom1->podatak))
			ubaci_na_kraj(glava2, pom1->podatak);
		pom1 = pom1->sledeci;
	}
}

void main() {
	PCVOR glava=NULL;
	
	ubaci_na_kraj(&glava, 15);
	ubaci_na_kraj(&glava, 18);
	ubaci_na_kraj(&glava, 23);
	ubaci_na_kraj(&glava, 46);
	ubaci_na_kraj(&glava, 97);
	ubaci_na_kraj(&glava, 7);
	ubaci_na_kraj(&glava, 18);
	ubaci_na_kraj(&glava, 6);
	
	
	ispisi_listu(glava);
	printf("\n");
	studenti();
}