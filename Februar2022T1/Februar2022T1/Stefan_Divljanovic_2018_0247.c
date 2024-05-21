#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct potez {
	int x;
	int y;
	int brojZnaka; //1 је икс, 0 је окс
} POTEZ;
typedef struct cvor CVOR;
typedef CVOR* PCVOR;
struct cvor
{
	POTEZ info;
	PCVOR sledeci;
};

int daLiPostoji(POTEZ p, PCVOR lista) {
	PCVOR pom = lista;
	while (pom != NULL) {
		if (pom->info.x==p.x &&  pom->info.y==p.y) {
			return 1;
		}
		pom = pom->sledeci;
	}
	return 0;
}
int dodajUListu(POTEZ potez, PCVOR * lista) {
	PCVOR novi = (PCVOR)malloc(sizeof(CVOR));
	if (*lista == NULL) {
		novi->info = potez;
		novi->sledeci = *lista;
		*lista = novi;
		return 1;
	}
	PCVOR pom = *lista;
	while (pom->sledeci != NULL) {
		pom = pom->sledeci;
	}
	novi->info = potez;
	novi->sledeci = NULL;
	pom->sledeci = novi;
	return 1;
}
int dodajPotez(POTEZ potez, PCVOR * lista) {
	if (!daLiPostoji(potez, *lista)) {
		dodajUListu(potez, lista);
		return 1;
	}
	
	return 0;
}
void prebaciUMatricu(PCVOR lista, int matrica[5][5], int m) {
	PCVOR pom = lista;
	while (pom != NULL) {
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i == pom->info.x && j == pom->info.y) {
					matrica[i][j] = pom->info.brojZnaka;
				}
				if (matrica[i][j] != 0 && matrica[i][j] != 1) {
					matrica[i][j] = -1;
				}
			}
		}
		pom = pom->sledeci;
	}
}
void ispisi_listu(PCVOR lista) {
	PCVOR pom = lista;
	int i = 1;
	while (pom != NULL) {
		printf("%d. x= %d y= %d potez= %d\n",i, pom->info.x, pom->info.y, pom->info.brojZnaka);
		pom = pom->sledeci;
		i++;
	}
}
void ispisi_matricu(int mat[5][5], int m) {
	printf("\nElementi matrice:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}
int jednaka_kolona(int mat[5][5],int m ,int kolona, int brojZnaka) {
	for (int i = 0; i < m; i++)
	{
		if (mat[i][kolona]!=brojZnaka) {
			return 0;
		}
		
	}
	return 1;
}
int jednak_red(int mat[5][5], int m, int red, int brojZnaka) {
	for (int j = 0; j < m; j++)
	{
		if (mat[red][j] != brojZnaka) {
			return 0;
		}

	}
	return 1;
}
int jednaka_dijagonala(int mat[5][5], int m, int brojZnaka) {
	for (int i = 0; i < m; i++)
	{
		for (int j  = 0;  j< m; j++)
		{
			if (i == j) {
				if (mat[i][j] != brojZnaka) {
					return 0;
				}
			}
		}
	}
	return 1;
}
int jednaka_sporedna(int mat[5][5], int m, int brojZnaka) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + j==m-1) {
				if (mat[i][j] != brojZnaka) {
					return 0;
				}
			}
		}
	}
	return 1;
}
int pobednickiNiz(int mat[5][5], int m, int brojZnaka) {
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (jednaka_dijagonala(mat, m, brojZnaka) || jednaka_sporedna(mat, m, brojZnaka) || jednaka_kolona(mat, m, j, brojZnaka)
				|| jednak_red(mat, m, i, brojZnaka)) {
				return 1;
			}
		}
	}
	return 0;
}
void pokreniIgru(PCVOR * lista, int dimenzije) {
	int x, y,brojZnaka;
	printf("X unesite potez");
	brojZnaka = 1;
	scanf("%d %d", &x, &y);
	POTEZ p;
	p.x = x;
	p.y = y;
	p.brojZnaka = brojZnaka;
	dodajPotez(p, lista);
	if (dodajPotez(p, lista) == 0) {
		printf("Potez nije unet!!!");
	}
	else {
		printf("Potez je uspesno unet!!!");
	}
	printf("O unesite potez");
	brojZnaka = 0;
	scanf("%d %d", &x, &y);
	POTEZ o;
	o.x = x;
	o.y = y;
	o.brojZnaka = brojZnaka;
	dodajPotez(p, lista);
	if (dodajPotez(o, lista) == 0) {
		printf("Potez nije unet!!!");
	}
	else {
		printf("Potez je uspesno unet!!!");
	}

}
void meni() {
	printf("#########################\n");
	printf("Student: ");
	printf("#########################\n");
	
		int br;
		scanf("%d", &br);
		switch (br)
		{
		case(1): {
			
			break;
			getchar();
		}
		case(2): {
			
			break;
		}
		case(3): {
			printf("Burek sa sirom!");
			break;
		}
		case(4): {
			printf("Burek sa sirom!");
			break;
		}case(0): {

			break;
		}
		default:
			break;
		}
}
void main() {
	meni();

}