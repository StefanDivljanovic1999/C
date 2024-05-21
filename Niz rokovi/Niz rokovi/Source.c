#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 200;
void ubaci_na_pocetak(int niz[], int* kapacitet, int element) {
	niz[(*kapacitet)++] = element;
}

void ispisiNiz(int niz[], int kapacitet) {
	for (int i = kapacitet-1; i>=0 ; i--)
	{
		printf("%d\t", niz[i]);
	}
}

int postoji_u_nizu(int niz[], int kapacitet, int element) {
	for (int i = 0; i <kapacitet; i++)
	{
		if (niz[i] == element) {
			return 1;
		}
	}
	return -1;
}
int pun_niz(int niz[], int kapacitet) {
	for (int i = 0; i < kapacitet; i++)
	{
		if (i == kapacitet-1) {
			return 1;
		}
	}
	return -1;
}

void ubaci_na_poziciju(int arr[], int n, int x, int pos) {

	
	int i;
	for ( i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	

	
	n++;

	// shift elements forward
	for (i = n - 1; i >= pos; i--)
		arr[i] = arr[i - 1];

	// insert x at pos
	arr[pos - 1] = x;

	// print the updated array
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");

	
}



void main() {
	int niz[100];
	int n = 10;
	ubaci_na_poziciju(niz, n, 550, 5);
	
	
}