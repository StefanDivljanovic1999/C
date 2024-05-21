#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zameni(int a, int b) {
	printf("Broj a pre zamene ima vrednost: %d\n", a);
	printf("Broj b pre zamene ima vrednost: %d\n\n", b);

	int c;
	c = a;// c=5;
	a = b;// a=b=6;
	b = c;// b=5;

	printf("Broj a posle zamene ima vrednost: %d\n", a);
	printf("Broj b posle zamene ima vrednost: %d\n", b);
}

void uvecaj(int *a) {
	a=a+1;
}

void main() {
	/*int r = 5;
	int t = 10;
	zameni(r, t);*/

	int a;
	a = 5;
	int *pok_a;
	pok_a = &a;
	//*pok_a = 10;
	uvecaj(&a);
	printf(" &a=%p pok_a=%p &pok_a=%p *pok_a=%d a=%d\n", &a, pok_a,&pok_a,*pok_a,a);

	
}