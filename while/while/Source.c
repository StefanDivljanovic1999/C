#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int prost(int broj) {
	
	if (broj % 2 == 0 || broj % 3 == 0 || broj % 4 == 0 || broj % 5 == 0 || broj % 6 == 0 || broj % 7 == 0 || broj % 8 == 0 || broj % 9 == 0) {
		printf("Uneti broj je slozen!");
		return 0;
	}
	else {
		printf("Uneti broj je prost!");
		return 1;
	}
	
}
void mnozi(int broj) {
	int c1 = broj / 1000;
	int c2 = (broj / 100) % 10;
	int c3 = (broj / 10) % 10;
	int c4 = broj % 10;
	if (prost(c1)) {
		printf("d");
	}
}
void sumaPrvihPetBrojeva() {
	int zbir = 0;
	int x=1;
	while (x<6) {
		zbir += x;
		x++;
	}
	printf("suma brojeva %d", zbir);
}
void sumaNbrojeva(int n) {
	int zbir = 0;
	int i = 1;
	while (i <= n) {
		zbir += i;
		i++;
	}
	printf("Zbir brojeva do broja %d je: \n %d", n, zbir);
}
void proizvodNbrojeva(int n) {
	int proizvod = 1;
	int i = 1;
	while (i <= n) {
		proizvod *= i;
		i++;
	}
	printf("Proizvod brojeva do broja %d je: \n %d", n, proizvod);
}
void proizvodNeparnih(int n) {
	int proizvod = 1;
	int i = 1;
	while (i <= n) {
		if(i%2!=0)
		proizvod *= i;
		i++;
	}
	printf("Proizvod neparnih brojeva do broja %d je: \n %d", n, proizvod);
}
void dvaN(int n) {
	int i;
	int z = pow(2, n);
	printf("2 na %d je:\n %d", n, z);
	int stepen = 1;
	for ( i = 0; i <=stepen; i++)
	{
		stepen *= 2;
	}
	printf("\n%d", stepen   );
}

void trocifreniNeparni() {
	//trocifreni brojevi cija je desetica manja od 5, a cifra neparna
	int broj;

	for (broj = 100; broj <=999; broj++)
		//printf("Beograd");
	{
		int stote = broj / 100;
		int desetice = (broj / 10) % 10;
		int jednice = broj % 10;

		if (jednice % 2 != 0 && desetice < 5) {
			
				printf("%2d\n", broj);
		}
	}
}
void piramida(int n) {
	int i, j, k;
	for ( i = 0; i <=n; i++)
	{
		for ( k = 0; k < n-i; k++)
		
			printf(" ");
		for ( j = 0; j < 2*i; j++)
		
			printf("* ");
		printf("\n");
	}

}


void main() {
	//prost(568);
	//mnozi(43456);
	//sumaPrvihPetBrojeva();
	//sumaNbrojeva(100);
	//proizvodNbrojeva(10);
	//proizvodNeparnih(10);
	//dvaN(6);
	//trocifreniNeparni();
	piramida(3);
}