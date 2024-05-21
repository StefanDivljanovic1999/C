#define _CRT_SECURE_NO_WARNINGS
#define MAX_BR_ELEMENATA 50
#include <stdio.h>

int trocifren(int broj) {
	if (broj >= 100 && broj <= 999) {
		return 1;
	}
	return 0;
}

int kontrola_unosa(int x, int y) {
	if (trocifren(x) && trocifren(y) && x < y) {
		return 1;
	}
	return 0;
}

int zbir_cifara(int broj) {
	int zbir = 0;
	while (broj != 0) {
		int cifra = broj % 10;
		broj /= 10;
		zbir += cifra;
	}
	return zbir;
}
void deljiv_sa2(int x, int y) {
	printf("Brojevi deljivi sa 2 iz intervala [%d,%d] su:\n",x,y);
	for (int i = x; i <=y; i++)
	{
		if (zbir_cifara(i) % 2 == 0) {
			printf("%d\t", i);
		}
	}
}
void zadatak1() {
	int x, y;
	do
	{
		printf("Unesite dva trocifrena cela broja:\n");
		scanf("%d %d", &x, &y);
		if (kontrola_unosa(x, y) == 1) {
			printf("Korisnik je uneo interval trocifrenih brojeva u intervalu [%d,%d]\n", x, y);
		}

	} while (kontrola_unosa(x, y) != 1);
	deljiv_sa2(x, y);
}
int savrsen(int broj) {

	int zbir = 0;
	//ako je jednak sumi njegovih delilaca
	for (int i = 1; i < broj; i++)
	{
		if (broj%i == 0) {
			zbir += i;

		}
	}
	if (zbir != broj) {
		return 0;
	} return 1;
}

void ispisi_niz(int niz[], int kapacitet) {
	for (int i = 0; i < kapacitet; i++)
	{
		printf("%d\t", niz[i]);
	}
}

void unesi_u_niz(int niz[], int* kapacitet, int element) {
	niz[(*kapacitet)++] = element;
}
int da_li_postoji_u_nizu(int niz[],int kapacitet,int broj) {
	int brojac = 0;
	for (int i = 0; i < kapacitet; i++)
	{
		if (niz[i] == broj) {
			brojac++;
			
		}
	}
	return brojac;
}

void napravi_niz_od_niza(int nizx[], int n1, int nizy[], int* n2) {
	*n2 = 0;
	for (int i = 0; i < n1; i++)
	{
		if(da_li_postoji_u_nizu(nizy,*n2,nizx[i])==0)
			unesi_u_niz(nizy, n2, nizx[i]);
		
	}
	
}
void unesi_s_tastature(int niz[], int kapacitet) {
	for (int i = 0; i < kapacitet; i++)
	{
		printf("Unesite niz[%d] element niza: ",i);
		scanf("%d", &niz[i]);
	}
}

void ubaci_na_pocetak(int niz[], int *n, int broj) {
	(*n)++;
	for (int i = *n-1; i>0; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[0] = broj;

}
void niz_parnih(int niz1[], int n1, int niz2[], int* n2) {
	for (int i = 0; i < n1; i++)
	{
		if(niz1[i]%2==0)
		unesi_u_niz(niz2, n2, niz1[i]);
	}
}

void aritmeticki_niz(int niz[], int n) {
	int brojac = 0;
	for (int i = 0; i < n; i++)
    {
		int d = niz[i+1] - niz[i];
		
		if (niz[i+1] = niz[i]+d) {
			brojac++;
		}
	}
	
	printf("%d", brojac);
}

int sr_vr(int niz[], int n) {
	int  srvr;
	int suma = 0;
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		suma += niz[i];
		brojac++;
	
		
	}
	srvr = suma / brojac;
	//printf("%.2lf", srvr);
	return srvr;
}






int vrati_poziciju(int niz[], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return i;
		}
	}
	return -1;
}

void izbrisiELement(int niz[], int* kapacitet, int element) {
	int pozicija = vrati_poziciju(niz, kapacitet, element);
	for (int i = pozicija; i <= (*kapacitet); i++) {
		niz[i] = niz[i + 1];
		

	}
	//(*kapacitet)--;
}
void srednje_vrednosti(int nizx[], int n, int nizy[], int* m) {
	
	for (int i = 0; i < n; i++)
	{
		if (nizx[i] > sr_vr(nizx, n)) {
			unesi_u_niz(nizy, m, nizx[i]);
			izbrisiELement(nizx, &n, nizx[i]);
			
		}
	}
	
}

void main() {
	int niz[100];
	int niz1[100];
	int n1=0;
	int n = 0;
	unesi_u_niz(niz, &n, 15);
	unesi_u_niz(niz, &n, 18);
	unesi_u_niz(niz, &n, 21);
	unesi_u_niz(niz, &n, 254);
	unesi_u_niz(niz, &n, 27);
	unesi_u_niz(niz, &n,4);
	unesi_u_niz(niz, &n, 45);
	
	ispisi_niz(niz, n);
	srednje_vrednosti(niz, n, niz1, &n1);
	//izbrisiELement(niz, &n, 15);
	printf("\n");
	ispisi_niz(niz, n);
	printf("\n");
	ispisi_niz(niz1, n1);
	
	
}