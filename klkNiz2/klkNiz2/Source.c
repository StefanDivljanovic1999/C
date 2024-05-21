#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dodaj_u_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}

void ubaci_na_pocetak(int niz[], int* n, int br) {
	(*n)++;
	for (int i = *n; i > 0; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[0] = br;
}

void ispisi_niz(int niz[], int n) {
	printf("Elementi niza: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}

int postoji(int niz[], int* n, int el) {
	for (int i = 0; i < *n; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
	}
	return -1;
}

void dodaj_posle_broja(int niz[], int*n, int broj, int novi) {
	(*n)++;
	int i  = 0;
	while (niz[i] != broj) {
			i++;
	}
	niz[i] = novi;
	
}

int vrati_poziciju(int niz[], int n, int br) {
	int i = 0;
	while (niz[i] != br) {
		i++;
	}
	return i;
}

void cifre(int br) {
	while (br != 0) {
		printf("%d\t", br%10);
		br /= 10;
	}
}

void ubaci_cifre_u_niz(int niz[], int* n, int br) {
	while (br != 0) {
	ubaci_na_pocetak(niz, n, br % 10);
		br /= 10;
	}
}

void izbaci_sa_pocetka(int niz[], int* n) {
	for (int i = 0; i<=*n; i++)
	{
		niz[i] = niz[i + 1];
	}
	(*n)--;

}

void izbaci_sa_kraja(int niz[], int* n) {
	(*n)--;
}

void invertuj_niz(int niz[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		int tmp = niz[i];
		niz[i] = niz[n - i - 1];
		niz[n - i - 1] = tmp;
	}
	
}

int palindrom(int niz[], int n) {
	for (int i = 0; i < n/2; i++)
	{
		int tmp = niz[i];
		if (niz[i] != niz[n - i-1]) {
			return 0;
		}
	}
	return 1;
}

void sortiraj_opadajuce(int niz[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j<n; j++)
		{
			if (niz[i] < niz[j]) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
	
}

int da_li_je_rastuci(int niz[], int n) {
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1;  j <n;  j++)
		{
			if (niz[j] < niz[i]) {
				return 0;
			}
		}
	}
	return 1;
}

void dodaj_pre_prvog_veceg(int niz[], int* n, int el) {
	int k=0;
	while (niz[k] < el) {
		k++;
	}

	(*n)++;
	for (int i = *n-1; i>k; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[k] = el;
}

void formiraj_rastuci(int niz1[], int n, int niz2[], int n2, int niz3[], int* n3) {
	for (int i = 0; i < n2; i++)
	{
		dodaj_u_niz(niz3, n3, niz2[i]);
	}
	
			for (int i = 0; i < n; i++)
	{
		dodaj_pre_prvog_veceg(niz3, n3, niz1[i]);
	}
}

void par_nepar(int niz[], int n, int par[], int* p1, int nepar[], int* n1) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 0) {
			dodaj_u_niz(par, p1, niz[i]);
		}
		else {
			dodaj_u_niz(nepar, n1, niz[i]);
		}
	}
}

int broj_ponavljanja(int niz[], int n, int br) {
	int brojac = 0;
	for (int i = 0; i <br; i++)
	{
		if (niz[i] == br) {
			brojac++;
		}
	}
	return brojac;
}

void ponavljanje(int niz[], int n, int jedn[], int* j, int vise[], int* v) {
	for (int i = 0; i < n; i++)
	{
		if (broj_ponavljanja(niz, n, niz[i]) == 1 && broj_ponavljanja(jedn,*j,niz[i])==0) {
			dodaj_u_niz(jedn, j, niz[i]);
		}
		else {
			if (broj_ponavljanja(vise, *v, niz[i]) == 0) {
				dodaj_u_niz(vise, v, niz[i]);
			}
		}
	}
}
void main() {
	int niz[499];
	int n = 0;

	dodaj_u_niz(niz, &n, 15);
	dodaj_u_niz(niz, &n, 18);
	dodaj_u_niz(niz, &n, 23);
	dodaj_u_niz(niz, &n, 46);
	dodaj_u_niz(niz, &n, 98);
	dodaj_u_niz(niz, &n, 7);
	dodaj_u_niz(niz, &n, 15);
	dodaj_u_niz(niz, &n, 1);
	dodaj_u_niz(niz, &n, 23);


	dodaj_u_niz(niz, &n, 7);


	ispisi_niz(niz, n);

	int jedn[499];
	int j = 0;

	int vise[499];
	int v = 0;

	ponavljanje(niz, n, jedn, &j, vise, &v);
	printf("\nJednom: \n");
	ispisi_niz(jedn, j);
	printf("\nVise:\n");
	ispisi_niz(vise, v);
}
