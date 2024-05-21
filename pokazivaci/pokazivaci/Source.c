#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zamenaMesta(int a, int b) {
	//program za menjanje mesta brojeva
	
	printf("Broj a pre zamene ima vrednost: \n %d\n", a);
	printf("Broj b pre zamene ima vrednost: \n %d\n", b);

	int c = a;
	a = b;
	b = c;

	printf("Broj a posle zamene ima vrednost: \n %d\n", a);
	printf("Broj b posle zamene ima vrednost: \n %d\n", b);
}

void uvecaj(int *a) {
	*a=*a+1;}
void umanji(int *b) {
	*b = *b - 1;
	
}


void main() {
	/*int a;
	a = 45;
	printf("Broj a pre izmene je : %d\n", a);
	int *pok_a;
	pok_a = &a;
	*pok_a = 52;
	printf("Broj a posle izmene preko pokazivaca na a je:  %d\n", a);
	//vrednost broja a i njegova adresa
	printf("a=%d , &a=%d ", a, &a);
	*/
	int a = 15;
	uvecaj(&a);
	printf("%d", a);
	umanji(&a);
	printf("%d", a);
}