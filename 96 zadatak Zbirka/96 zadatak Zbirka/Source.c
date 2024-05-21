#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisi_niz(int niz[], int kapacitet) {
	int i;
	for ( i = 0; i < kapacitet; i++)
	{
		printf("%d\t", niz[i]);
	}
}


void dodaj_na_pocetak(int niz[], int* kapacitet, int element) {
	niz[++(*kapacitet)] = element;
	for (int i = 0; i <= *kapacitet-1;i++) {
		
		niz[i + 1] = niz[i];
		niz[0] = element;
		
	}
}

void sjean() {
	int   student[40], pos, i, size, value;
	printf("Unesite velicinu niza studenata:");
	scanf("%d", &size);
	printf("Niz ce biti velicine: %d \n", size);
	for (i = 0; i < size; i++)
		scanf("%d", &student[i]);
	printf("Unesi poziciju na koju ubacujes studenta:");
	scanf("%d", &pos);
	printf("Vrednost na poziciji:");
	scanf("%d", &value);
	for (i = size - 1; i >= pos - 1; i--)
		student[i + 1] = student[i];
	student[pos - 1] = value;
	printf("Krajnji prikaz\n");
	for (i = 0; i <= size; i++)
		printf("%d\n", student[i]);
}

void main() {
	int niz[100];
	int n = 0;

	dodaj_na_pocetak(niz, &n, 15);
	dodaj_na_pocetak(niz, &n, 18);
	dodaj_na_pocetak(niz, &n, 65);
	dodaj_na_pocetak(niz, &n, 48);
	dodaj_na_pocetak(niz, &n, 78);
	dodaj_na_pocetak(niz, &n, 11);

	ispisi_niz(niz, n);
	
	

}