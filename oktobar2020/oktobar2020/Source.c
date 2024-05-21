#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cvor CVOR;
typedef struct cvor * PCVOR;
struct cvor {
	char naziv[50];
	double cena;
	int tip; //0 – CPU, 1 – RAM, 2 – GPU, 3 -SSD
	PCVOR sledeci;
};
typedef struct komponenta {
	char naziv[50];
	double cena;
	int tip;
}KOMPONENTA;

void dodaj(char naziv[], double cena, int tip, PCVOR * glava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	strcpy(novi->naziv, naziv);
	novi->cena = cena;
	novi->tip = tip;
	novi->sledeci = *glava;
	*glava = novi;
	}
void ispisi(PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		printf("Naziv: %s", pom->naziv);
		printf("Cena: %.2lf\n", pom->cena);
		printf("Tip: %d\n", pom->tip);

		pom = pom->sledeci;
	}
}
int da_li_postoji(char naziv[], PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		if (strcmp(pom->naziv, naziv) == 0) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}
void skrati_za_jedan(char s[]) {
	s[strlen(s) - 1] = '\0';
}
void unesi_komponentu(PCVOR * glava) {
	char naziv[100];
	PCVOR pom = *glava;
	double cena;
	int tip;

	do {
		printf("Unesite naziv: ");
		fgets(naziv, 100, stdin);
		
	} while (da_li_postoji(naziv, *glava));
	do {
		printf("Unesite cenu: ");
		scanf("%lf", &cena);
		if (cena <= 0) {
			printf("GRESKA!\n");
		}
	} while (cena <= 0);
	do {
		printf("Unesite tip:");
		scanf("%d", &tip);
		if (tip < 0 || tip>3) {
			printf("GRESKA!\n");
		}
	} while (tip < 0 || tip>3);

	dodaj(naziv, cena, tip, glava);
	
	printf("Komponenta je dodata!\n");
	getchar();
}
void dodaj_u_niz(KOMPONENTA komponenta, KOMPONENTA komponente[], int * n) {
	komponente[(*n)++] = komponenta;

}
void napravi_niz(int tip, PCVOR glava, KOMPONENTA komponente[], int * n) {
	PCVOR pom = glava;
	KOMPONENTA k;
	while (pom != NULL) {
		if (pom->tip == tip) {
			k.cena = pom->cena;
			k.tip = pom->tip;
			strcpy(k.naziv, pom->naziv);
			dodaj_u_niz(k, komponente, n);
		}
		pom = pom->sledeci;
	}
}
void ispisi_niz(KOMPONENTA komponente[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d.Naziv: %s\tCena:%.2lf\tTip:%d\n",i+1 ,komponente[i].naziv, komponente[i].cena, komponente[i].tip);
	}
}
KOMPONENTA pronadji_najjeftiniju(KOMPONENTA komponente[], int n) {
	double min = komponente[0].cena;
	KOMPONENTA k = komponente[0];
	for (int i = 0; i < n; i++)
	{
		if (komponente[i].cena < k.cena) {
			k= komponente[i];
		
		}
	}
	return k;
}
int broj_komponenata(PCVOR glava) {
	int br = 0;
	PCVOR pom = glava;
	while (pom != NULL) {
		br++;
		pom = pom->sledeci;
}
	return br;
}
KOMPONENTA najjeftiniji_po_tipu(KOMPONENTA komponente[], int n, int tip) {
	KOMPONENTA min=komponente[0];
	
	return min;
}
void odaberi_komponente(KOMPONENTA odabraneKomponente[], PCVOR glava) {
	PCVOR pom = glava;
	KOMPONENTA k;
	strcpy(k.naziv, pom->naziv);
	k.cena = pom->cena;
	k.tip = pom->tip;

	int i;
	while (pom != NULL) {
		for (i = 0; i < 3; i++)
		{
			
			napravi_niz(i, pom, odabraneKomponente, &i);

		}pom = pom->sledeci;
	}
	ispisi_niz(odabraneKomponente, i);
}
void main() {
	PCVOR glava = NULL;
	KOMPONENTA k[1000];
	int n = 0;
	for (int i = 0; i < 5; i++)
	{
		unesi_komponentu(&glava);
	}
				

	napravi_niz(2, glava, k, &n);
	printf("\n");
	ispisi_niz(k, n);
	/*
	KOMPONENTA k1;
	strcpy(k1.naziv, "komponenta 1");
	k1.cena = 77.98;
	k1.tip = 2;
	
	KOMPONENTA k2;
	strcpy(k2.naziv, "komponenta 2");
	k2.cena = 120.50;
	k2.tip = 1;

	KOMPONENTA k3;
	strcpy(k3.naziv, "komponenta 3");
	k3.cena = 378.87;
	k3.tip = 2;

	KOMPONENTA k4;
	strcpy(k4.naziv, "komponenta 4");
	k4.cena = 100.50;
	k4.tip = 3;

	KOMPONENTA k5;
	strcpy(k5.naziv, "komponenta 5");
	k5.cena = 105.30;
	k5.tip = 3;
	
	KOMPONENTA k[1000];
	int n = 0;
	dodaj_u_niz(k1, k, &n);
	dodaj_u_niz(k2, k, &n);
	dodaj_u_niz(k3, k, &n);
	dodaj_u_niz(k4, k, &n);
	dodaj_u_niz(k5, k, &n);
	
	ispisi_niz(k, n);
	KOMPONENTA odabrane[1000];
	najjeftiniji_po_tipu(k, n, 1);
	//ispisi_niz(odabrane, 5);*/
}