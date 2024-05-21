#define _CRT_NO_WARNINGS
#include <stdio.h>

void ubaci_u_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}
void ispisi_niz(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
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
void razlika_nizova(int niz[], int n,int niz1[], int n1, int niz2[], int* n2 ) {
	for (int i = 0; i < n; i++)
	{
		if (postoji(niz1, n1, niz[i]) == 1) {
			ubaci_u_niz(niz2, n2, niz[i]);
		}
	}
}
void uvecanje_niza(int niz[],int* n){
	for (int i = 0; i < *
n; i++)
	{
		if (i % 2 == 1) {
			niz[i]++;
		}
		else {
			niz[i] += 2;
		}
	}
}
void najduzi_podniz_istih(int niz[], int n) {
	int i=0;
	int max_index, max_karakter, max_duzina = 0;
	int t_index, t_karakter, t_duzina;
	while (i < n) {
		while (niz[i] != niz[i + 1] && i < n) {
			i++;
		}
		t_index = i;
		t_karakter = niz[i];
		t_duzina = 0;
		while (niz[i] == niz[i + 1] && i < n) {
			t_duzina++;
			i++;
		}
		if (max_duzina < t_duzina) {
			max_index = t_index;
			max_karakter = t_karakter;
			max_duzina = t_duzina;
		}
	}
	max_duzina++;
	printf("Najveca duzina je:%d, a karakter: %d\n", max_index, max_karakter);
	
	for ( i = max_index; i < max_index+max_duzina; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void najduzi_podniz_parnih(int niz[], int n){
	int i = 0;
	int max_index, max_duzina = 0;
	int t_index,  t_duzina;

	while (i < n) {
		while (niz[i] % 2 != 0 && i < n) {
			i++;
		}
		t_index = i;
		
		t_duzina = 0;
		while (niz[i] % 2 == 0 && i < n) {
			t_duzina++;
			i++;
		}
		if (max_duzina < t_duzina) {
			max_index = t_index;
			
			max_duzina = t_duzina;
		}
	}
	max_duzina++;

	

	printf("Elementi najduzeg podniza:\n");
	for (i = max_index; i < max_index + max_duzina-1; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int neopadajuci(int niz[], int n) {
	int i, j;
	for ( i = 0; i < n-1; i++)
	{
		for ( j =i+1; j < n; j++)
		{
			if (!(niz[i] >=niz[j])) {
				return 0;
			}
		}
	}
	return 1;
}
void sredi_u_neopadajuci(int niz[], int* n) {
	int i, j;
	for ( i = 0; i <*n-1; i++)
	{
		for ( j = i+1; j < *n; j++)
		{
			if (niz[i] < niz[j]) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
}
void neopadajuci_niz_od_nizova(int niz[5], int niz1[8], int niz2[], int* n2) {
	int i;
	if (neopadajuci(niz, 5) == 1 && neopadajuci(niz1, 8) == 1) {
		for (i = 0; i < 5; i++)
		{

			ubaci_u_niz(niz2, n2, niz[i]);
		}
		for (i = 0; i < 8; i++)
		{

			ubaci_u_niz(niz2, n2, niz1[i]);
			sredi_u_neopadajuci(niz2, n2);
		}
	}
	else {
		printf("Jedan od nizova nije neopadajuci!!!");
		
	}
}
void ubaci_na_pocetak_niza(int niz[], int* n, int el) {
	for (int i = *n; i>=0; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[0] = el;
	(*n)++;
}
void ubaci_na_poziciju(int niz[], int* n, int el, int poz) {
	for (int i =*n; i>=poz; i--)
	{
		niz[i] = niz[i - 1];
	}
	(*n)++;
	niz[poz-1] = el;
}
void izbaci_sa_pocetka(int niz[], int* n) {

	int i;
	niz[0] = NULL;
	for ( i = 0; i<*n; i++)
	{
		niz[i] = niz[i + 1];
	}
	
	(*n)--;
}
void izbaci_sa_pozicije(int niz[], int* n, int pozicija) {
	int i;
	niz[pozicija-1] = NULL;
	for ( i = pozicija-1; i <*n; i++)
	{
		niz[i] = niz[i + 1];
	}
	(*n)--;
}
int vrati_poziciju(int niz[], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return i+1;
		}
	}
	return -1;
}
int vrati_element_na_poziciji(int niz[], int n, int poz) {
	return niz[poz];
}
void izbaci_element(int niz[], int* n, int el) {
	izbaci_sa_pozicije(niz, n, vrati_poziciju(niz, n, el));
}
int prost(int broj) {
	int brojac = 0;
	for (int i = 1; i <=broj;i++){
		if (broj%i == 0) {
			brojac++;
		}
	}
	if (brojac == 2) {
		return 1;
	}
	return 0;
}
void najduzi_podniz_prostih(int niz[], int n) {
	int i = 0;
	int max_index, max_karakter, max_duzina = 0;
	int T_index, T_karakter, T_duzina;
	while (i < n) {
		while (i < n && prost(niz[i])==0) {
			i++;
		}
		T_index = i;
		T_karakter = niz[i];
		T_duzina = 0;
		while (prost(niz[i])==1 && i < n) {
			T_duzina++;
			i++;
		}
		if (max_duzina < T_duzina) {
			max_index = T_index;
			max_karakter = T_karakter;
			max_duzina = T_duzina;
		}
    }
	max_duzina++;
	printf("Najveci podniz prostih brojeva je:\n");
	for ( i = max_index; i < max_duzina+max_index-1; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int pozicija_najmanjeg_parnog(int niz[], int n) {
	int najmanji = 2000;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 0 && niz[i] < najmanji) {
			najmanji = niz[i];
		}
		if (najmanji == niz[i]) {
			return i+1;
		}
	}

	return -1;
}
void razlika_prvih_n_i_zadnjih_k(int niz[],int n, int k,int m) {
	int i;
	int suma1 = 0;
	int suma2 = 0;
	for ( i = 0; i <= k-1; i++)
	{
		suma1 += niz[i];
	}
	for ( i = n-m; i <n ; i++)
	{
		suma2 += niz[i];
	}
	printf("Zbir prvih %d brojeva je: %d\t\n",k, suma1);
	printf("Zbir poslednjij %d brojeva je: %d\t\n",m, suma2);
	printf("Razlika prvih %d elemenata i poslednja %d elementa:%d\n", k, m, suma1 - suma2);
}
double vrati_sr_vr(int niz[], int n) {
	int suma = 0;
	int brojac = 0;
	int sr_vr;
	for (int i = 0; i <n; i++)
	{
		suma += niz[i];
		brojac++;
	}
	return (double)suma / brojac;
}
void srednje_vredsnosti(int niz[], int n, int niz1[], int* n1) {

	int i;
	for ( i = 0; i < n; i++)
	{
		if (vrati_sr_vr(niz, n) > niz[i]) {
			ubaci_u_niz(niz1, n1, niz[i]);
			printf("Elementi koji se prebacuju iz niza A u niz B su:%d\t\n",niz[i]);
			//izbaci_element(niz, n, niz[i]);
		}
		
	}
	printf("Srednja vrednost niza A posle prebacivanja je:%d\n", vrati_sr_vr(niz, n));
	printf("Srednja vrednost niza B posle prebacivanja je:%d\n", vrati_sr_vr(niz1, n1));
}

void main() {
	int niz[100];
	int n = 0;

	int niz1[100];
	int n1 = 0;

	ubaci_u_niz(niz1, &n1, 15);
	ubaci_u_niz(niz1, &n1, 1);
	ubaci_u_niz(niz1, &n1, 23);
	ubaci_u_niz(niz1, &n1, 5);

	ubaci_na_pocetak_niza(niz, &n, 1999);
	ubaci_u_niz(niz, &n, 2003);
	ubaci_na_pocetak_niza(niz, &n, 325);
	ubaci_u_niz(niz, &n, 2);
	ubaci_u_niz(niz, &n, 1901);
	ubaci_u_niz(niz, &n, 1986);
	ispisi_niz(niz, n);
	printf("\n");
	ispisi_niz(niz1, n1);
	
	
	srednje_vredsnosti(niz, n, niz1, &n1);
	
}