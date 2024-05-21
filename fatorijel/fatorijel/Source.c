#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void suma(int n) {
	//program koji ispisuje sumu brojeva do unetog broja
	int suma = 0;
	for (int i = 0; i <=n; i++)
	{
		suma += i;
	}
	printf("Suma brojeva do broja %d je: \n %d\n", n, suma);
}

int faktorijel(int n) {

	//funkcija koja za uneti broj n racuna njegov faktorijel
	

	printf("Unesite neki broj:\n");
	scanf("%d", &n);
	int rezultat = 1;
	for (int i = n; i > 0; i--)
	{
		rezultat = rezultat * i;
	}
	//printf("Faktorijel unetog broja je \n%d\n", rezultat);
	return rezultat;
}
void razlikaFaktorijela(int a, int b) {
	int f1 = faktorijel(a);
	int f2 = faktorijel(b);
	int raz = f1 - f2;
	printf("Razlika faktorijela brojeva %d i %d je: \n%d",a,b,raz);
}
void main() {
	
	//suma(4);
	//faktorijel(5);
	razlikaFaktorijela(5, 4);
}