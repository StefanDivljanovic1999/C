#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main() {
	char s[100];
	printf("Unesite neki tekst:\n");
	scanf(" %s", &s);
	fgets(s, 100, stdin);
	printf(" %s\t", s);
}