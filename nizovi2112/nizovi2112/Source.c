#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

void ispisiniz(int niz[], int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%5d ", niz[i]);
	}
}


void dodaj(int niz[],int element,int n) {
	niz[n] = element;
	n++;
	ispisiniz(niz,n);
}

void main() {
	int n1 = 4,  n2 = 6;
	int niz[] = { 2,3,20,30 };
	niz[0] = 200;
	//printf("Zbir prvog i poslednjeg elementa niza %d + %d = %d\n", niz[0], niz[3],niz[0]+niz[3]);
	int niz1[6];
	niz1[3] = 7;
	niz1[4] = 5;
	niz1[5] = 12;
	printf("\n");
	
	
	dodaj(niz1, 51 , n1);
	printf("\n");
	ispisiniz(niz1, n2);
}