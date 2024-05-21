#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 200;

void ispisi(int niz[], int kapacitet) {
	//int i;
	for (int i = 0; i < kapacitet; i++)
	{
		printf(" %d ", niz[i]);
		
	}
}
void dodaj(int niz[], int* kapacitet, int element) {
	niz[*kapacitet] = element;
	*(kapacitet)++;
	
}

void main() {
	int niz1[200];
	niz1[1] = 67;
	int kapac = 0;
	dodaj(niz1, &kapac, 15);
	
	ispisi(niz1, kapac);

}