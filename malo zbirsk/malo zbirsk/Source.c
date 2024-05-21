#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void suma_jednocifrenih_brojeva() {
	int i=0;
	int suma = 0;
	printf("Suma jednocifrenih brojeva iznosi\n");
	do{
		suma += i;
		i++;
	} while (i<10);
	printf("%d", suma);
}

int  zbirCifara(int broj) {
	int suma = 0;
	int cifra;
	while (broj!=0)
	{
		cifra = broj % 10;
		broj /= 10;
		suma += cifra;
	}
	
	return suma;
	
}

void zbir_cifara_deljiv_sa3(int dg, int gg) {
	for (int i = dg; i <= gg; i++)
	{
		if (zbirCifara(i) % 3 == 0) {
			printf("%d\t", i);
		}
	}
	
}

void aritmetcki_niz() {
	int a, d, n;
	printf("Unesite razliku aritm niza");
	scanf("%d", &d);
	do
    {
		printf("Unesite neki element:");
		scanf("%d", &a);
	} while (a=a+d);
	
}

int kontrola_unosa(int br1, int br2) {
	if(br1>0 && br2>0 && br1<=br2){
		return 1;
	}
	return 0;
}

void srendnja_vrednost_neparnih(int x, int y) {
	double srvr;
	int i;
	int suma = 0;
	int brojac = 0;
	for (i = x; i <=y; i++)
	{
		if (i % 2 != 0) {
			brojac++;

			suma += i;

			srvr = (double)suma / brojac;
		}
	}
	printf("Srednja vrednost je: %.3lf", srvr);
	
	
}


void zadatak1() {
	int brojac = 0;
	int x, y;
	do {
		printf("Unesite dva cela broja veca od nule i prvi manji ili jednak drugom:\n");
		scanf("%d %d", &x, &y);
		brojac++;
		if (kontrola_unosa(x, y) == 1) {
			printf("Korisnik je uneo interval [%d,%d]", x, y);
			break;
		} 
	} while (brojac<3);
	if (brojac ==3 && kontrola_unosa(x,y)!=1) {
		printf("Korisnik je iskoristio tri pokusaja, ali nije uneo interval na pravi nacin!");
		}
	
	srendnja_vrednost_neparnih(x, y);
}

void main() {
	//printf("%d", kontrola_unosa(15, 16));
	zadatak1();
}