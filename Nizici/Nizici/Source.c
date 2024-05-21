#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiNiz(int niz[200], int kapacitet) {
	int i;
	for ( i = 0; i < kapacitet; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void dodajUNiz(int niz[200], int* kapacitet, int element) {
	niz[(*kapacitet)++] = element;
}
void sumaNiza(int niz[200], int kapacitet) {
	int suma = 0;
	for (int i = 0; i <kapacitet; i++)
	{
		suma += niz[i];
	}
	printf("Suma elemenata naseg niza je:%d", suma);
}
int daLiPostojiBroj(int niz[200], int kapacitet, int broj){
	int i;
	for (i = 0; i < kapacitet; i++)
	{
		if (niz[i] == broj) {

			return 1;


		}
	}

}
void avgNeparnih(int niz[200], int kapacitet) {
	double avg;
	int i,brojac=0;
	int suma = 0;
	for ( i = 0; i < kapacitet; i++)
	{
		if (niz[i] % 2 != 0) {
			brojac++;
			suma += niz[i];
			avg = (double)suma / brojac;
		}
	}
	printf("Prosecna vrednost neparnih elemenata u nizu je: %.2lf", avg);
}
void izNizaUNiz(int nizX[200], int kapacitet, int nizY[200],int* m) {
	*m = 0;
	for (int i = 0; i < kapacitet; i++)
	{
		if(nizX[i]%2==0)
		nizY[(*m)++] = nizX[i];
	}
	//ispisiNiz(nizY, kapacitet);
}


void main() {
	int niz[200];
	niz[0] = 15;
	int n = 1;
	dodajUNiz(niz, &n, 6);
	dodajUNiz(niz, &n, 89);
	dodajUNiz(niz, &n, 41);
	dodajUNiz(niz, &n, 512);
	



	
	ispisiNiz(niz, n);
	printf("\n");
	sumaNiza(niz, n);
	printf("\n");
	if (daLiPostojiBroj(niz, n, 8959)==1) {
		printf("Uneti broj postoji u nizu!");
	}
	else {
		printf("Uneti broj ne postoji u nizu!");
	}
	avgNeparnih(niz, n);
	printf("\n");
	int niz1[200];
	int n1;
//	izNizaUNiz(niz, n,niz1,&n1);
	//ispisiNiz(niz1, n1);
	
}