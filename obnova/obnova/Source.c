#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void broj_cifara(int x) {
	int brojac = 0;
	while (x != 0) {
		x /= 10;
		brojac++;
		
	}
	printf("%d", brojac);
}

void ispisi_zbir(int a, int b) {
	int c = a + b;
	printf("Zbir %d i %d je : %d", a, b, c);
}

int najveci_od_tri(int a, int b, int c) {
	int max=-159509;
	if (a > b && a > c) {
		max = a;
	}
	if (b > a && b > c) {
		max = b;
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

int proizvod_prostih_cifara(int x) {
	int proizvod = 1;
	while (x != 0) {
		if (prost(x)) {
			proizvod *= x;
		}
		x /= 10;
	}
	return proizvod;
}

void main() {
	int x;
	printf("Unesite neki broj: ");
	scanf("%d", &x);
	printf("Proizvod prostih cifara u broju %d je: %d", x, proizvod_prostih_cifara(x));
}