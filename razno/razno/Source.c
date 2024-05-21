#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
void ispisi_mat(int mat[10][10], int m) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void napravi_matricu_od_niza(int niz[], int n, int mat[10][10]) {
	int m = (int)sqrt(n);
	printf("\nDimenzija matrice:%d\n", m);
	int ch;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				for (int k = n-1; k >=0; k--)
				{
					ch = niz[k];
					niz[k] = mat[i][j];
					mat[i][j] = ch;

				}
				

			}
		}
	
	ispisi_mat(mat, m);
}
void najduzi_podniz_cifara(FILE* fajl) {
	if (fajl == NULL) {
		printf("fajl nije pronadjen!");
		return;
	}
	char s[1000];
	while (fgets(s, 1000, fajl) != NULL) {


		int pocetno_i = 0;
		int max_i;
		int max_duzina = -1;
		int tren_duzina;
		char podniz[100] = "";
		char max_podniz[100];
		int j;
		int duzina_teksta = strlen(s);
		for (int i = 0; i < duzina_teksta; i++)
		{
			tren_duzina = 0;

			while (!(s[i] >= 48 && s[i] <= 57) && s[i]) {
				i++;
			}
			pocetno_i = i;
			j = 0;
			while (s[i] >= '0' && s[i] <= '9' && s[i]) {
				podniz[j] = s[i];
				i++;
				j++;

				tren_duzina++;


			}
			if (tren_duzina > max_duzina) {
				max_duzina = tren_duzina;
				max_i = i;
				strcpy(max_podniz, podniz);
			}

		}
		printf("Najduzi podniz cifara u tekstu |%s| je dugacak %d  i glasi |%s|", s,max_duzina ,max_podniz);

	}
	
}
void izbaci_znak_razmaka(char tekst[],char c) {
	int n = strlen(tekst);
	for (int i = 0; i <n ; i++)
	{
		while (tekst[i] !=c) {
			i++;
		}
		
		for (int j = i; j <n; j++)
		{
			tekst[j] = tekst[j + 1];
			if (tekst[i] == '\0') {
				break;
			}
		}
	}
}
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza su: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
void dodaj_U_niz(int niz[], int* n, int el) {
	niz[(*n)++] = el;
}
void lanac(int niz[], int n) {
	int tmp = niz[0];
	
	for (int i =0; i <n-1 ; i++)
	{
		niz[i] = niz[i + 1];
	}
	niz[n-1] = tmp;
	
}
void ispisi_matricu(int mat[10][10],int m ,int n) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void unesi_niz() {
	int n=0;
	int niz[1000];
	int broj;
	int mat[10][10];
	int br = 0;
	int s = 0;
	do {
		printf("Unesite %d broj u niz: ",  n+1);
		scanf("%d", &broj);
		if(broj!=0)
		dodaj_U_niz(niz, &n, broj);
		br++;
	} while (broj!=0);
	do {
		for (int i = 0; i < br; i++)
		{
			lanac(niz, n);
			for (int j = 0; j < br; j++)
			{
				mat[i][j] = niz[j];
			}
		}
		s++;
	} while (s < br-1);
	ispisi_mat(mat, br-1);
	
}
int najveci_neparni_el_u_koloni(int mat[10][10], int m, int n, int kolona) {
	int max_nepar = 0;
	for (int i = 0; i < n; i++)
	{
		if (mat[i][kolona] % 2 != 0 && mat[i][kolona] > max_nepar) {
			max_nepar = mat[i][kolona];
		}
	}
	return max_nepar;
}
void zadatak1(int mat[10][10], int m, int n){
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0) {
				mat[i][j] = najveci_neparni_el_u_koloni(mat, m, n, j
);
			}
		}
	}
}
int postoji_u_redu(int mat[10][10], int  red, int n, int el) {
	for (int j = 0; j < n; j++)
	{
		if (mat[red][j] == el) {
			return 1;
		}
	}
	return 0;
}
void matrica_sa_tastature() {
	int mat[10][10];
	int m, n;
	printf("Unesite broj redova: ");
	scanf("%d", &m);
	printf("Unesite broj kolona: ");
	scanf("%d", &n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("Unesite [%d][%d] el matrice:",i,j);
			
				scanf("%d", &mat[i][j]);
				if (!postoji_u_redu(mat, i, n, mat[i][j])) {

				}
		}
	}
	ispisi_matricu(mat, m, n);
}
int palindromski_niz(int niz[], int n) {
	for (int i = 0; i < n/2; i++)
	{
	//	printf("%d----%d\n", niz[i], niz[n - i - 1]);
		if (niz[i] != niz[n - i - 1]) {
			return 0;
		}
	}
	return 1;
}
int palindrom(int broj) {
	int niz[100];
	int n = 0;
	while (broj != 0) {
		niz[n++] = broj%10;
		broj /= 10;
	}
	if (palindromski_niz(niz, n)) {
		return 1;
	}
	return 0;
}
void prebaci_u_obod_palindrome(int mat[10][10], int m, int n,char naziv[]) {
	FILE* fajl = fopen(naziv, "r");
	if (fajl == NULL) {
		printf("Greska!!!");
		return;
	}

		for (int j = 0; j < n; j++)
		{
			fscanf(fajl, "%d", &mat[0][j]);
			fscanf(fajl, "%d", &mat[n - 1][j]);
		}
		for (int i = 0; i < m; i++)
		{
			fscanf(fajl, "%d", &mat[i][0]);
			fscanf(fajl, "%d", &mat[i][n-1]);
		}
		ispisi_mat(mat, n);
	fclose(fajl);
}
void main() {
	int niz[] = { 15,1,23,1,15 };
	//printf("Palindromski niz: %d", palindrom(220022));
	int mat[10][10] = { {1,2,3},{4,5,6},{7,8,9} };
	prebaci_u_obod_palindrome(mat, 3, 3, "palindromi.txt");
	
	
}