#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 200
#define JASAM "Stefan"
#define Pi 3.14


void ispisiNiz(int niz[],int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		//if(niz[i]>=0)
		printf("%5d ", niz[i]);
	}
}
void dodajUNiz(int element,int niz[],int velicina) {
	niz[velicina++] = element;
	//velicina++;
}
void dodaj(int niz[], int* kapacitet, int element) {
	if (*kapacitet < 0 || *kapacitet >= 200) {
		return;
	}
	niz[(*kapacitet)++] = element;

}
void puniNiz(int niz[], int*n) {

	int brEl, a;
	do {
		printf("Unesite broj elemenata u intervalu od [1,%d]", MAX);
		scanf("%d", &brEl);
	} while (brEl <1 || brEl < 200);
	
		*n = 0;
		while (*n < brEl) {
			printf("Unesite element a: \n");
			scanf("%d", &a);
			dodajUNiz(niz, n, a);
		}
		
}




void main() {
	int niz1[] = { 2,3,20,30 };
	int niz2[6];
	int n1 = 4, n2 = 6, i;
	niz1[0] = 200;
//	printf("Zbir prvog i poslednjeg elementa niza je: \n%d\n", niz1[0] + niz1[3]);
	niz2[3] = 7;
	niz2[1] = 12;
	niz2[5] = 5;

	//ispisiNiz(niz2, n2);

	int niz3[MAX];
	int n3 = 0;
	niz3[n3] = 15;
	n3++;
	niz3[n3] = 20;
	n3++;
	niz3[n3++] = 35;
	//dodajUNiz(5, niz3, 0);
	dodaj(niz3, &n3, 45);
	dodaj(niz3, &n3, 55);
	//ispisiNiz(niz3, n3);
	//printf("%s", JASAM);
	puniNiz(niz3, n3);
	//ispisiNiz(niz3, n3);
}