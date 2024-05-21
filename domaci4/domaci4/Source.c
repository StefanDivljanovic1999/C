#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void cifre(int x) {
	
/*	printf("%d", x % 10);
	x = x / 10;
	printf("%d", x % 10);
	x = x / 10;
	printf("%d", x % 10);
	x = x / 10;
	printf("%d", x % 10);
	*/
	while (x != 0) {
		int cifra = x % 10;
		printf("  %d ",cifra);
		x /= 10;

		}
	
}

int prost(int x) {
	int brojac = 0;
	for (int i = 1; i <=x; i++)
	{
		if (x%i == 0) {
			brojac++;
		}
	}
	if (brojac == 2) {
		return 1;
	}
	return 0;
}

int proizvod_prostih(int x) {
	int cifra;
	int proizvod = 1;
	while (x != 0) {
		cifra = x % 10;
		x /= 10;

		if (prost(cifra) == 1) {
			proizvod *= cifra;
		}
	}
	return proizvod;
}

double max(double a, double b, double c) {
	if (a >= b && a >= c) {
		return a;
	}
	if (b >= a && b >= c) {
		return b;
	}
	if (c >= a && c >= b) {
		return c;
	}
}

void da_li_je_samoglasnik(char s) {
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s=='u'
		|| s == 'A' || s == 'E' || s == 'I'  || s == 'O' || s=='U') {
		printf("Samoglasnik!");
	}
	else {
		printf("Suglasnik!");
	}
}

void main() {
	double br1;
	double br2;
	double br3;
	
	printf("Unesite neki broj: ");
	scanf("%lf ", &br1);
	
	printf("Unesite neki broj: ");
	scanf("%lf ", &br2);

	printf("Unesite neki broj: ");
	scanf("%lf ", &br3);

	printf("Najveci broj od unetih je: %lf ", max(br1,br2,br3));
}