#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct reprezentacija {
	char sifra[100];
	char naziv[100];
	int br_odigranih;
	int br_pobeda;
	int br_neresenih;
	int br_poraza;
	int br_poena;
}REPREZENTACIJA;
typedef struct utakmica {
	REPREZENTACIJA gost;
	REPREZENTACIJA domacin;
	int br_golova_gost;
	int br_golova_domacin;
}UTAKMICA;
typedef struct cvor {
	int p;
	 struct cvor* sledeci;
}CVOR;
typedef CVOR* PCVOR;

void ispisi_niz(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int broj_ponavljanja(int niz[], int n, int broj) {
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == broj) {
			brojac++;
		}
	}
	return brojac;
}
int cifre(int broj) {
	int cifra[100];
	int n = 0;
	while (broj != 0) {
		cifra[n++] = broj % 10;
		broj /= 10;
	}
	for (int i = 0; i < n; i++)
	{
		if (broj_ponavljanja(cifra, n, cifra[i]) > 1) {
			return 0;
		}
	}
	return 1;
}
void zadatak2() {
	FILE* fajl = fopen("divota.txt", "w");
	int broj1, broj2;
	printf("Unesite interval:");
	char s[1000];
	scanf("%d %d", &broj1, &broj2);
	for (int i = broj1; i <broj2; i++)
	{
		if (cifre(i) == 1) {
			sprintf(s, "%d\n", i);
			fputs(s, fajl);
		}
	}
	fclose(fajl);
}
void dodaj_u_tekst(char niz[], int* n, char c) {
	niz[(*n)++] = c;
}
int postoji_u_tekstu(char tekst[], char c) {
	for (int i = 0; tekst[i]!='\0'; i++)
	{
		if (tekst[i] == c) {
			return 1;
		}
	}
	return 0;
}
void ispisi_tekst(char kompres[]) {
	for (int i = 0; kompres[i] != '\0'; i++)
	{
		printf("%c\t", kompres[i]);
	}
}
void kompresija(char tekst[],char kompres[],int* n) {
	int brojac = 0;
	
	for (int i = 0; tekst[i]!='\0'; i++)
	{
		if (tekst[i]==tekst[i+1] && tekst[i]==tekst[i+2]) {
			
				
			
		}
	}
	

}
void ispisi_matricu(int mat[10][20], int m1, int n1) {
	printf("Elementi matrice su:\n");
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
void proizvod_matrica(int mat1[10][20],int m1,int n1 ,int mat2[10][20],int m2,int n2, int mat3[10][20]) {
	
	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			mat3[i][j] = 0;
			for (int k = 0; k < n2; k++)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	ispisi_matricu(mat3, n1, m2);
	
}
void ucitaj_matrice(int mat1[10][20],int mat2[10][20], int mat3[10][20]) {
	FILE* fajl1 = fopen("matrica1.txt", "r");
	FILE* fajl2 = fopen("matrica2.txt", "r");

	int m1, n1, m2, n2;

	fscanf(fajl1, "%d %d", &m1, &n1);
	printf("%d %d\n", m1, n1);

	fscanf(fajl2, "%d %d", &m2, &n2);
	printf("%d %d\n", m2, n2);

	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			fscanf(fajl1, "%d", &mat1[i][j]);
			
		}
		printf("\n");
	}
	ispisi_matricu(mat1, m1, n1);
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			fscanf(fajl2, "%d", &mat2[i][j]);
			
		}
		printf("\n");
	}
	ispisi_matricu(mat2, m2, n2);
	proizvod_matrica(mat1, n1, m1, mat2, n2, m2, mat3);
	
	fclose(fajl1);
	fclose(fajl2);
}
int postoji_repr(REPREZENTACIJA r[], int n, REPREZENTACIJA r1) {
	for (int i = 0; i < n; i++)
	{
		if (strcmp(r[i].sifra, r1.sifra) == 0) {
			return 1;
		}
	}
	return 0;
}
void dodaj_reprezentaciju(REPREZENTACIJA niz_r[], int* n, REPREZENTACIJA r) {
	if (!postoji_repr(niz_r, *n, r)) {
		niz_r[(*n)++] = r;
	}
	else {
		printf("Reprezentacija sa ovom sifrom vec postoji u nizu reprezentacija!!!");
		return;
	}
}
void ispisi_reprezentaciju(REPREZENTACIJA r) {
	printf("Naziv: %s\n", r.naziv);
	printf("Sifra: %s\n", r.sifra);
	printf("Broj odigranih utakmica: %d\n", r.br_odigranih);
	printf("Broj pobeda: %d\n", r.br_pobeda);
	printf("Broj neresenih: %d\n", r.br_neresenih);
	printf("Broj poraza: %d\n", r.br_poraza);
}
void ispisi_niz_repr(REPREZENTACIJA r[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", i+1);
		ispisi_reprezentaciju(r[i]);
	}
}

/*void dodaj_utakmicu(UTAKMICA u, PCVOR* pglava,REPREZENTACIJA r[1000], int n) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	PCVOR pom = *pglava;
	if (!postoji_repr(r, n, u.domacin) || !postoji_repr(r, n, u.gost) || strcmp(u.domacin.sifra,u.gost.sifra)==0) {
		printf("Ovakva utakmica ne moze da se odigra!!!");
		return;
	}
	if (postoji_utakmica(*pglava, u)) {
		printf("Ova utakmica je vec odigrana!!!");
		return;
	}
	if ((u).br_golova_domacin < 0 || (u).br_golova_gost < 0) {
		printf("Broj golova mora biti bar 0!");
		return;
	}
	if (*pglava == NULL) {
		novi->u = u;
		novi->sledeci = *pglava;
		*pglava = novi;
		return;
	}
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	pom->sledeci = novi;
	
	novi->u =u;
	
	novi->sledeci = NULL;
	
	REPREZENTACIJA d = u.domacin;
	REPREZENTACIJA g = u.gost;

	d.br_odigranih++;
	g.br_odigranih++;

	if (u.br_golova_domacin > u.br_golova_gost) {
		d.br_pobeda++;
		d.br_poena += 3;
		g.br_poraza++;
	}
	else if (u.br_golova_domacin == u.br_golova_gost) {
		g.br_neresenih++;
		d.br_neresenih++;
		g.br_poena += 1;
		d.br_poena += 1;
	}
	else {
		g.br_pobeda++;
		g.br_poena += 3;
		d.br_poraza++;
	}
	//novi->u.domacin = d;
	//novi->u.gost = g;
	
	for (int i = 0; i < n; i++)
	{
		if (strcmp(r[i].sifra, g.sifra) == 0) {
			r[i] = g;
		}
		else if (strcmp(r[i].sifra, d.sifra) == 0) {
			r[i] = d;
		}
	}

}*/
void ispisi_utakmicu(UTAKMICA u) {
	printf("Reprezentacija domacin: %s\n", u.domacin.naziv);
	printf("Reprezentacija gost: %s\n", u.gost.naziv);
	printf("Broj golova domacin: %d\n", u.br_golova_domacin);
	printf("Broj golova gost: %d\n", u.br_golova_gost);
}
void ispisi_niz_utakmica(UTAKMICA u[], int n) {
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",i+1);
		ispisi_utakmicu(u[i]);
	}
}
void septembar2017_1(char tekst[1000]) {
	FILE* fajl = fopen("ulaz.txt", "r");
	
	char T_najduzi_podniz[1000];
	char max_podniz[1000];
	int tekuci_i;
	int t_duzina;
	int max_duzina = -1;
	int pocetni_index;
	if (fajl == NULL) {
		printf("Fajl nije pronadjen!!!");
		return;
	}
	

		for (int i = 0; tekst[i] != '\0'; i++)
		{


			while (!(tekst[i] >= 48 && tekst[i] <= 57) && tekst[i]) {
				i++;
			}
			t_duzina = 0;
			tekuci_i = i;
			pocetni_index = tekuci_i;
			while (tekst[i] >= 48 && tekst[i] <= 57 && tekst[i]) {
				T_najduzi_podniz[tekuci_i++] = tekst[i++];
				t_duzina++;
			}
		}
		if (t_duzina > max_duzina) {
			max_duzina = t_duzina;
			strcpy(max_podniz, T_najduzi_podniz);
		}

		printf("%d i %d", tekuci_i, max_duzina);
	

}
void najduzi_podstring_cifara(char tekst[]) {
	
	FILE* fajl = fopen("ulaz.txt", "r");
	char s[1000];
	int t_duzina;
	int t_index=0;
	int max_index;
	int j;
	int max_duzina=-5;
	char tekuci[1000];
	char max_podniz[1000];
	if (fajl == NULL) {
		printf("Fajl nije pronadjen!!!");
		return;
	}
	while (fgets(s, 1000, fajl) != NULL) {
		
		for (int i = 0; s[i] != '\0'; i++) {
			t_duzina = 0;
			
			while (!(s[i] >= '0' && s[i] <= '9') && tekst[i]) {
				i++;
			}
			t_index = i;
			
			
			j = 0;
			while ((s[i] >= '0' && s[i] <= '9') && tekst[i]) {
				
				t_duzina++;
				tekuci[j++] = tekst[i++];
			}
			if (t_duzina > max_duzina) {
				max_duzina = t_duzina;
				max_index = t_index;
				strcpy(max_podniz, tekuci);
			}
		}
	
	}
	
	for (int i =j; i < max_duzina; i++)
	{
		printf("%c", max_podniz[i]);
	}
	
	fclose(fajl);
}
int prost(int broj) {
	int brojac = 0;
	for (int i = 1; i <= broj; i++)
	{
		if (broj%i == 0) {
			brojac++;
		}
	}
	if (brojac <= 2) {
		return 1;
	}
	return 0;
}
void prosti_dijagonale(int mat[10][20], int n) {
	int prosti_glavna = 0;
	int prosti_sporedna = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j && prost(mat[i][j])) {
				prosti_glavna++;
			}
			if (i + j == n-1 && prost(mat[i][j])) {
				prosti_sporedna++;
			}
		}
	}
	printf("Broj prostih elemenata na glavnoj dijagonali je: %d\n", prosti_glavna);
	printf("Broj prostih elemenata na sporednoj dijagonali je: %d\n", prosti_sporedna);
}
int suma_kolone(int mat[10][20], int n, int kolona) {
	int suma = 0;
	for (int j = 0; j < n; j++)
	{
		suma += mat[kolona][j];
	}
	return suma;
}
void kolona_sa_max_el(int mat[10][20], int n) {
	
	int suma_kolone1;
	int max_suma = mat[0][0];
	
	for (int i = 0; i < n; i++)
	{
		suma_kolone1 = 0;
		for (int j = 0; j < n; j++)
		{
			suma_kolone1 += mat[i][j];
		}


		if (suma_kolone1 > max_suma) {
			max_suma = suma_kolone1;
		}
	}
	printf("Max suma kolone je: %d\n", max_suma);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (suma_kolone(mat, n, i) == max_suma) {
				
				printf("%d\t", mat[i][j]);
			}
		}
	}
}
int postoji_na_glavnoj(int mat[10][20], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j && mat[i][j] == el) {
				return 1;
			}
		}
	}
	return 0;
}
int postoji_na_sporednoj(int mat[10][20], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == n - 1 && mat[i][j] == el) {
				return 1;
			}
		}
	}
	return 0;
}
void ispisi_listu(PCVOR glava) {
	PCVOR pom = glava;
	printf("Elementi liste su:\n");
	while (pom != NULL) {
		printf("%d\t", pom->p);
		pom = pom->sledeci;
	}
}
int postoji_u_listi(PCVOR glava, int el) {
	PCVOR pom = glava;
	
	while (pom != NULL) {
		if (pom->p == el) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}
void dodaj_na_pocetak(PCVOR* pglava, int el) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	novi->p =el;
	novi->sledeci = *pglava;
	*pglava = novi;
}
void lista_od_el_glavne_sporedne(int mat[10][20], int n, PCVOR* pglava) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (postoji_na_glavnoj(mat, n, mat[i][j]) && postoji_na_sporednoj(mat, n, mat[i][j]) && !postoji_u_listi(*pglava,mat[i][j])) {
				dodaj_na_pocetak(pglava, mat[i][j]);
				
				
			}
		}
	}
	//ispisi_listu(pglava);
}


void main() {
	int mat[10][20] = { {1,2,5,2},{3,2,6,7},{6,5,0,3},{1,4,7,6} };
	ispisi_matricu(mat, 4, 4);
	prosti_dijagonale(mat, 4);
	kolona_sa_max_el(mat, 4);
	printf("\n%d", postoji_na_sporednoj(mat,4,1));
	PCVOR glava = NULL;
	lista_od_el_glavne_sporedne(mat, 4, &glava);
	
	ispisi_listu(glava);
}