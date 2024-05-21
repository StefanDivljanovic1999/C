#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ispisiManjeOd100() {
	printf("Brojevi manji od 100:\n");
	int i=00000;
	while (i < 100) {
		printf("%d\n", i);
		i++;
	}
}

//ispis svakog treceg broja od 200 do 150
void svakiTreciOd200do150() {
	int i = 200;
	while (i >= 150) {
		printf("%d\n", i);
		i = i - 3;
	}
}

void svakiTreciOd200do150FOR() {
	for (int i = 200; i>=150; i-=3)
	{
		printf("%d\n", i);
		
	}
}

void deljiviSa7odMinus40do40() {
	for ( int i = -40; i <=40; i++)
	{
		if (i % 7 == 0) {
			if(i==0)
			{
				continue;
			}
			printf("%d\n", i);
		}
		
		
	}
}
void ispitajBrojCifara(int x) {
	int brojac = 0;
	while (x != 0) {
		x /= 10;
		brojac++;
	}
	printf("%d", brojac);
}



void main() {
	ispisiManjeOd100();
	svakiTreciOd200do150();
	svakiTreciOd200do150FOR();
	deljiviSa7odMinus40do40();
	ispitajBrojCifara(159898);
	
}