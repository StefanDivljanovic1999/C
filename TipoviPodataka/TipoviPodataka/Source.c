#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void prost(int broj) {
	int brojac = 0;
	
	for (int i = 0; i <=broj; i++)
	{
		printf("%d", broj%i);
			
	}
		
	
	printf("brojac je jedank %d\n", brojac);
	printf("broj je %d\n", broj);
}

void main() {
	prost(13);
}