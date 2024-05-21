#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int br_redova(char* naziv) {
	int br = 0;
	FILE* fajl = fopen(naziv, "r");
	char s[1000];
	while (fgets(s, 1000, fajl) != NULL) {
		br++;
	}
	fclose(fajl);
	return br;
}

void procitaj_datoteku(char * naziv, int info[][4], int *n){
	FILE* fajl = fopen(naziv,"r");
	*n = br_redova(naziv);
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fscanf(fajl, "%d", &info[i][j]);
		}
	}

fclose(fajl);
	}
void ispis(int info[4][4], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d\t", info[i][j]);
		}
		printf("\n");
	}
}
int fun(int n) {
	if (n >= 1) {
		return n * fun(n - 1);
	}
	else {
		return 1;
	}
}

void main() {
	printf("%d", 234 % 10);
}