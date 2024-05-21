#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void dodaj(int x, int y, char op) {
	if (op == '+') {
		printf("Zbir unetih brojeva je: %d", x + y);
	}
	if (op == '-') {
		printf("Razlika unetih brojeva: %d", x - y);
	}
	if (op == '*') {
		printf("Proizvod dva uneta broja je: %d", x * y);
	}
	if (op == '/') {
		printf("Kolicnik unetih brojeva je: %.2lf",(double) x / y);
	}
}
void main() {
	int p;
	int q;
	char opr;
	
	printf("Unesite prvi broj: \n");
	scanf("%d", &p);

	printf("Unesite drugi broj: \n");
	scanf("%d", &q);
	
	
	printf("Unesite operaciju: \n");
	getchar();
	scanf("%c", &opr);
	
	dodaj(p,q,opr);
	
	
}