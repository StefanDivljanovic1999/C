#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct proizvod
{
	int sifra;
	char naziv[50];
	double cena;
}PROIZVOD;




void ispisi_proizvod(PROIZVOD p) {
	printf("%d\t%s\t%.2lf", p.sifra, p.naziv, p.cena);
}
PROIZVOD unesi_proizvod() {
	PROIZVOD p;
	printf("Unesite sifru proizvoda: ");
	scanf("%d", &p.sifra);
	printf("Unesite naziv proizvoda: ");
	getchar();
	gets(p.naziv);
	printf("Unesite cenu proizvoda: ");
	scanf("%lf", &p.cena);
	return p;
}
void ispisi_niz(PROIZVOD proizvodi[], int broj_pr) {
	printf("U prodavnici se nalaze:\n");
	for (int i = 0; i < broj_pr; i++)
	{
		ispisi_proizvod(proizvodi[i]);
		printf("\n");
	}
}
int postoji_li_u_nizu(PROIZVOD proizvodi[], int br_pr,int sifra) {
	for (int i = 0; i < br_pr; i++)
	{
		if (proizvodi[i].sifra == sifra) {
			return 1;
		}
	}
	return 0;
}
void unesi_u_niz(PROIZVOD proizvodi[], int* br_pr, PROIZVOD proizvod) {
	if (postoji_li_u_nizu(proizvodi, *br_pr, proizvod.sifra) == 0) {
		proizvodi[(*br_pr)++] = proizvod;
	}
	else {
		printf("U radnji se vec nalazi proizvod sa datom sifrom!!!");
	}
	
	
	
}
void sortiraj_po_nazivu(PROIZVOD proizvodi[], int* br) {
	for (int i = 0; i < *br-1; i++)
	{
		for (int j = i+1; j < *br; j++)
		{
			if (strcmp(proizvodi[i].naziv,proizvodi[j].naziv)>0) {
				PROIZVOD p = proizvodi[i];
				proizvodi[i] = proizvodi[j];
				proizvodi[j] = p;
			}
		}
	}
}
int vrati_indeks(PROIZVOD proizvodi[], int br, char ime[]) {
	for (int i = 0; i < br; i++)
	{
		if (strcmp(proizvodi[i].naziv, ime) == 0) {
			return i;
		}
	}
	return -1;
}
void izbrisi_proizvod(PROIZVOD proizvodi[], int* br, char naziv[]) {
	int i;
	int n = vrati_indeks(proizvodi, br, naziv);
	
	for ( i = *br; i>=n; i--)
	{
		if (i == n ) {
			proizvodi[i].naziv== NULL;
			proizvodi[i].sifra = NULL;
			proizvodi[i].cena = -1;
		}
		else {
			proizvodi[i] = proizvodi[i - 1];
		}
	}
	*br = *br - 1;
}

void main() {
	PROIZVOD p = { 1265,"Koka kola",139.99 };
	PROIZVOD p1 = { 1598,"Benzin 95 oktana",171.99 };
	PROIZVOD p2 = { 2934,"G drive dizel",179.99 };
	
	PROIZVOD proizvodi[100];
	int br = 0;
	unesi_u_niz(proizvodi, &br, p);
	unesi_u_niz(proizvodi, &br, p1);
	unesi_u_niz(proizvodi, &br, p2);
	
	
	sortiraj_po_nazivu(proizvodi, &br);
	/*izbrisi_proizvod(proizvodi, &br, p.naziv);
	izbrisi_proizvod(proizvodi, &br, p3.naziv);*/
	ispisi_niz(proizvodi, br);
	printf("\n");


	char ime[] = "Benzin 95 oktana";
}