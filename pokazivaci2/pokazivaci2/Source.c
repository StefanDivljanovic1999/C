#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void zamenaMesta(int *pok_a, int *pok_b) {
	
	printf("Broj a pre zamene ima vrednost: %d\n", *pok_a);
	printf("Broj b pre zamene ima vrednost: %d\n", *pok_b);
	int c = *pok_a;
	*pok_a = *pok_b;
	*pok_b = c;
	printf("Broj a posle zamene ima vrednost: %d\n", *pok_a);
	printf("Broj b posle zamene ima vrednost: %d\n", *pok_b);
}

void main() {

	int g=45; 
	int h=55;
	/*printf("Broj a pre zamene ima vrednost: %d\n", a);
	int *pok_a;
	pok_a = &a;
	*pok_a = 45;
	printf("Broj a posle zamene ima vrednost: %d\n", a);*/
	zamenaMesta(&g, &h);
}



