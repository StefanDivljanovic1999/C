#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prost(int br) {
	if (br < 1 )
		return 0;
	int n = 0;
	for (int i = 1; i <= br; i++) {
		
		if (br%i == 0)
			
			n++;
	}
	if (n == 2) {
		return 1;
	}
	else {
		return 0;
	}
}

int proizvodprCifara(int broj) {
	int proizvod = 1;
	while (broj != 0) {
		
	int cifra=	broj % 10;
		broj /= 10;
		if (prost(cifra))
			proizvod *= cifra;
	}
	return proizvod;
}

void main() {
	int broj;
	printf("Unesite neki broj:\n");
	scanf("%d",&broj);
	//printf("%d", prost(broj));
	printf("Proizvod prostih cifara u broju je \n%d", proizvodprCifara(broj));
}