#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 200
void dodaj(int niz[], int* n, int element) {
	niz[(*n)++] = element;
}

void ispisi(int niz[], int n) {
	int i;
	for ( i = 0; i < n; i++)
	{
		printf(" %5d", niz[i]);
	}
}

void puniNiz(int niz[],  int* n) {
	int brEl,element;
	do{
		printf("Unesite broj elementa: ");
		scanf("%d", &brEl);
	}
	while (brEl<1 || brEl>200);
	
	
	//printf("dosao sam");
	*n = 0;
	while ((*n)<brEl)
	{
		
		printf("Unesite element u niz:");
		scanf("%d", &element);
		dodaj(niz, n, element);
		//ispisi(niz, n);
	}
}
int* deklaracija(int* n){
	do {
		printf("Unesi dimenziju koja je prirodan broj!");
		scanf("%d", n);

	} while (*n < 1);
	int* niz = (int*)malloc((*n) * sizeof(int));
	return niz;
	
}
void sortiraj(int niz[], int* n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < *n; j++)
		{
			if (niz[j] < niz[i]) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
}


void main() {
	int niz[MAX];
	int n = 0;
	int n4 = 0;
	int j;
	dodaj(niz, &n, 28);
	dodaj(niz, &n, 11);
    dodaj(niz, &n, 43);
    dodaj(niz, &n, 1718);
	dodaj(niz, &n, 0);
	dodaj(niz, &n, 19);
	dodaj(niz, &n, 5);
	
	//puniNiz(niz, &n4);
	//printf("%d\n", *(niz + 3));
	
	sortiraj(niz, &n);
	ispisi(niz, n);
}