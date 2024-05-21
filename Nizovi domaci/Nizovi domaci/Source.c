#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 220
void dodaj(int niz[], int* n, int element) {
	niz[(*n)++] = element;
}

void ispisi(int niz[], int n) {
	printf("\nElementi niza su:\n");
	int i;
	for ( i = 0; i < n; i++)
	{
		printf(" %5d ", niz[i]);
	}
}
void unesi(int niz[], int* n) {
	int brEl;
	int element;
	do
	{
		printf("\nUnesite broj elemenata: \n");
		scanf("%d", &brEl);
	} while (brEl<1 || brEl>200);
	*n = 0;
	while ((*n) < brEl) {
		printf("Unesite neki element niza: ");
		scanf("%d", &element);
		dodaj(niz, n, element);
	}
}
void sortiraj(int niz[], int* n) {
	int i, j;
	for ( i = 0; i < *n-1; i++)
	{
		for ( j = i+1; j < *n; j++)
		{
			if (niz[j] < niz[i]) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
}
int parnost(int broj) {
	if (broj % 2 == 0) {
		return 1;
	}
	else {
		return 0;

	}
}
void sortirajPoParnosti(int niz[], int n) {
	int i, j;
	for ( i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (parnost(niz[j])==1) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
}
void invertuj(int niz[], int *n) {
	int i, j;
	for (i = 0; i < *n - 1; i++)
	{
		for (j = i + 1; j < *n; j++)
		{
			if (i<j) {
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
	}
	
}

void  najveciUNizu(int niz[], int* n) {
	int max = 0;
	int i;
	for ( i = 0; i < *n; i++)
	{
		if (niz[i] > max) {
			max = niz[i];

		}

	}
	printf("\n Najveci element u nizu je %d", max);
}
void najmanjiUNizu(int niz[], int* n) {
	int min = MAX;
	int i;
	for (i = 0; i < *n; i++)
	{
		if (niz[i] < min) {
			min = niz[i];

		}

	}
	printf("\n Najmanji element u nizu je %d\n", min);
}

void unosiDo0(int niz[], int* n) {
	//*niz = malloc(n * sizeof(niz));
	int brojac=0;
	int element;
	do
	{
		printf("Unesite neki element: ");
		scanf("%d", &element);
		//brojac++;
		if (element != 0) {
			brojac++;
			dodaj(niz, n, element);
		}

	} while (element!=0);
	printf("\nbroj elemenata u nizu je jednak: %d \n", brojac);
	 najveciUNizu(niz,n);
	 najmanjiUNizu(niz,n);

}
int palindrom(int niz[], int n) {
	int i;
	for (i = 0; i < n / 2; i++) 

		if (niz[i] != niz[n - i - 1]) 
			return 0;


			return 1;
		
	
	}

void invertuj1(int niz[], int n) {
	int i;
	for ( i = 0; i <n/2; i++)
	{
		int c = niz[i];
		niz[i] = niz[n - i - 1];
		niz[n - i - 1] = c;
	}
}


void main() {
	int niz[MAX];
	int n = 0;

	dodaj(niz, &n, 1999);
	dodaj(niz, &n, 15);
	dodaj(niz, &n, 535);
	dodaj(niz, &n, 145);
    dodaj(niz, &n, 545);
	dodaj(niz, &n, 545);
	dodaj(niz, &n, 145);
	dodaj(niz, &n, 535);
	dodaj(niz, &n, 15);
	dodaj(niz, &n, 1999);
	
	
	ispisi(niz, n);

	printf("\n1->palindrom,0->nije!\n%d", palindrom(niz, n));
}