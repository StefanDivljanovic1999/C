#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void ispisiNiz(int niz[], int kapacitet) {
	for (int i = 0; i < kapacitet; i++)
	{
		printf("%d\t", niz[i]);
	}
}

void dodaj(int niz[200], int* kapacitet, int element) {
	
	niz[(*kapacitet)++] = element;
}

 int daLiJeUNizu(int niz[],int kapacitet,int element) {
	for (int i = 0; i <kapacitet ; i++)
	{
		if (niz[i] == element) {
			return 1;
			
		}
	} return 0;
}

 void napraviNoviNiz(int niz[], int n, int niz2[], int* n2) {
	 *n2 = 0;
	 
     for (int i = 0; i <n; i++)
	 {
		 int indeks = daLiJeUNizu(niz2, *n2, niz[i]);
		 if (indeks==0) {
			 dodaj(niz2, n2, niz[i]);
		 }
	 }
	
 }

 int prost(int broj) {
	 int br = 0;
	 for (int i = 1; i <=broj; i++)
	 {
		 if (broj%i ==0) {
			 br++;
		 }
	 }
	 return br;
 }

 void nizOdProstih(int niz[], int n, int niz2[], int* n2) {
	 *n2 = 0;
	 for (int i = 0; i <n; i++)
	 {
		 if (prost(niz[i])==2) {
			 dodaj(niz2, n2, niz[i]);
		 }
	 }
	 
 }
 void deljiv(int broj) {
	 for (int i = 1; i <=broj; i++)
	 {
		 if (broj%i == 0) {
			 printf("%d\t", i);
		 }
	 }
 }

void main() {
	int niz[200];
	int n = 0;
	dodaj(niz, &n, 79);
	dodaj(niz, &n, 1019);
	dodaj(niz, &n, 7);
	dodaj(niz, &n, 1003);
	dodaj(niz, &n, 11);
	dodaj(niz, &n, 1549);
	
	int niz2[100];
	int n2 = 0;
	napraviNoviNiz(niz, n, niz2, &n2);
	//ispisiNiz(niz2,n2);
	
	int niz3[100];
	int n3 = 0;
	nizOdProstih(niz, n, niz3, &n3);
	//ispisiNiz(niz3,n3);
	deljiv(1954);
}