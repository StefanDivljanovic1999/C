#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reprezentacija {
	int sifra;
	char naziv[100];
	int odigrano;
	int pobede;
	int nereseno;
	int porazi;
	int poeni;
}REPREZENTACIJA;
typedef struct utakmica {
	REPREZENTACIJA domacin;
	REPREZENTACIJA gost;
	int gol_domaci;
	int gol_gosti;

}UTAKMICA;
typedef struct cvor* PCVOR;
typedef struct cvor {
	UTAKMICA u;
	struct cvor* sledeci;
}CVOR;

void ispisi_matricu(int mat[10][10], int m, int n) {
	printf("\nElementi matrice su: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}

}
void proizvod_matrica(int mat1[10][10], int m1, int n1, int mat2[10][10], int m2, int n2, int mat3[10][10]) {
	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			mat3[i][j] = 0;
			for (int k = 0; k < n1; k++)
			{
				mat3[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}
void ucitaj_matrice(int mat1[10][10], int mat2[10][10]) {
	
	FILE* fajl1 = fopen("matrica1.txt", "r");
	FILE* fajl2 = fopen("matrica2.txt", "r");
	if (fajl1 == NULL || fajl2 == NULL) {
		printf("Jedan od fajlova nije pronadjen!!!");
		return;
	}

	int m1, n1, m2, n2;
	fscanf(fajl1, "%d %d", &m1, &n1);
	fscanf(fajl2, "%d %d", &m2, &n2);

	printf("m1=%d, n1=%d, m2=%d, n2=%d", m1, n1, m2, n2);

	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			fscanf(fajl1, "%d", &mat1[i][j]);
		}
	}

	for (int i = 0; i < m2; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			fscanf(fajl2, "%d", &mat2[i][j]);
		}
	}
	ispisi_matricu(mat1, m1, n1);
	ispisi_matricu(mat2, m2, n2);
	int mat3[10][10];
	proizvod_matrica(mat1, m1, n1, mat2, m2, n2, mat3);
	ispisi_matricu(mat3, m1, n2);
	fclose(fajl1);
	fclose(fajl2);
}
void ispisi_utakmicu(UTAKMICA u) {
	printf("%s vs. %s\n", u.domacin.naziv,u.gost.naziv);
	printf("%d:%d\n", u.gol_domaci, u.gol_gosti);
}
void dodaj_u_niz_repr(REPREZENTACIJA niz[], REPREZENTACIJA r1, int* n) {
	niz[(*n)++] = r1;
}
void ispisi_rep(REPREZENTACIJA r) {
	printf("(%d) %s , (odigranih)=|%d|  (pobeda)=|%d|  (neresenih)=|%d|  (poraza)=|%d|\n", r.sifra, r.naziv, r.odigrano, r.pobede, r.nereseno, r.porazi);
}
void niz_repr(REPREZENTACIJA niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		ispisi_rep(niz[i]);

	}
}
int postoji_repr(REPREZENTACIJA niz[], int n, REPREZENTACIJA r) {
	for (int i = 0; i <n; i++)
	{
		if (strcmp(niz[i].naziv,r.naziv),niz[i].sifra==r.sifra) {
			return 1;
		}
	}
	return 0;
}
int postoji_utakmica(UTAKMICA u, PCVOR glava) {
	PCVOR pom = glava;
	while (pom != NULL) {
		if (strcpy(pom->u.domacin.naziv, u.domacin.naziv) == 0 && strcpy(pom->u.gost.naziv, u.gost.naziv) == 0) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}
void unesi_utakmicu(UTAKMICA u, PCVOR* pglava, REPREZENTACIJA r[],int* n) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (!postoji_repr(r, *n, u.domacin) || !postoji_repr(r, *n, u.gost)) {
		printf("Jedna od reprezentcija nije clan FIFA!");
		return;
	}
	if (postoji_utakmica(u, *pglava) == 1) {
		printf("Utakmica je vec odigrana!");
		return;
	}
	if (u.gol_domaci < 0 || u.gol_gosti < 0) {
		printf("Broj golova mora biti bar 0!");
		return;
	}
	
	if (*pglava == NULL) {
		novi->u = u;
		novi->sledeci = *pglava;
		*pglava = novi;
		REPREZENTACIJA d = u.domacin;
		REPREZENTACIJA g = u.gost;
		d.odigrano++;
		g.odigrano;
		if (u.gol_domaci > u.gol_gosti) {
			d.pobede++;
			d.poeni += 3;
			g.porazi++;
		}
		else if (u.gol_domaci == u.gol_gosti) {
			d.nereseno++;
			d.poeni += 1;
			g.nereseno++;
			g.poeni += 1;
		}
		else {
			g.pobede++;
			g.poeni += 3;
			d.porazi++;
		}
		u.domacin = d;
		u.gost = g;
		dodaj_u_niz_repr(r, u.domacin, n);
		dodaj_u_niz_repr(r, u.gost, n);
		return;
	}
	PCVOR pom = *pglava;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	novi->u = u;
	novi->sledeci = NULL;
	pom->sledeci = novi;

	REPREZENTACIJA d = u.domacin;
	REPREZENTACIJA g = u.gost;
	
	d.odigrano++;
	g.odigrano;
	if (u.gol_domaci > u.gol_gosti) {
		d.pobede++;
		d.poeni += 3;
		g.porazi++;
	}
	else if (u.gol_domaci == u.gol_gosti) {
		d.nereseno++;
		d.poeni += 1;
		g.nereseno++;
		g.poeni += 1;
	}
	else {
		g.pobede++;
		g.poeni += 3;
		d.porazi++;
	}
	u.domacin.pobede=d.pobede;
	u.domacin.poeni = d.poeni;
	u.domacin.porazi = d.porazi;
	u.domacin.nereseno = d.nereseno;
	
}

void main() {
	REPREZENTACIJA niz[350];
	int n = 0;
	PCVOR glava = NULL;
	REPREZENTACIJA r1 = { 381,"SRBIJA",624,417,53,624 - 417 - 53 };
	REPREZENTACIJA r2 = { 382,"CRNA GORA",321,108,51,321 - 108 - 51 };
	REPREZENTACIJA r3 = { 1,"ARGENTINA",754,622,75,754 - 622 - 75 };
	REPREZENTACIJA r4 = { 2,"FRANCUSKA",712,514,103,712 - 514- 103 };
	dodaj_u_niz_repr(niz, r1, &n);
	dodaj_u_niz_repr(niz, r2, &n);
	dodaj_u_niz_repr(niz, r3, &n);
	dodaj_u_niz_repr(niz, r4, &n);
	niz_repr(niz, n);
	UTAKMICA u1 = { r1,r3,4,3 };
	unesi_utakmicu(u1, &glava, niz, &n);
	ispisi_utakmicu(u1);
	niz_repr(niz, n);
}