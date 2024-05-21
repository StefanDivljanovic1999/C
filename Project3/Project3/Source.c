#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void main() {
	
	int *a = malloc(sizeof(int));
	*a = 10;
	printf("*a=%d\n", *a);

	a = NULL;

}