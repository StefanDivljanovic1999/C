#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int niz[10];
	niz[0] = 5;
	printf("%d", niz[0]);

	for (int i = 0; i < sizeof(niz); i++)
	{
		if(niz[i]!=NULL)
		printf("%5d", niz[i]);
		
	}
}