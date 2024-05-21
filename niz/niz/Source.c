#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void faktorijel(int a) {
	int rezultat=1;
	for (int i = 1; i <= a; i++)
	{
		rezultat =rezultat * i;
		
}
	printf("Faktorijel unetog broja je:%d\n", rezultat);
	
}
void suma(int a) {
	int rezultat = 0;
	for (int i = 0; i <= a; i++)
	{
		rezultat += i;
	}
	printf("Suma unetog broja je: %d\n", rezultat);
}

void main() {
	int a = 3;
	faktorijel(6);
	suma(8);
}