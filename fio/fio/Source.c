#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void skrati_za_jedan(char s[]) {
	s[strlen(s) - 1] = '\0';
}

void main() {
	char s[100];
	puts("Unesi tekst:");
	fgets(s, 100, stdin);
	//gets(s);
	skrati_za_jedan(s);
	//puts(s);
	sprintf(s, "%s.", s);
	puts(s);
}