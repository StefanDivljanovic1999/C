#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dodajUNiz(int niz[200], int* kapacitet, int broj) {
	niz[(*kapacitet)++] = broj;
}

void ispisiNiz(int niz[200], int kapacitet) {
	int i;
	for (i = 0; i < kapacitet; i++)
	{
		printf("%d\t", niz[i]);
	}
}

void sortirajNiz(int niz[200], int kapacitet) {
	int i, j;
	for ( i = 0; i <kapacitet; i++)
	{
		for ( j = i+1; j <kapacitet; j++)
		{
			if (niz[i] > niz[j]) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
}
void srednjaVrednost(int niz[200], int n) {
	int zbir = 0;
    int i;
	float srvr;
	for (i = 0; i < n; i++)
	{
		zbir += niz[i];
		srvr = (float)zbir / n;
	}
	printf("Srednja vrednost niza je:%.2lf", srvr);
	printf("\n");
	printf("Broj elemenata je:%d", n);
}

void unesiUNiz(int niz[200], int* n) {
	int element;
	
	do
	{
		printf("Unesite element u niz:\n");
			scanf("%d", &element);
			dodajUNiz(niz, n,element);
			
		
	} while (element!=105);
	//ispisiNiz(niz, n);
}

void NajveciElementNiza(int niz[200], int n) {
	
	int i;
	int max = 0;
	for ( i = 0; i <n; i++)
	{
		if (niz[i] > max) {
			max=niz[i];
			
		}
	}
	printf("\nNajveci element niza je:%d", max);
}

void napraviNoveNizove(int niz[200], int n){
	int b[100], c[100];
	int n_b=0, n_c = 0;
	for (int i = 0; i <n; i++)
	{
		if (niz[i] % 2 == 0) {
			b[n_b++] = niz[i];
		}
		else {
			c[n_c++] = niz[i];
		}
	}
	printf("\nElementi niza b su\n");
	ispisiNiz(b, n_b);
	printf("\nElementi niza c su\n");
	ispisiNiz(c, n_c);
}

void main() {
	int niz[100];
	int n = 0;
	niz[0] = 15;
	n++;
	niz[1] = 18;
	n++;
	
	dodajUNiz(niz, &n, 5);
	//sortirajNiz(niz, n);
	unesiUNiz(niz, &n);
	ispisiNiz(niz, n);
	NajveciElementNiza(niz, n);
	napraviNoveNizove(niz, n);
	//srednjaVrednost(niz, n);

}