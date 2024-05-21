#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zbir_cifara(int broj) {
	int zbir = 0;
	while (broj != 0) {
		int cifra = broj % 10;
	    broj /= 10;

		zbir += cifra;
	}
	return zbir;
}

void parni_trocifreni_zbir_13() {
	int brojac = 0;
	for (int i = 100; i < 1000; i++)
	{
		if (zbir_cifara(i) == 13 && i%2==0) {
			
			brojac++;
			
		}
	}
	printf("Broj parnih trocifrenih brojeva ciji je zbir cifara 13 je jednak: %d", brojac);
}

void zadatak_E() {
	FILE* f100 = fopen("100.txt", "w");
	FILE* f200 = fopen("200.txt", "w");
	FILE* f300 = fopen("300.txt", "w");
	FILE* f400 = fopen("400.txt", "w");
	FILE* f500 = fopen("500.txt", "w");
	FILE* f600 = fopen("600.txt", "w");
	FILE* f700 = fopen("700.txt", "w");
	FILE* f800 = fopen("800.txt", "w");
	FILE* f900 = fopen("900.txt", "w");
    
	int i;

	for ( i = 100; i < 200; i++) {
		if(zbir_cifara(i)==14 && i%2==0)
		fprintf(f100, "%d ;", i);
	}
	for (i = 200; i < 300; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f200, "%d ;", i);
	}
	for (i = 300; i < 400; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f300, "%d ;", i);
	}
	for (i = 400; i < 500; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f400, "%d ;", i);
	}
	for (i = 500; i < 600; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f500, "%d ;", i);
	}
	for (i = 600; i < 700; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f600, "%d ;", i);
	}
	for (i = 700; i < 800; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f700, "%d ;", i);
	}
	for (i = 800; i < 900; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f800, "%d ;", i);
	}
	for (i = 900; i < 1000; i++) {
		if (zbir_cifara(i) == 14 && i % 2 == 0)
			fprintf(f900, "%d ;", i);
	}

	fclose(f100);
	fclose(f200);
	fclose(f300);
	fclose(f400);
	fclose(f500);
	fclose(f600);
	fclose(f700);
	fclose(f800);
	fclose(f900);
	

}

void zadatak_E_nacin2() {
	int i, s;
	FILE* fajl;
	char ime[10];
	for ( s = 100; s <1000; s+=100)
	{
		sprintf(ime, "%d.txt", s);
		fajl = fopen(ime, "w");
		fprintf(fajl, "Brojevi %d.stotine\n", s / 100);
		for(i=s;i<s+100;i++)
			if(zbir_cifara(i)==14 && i%2==0)
			fprintf(fajl, "%d;", i);
		
	}
	fclose(fajl);
}

void procitaj_fajlove() {
	int s, i;
	FILE* fajl;
	char naziv[10];
	char c;
	for ( s = 100; s <= 900; s+=100)
	{
		sprintf(naziv, "%d.txt", s);
		fajl = fopen(naziv, "r");
		if (fajl == NULL) {
			printf("Fajl ne postoji!");
			continue;
		}
	}
	while ((c = fgetc(fajl)) != EOF){
		printf("%c", c);
		
	}
	fclose(fajl);
}

void ispisi_Matricu(int mat[5][5], int m, int n) {
	int i, j;
	for ( i = 0; i <m-1; i++)
	{
		for ( j = 0; j <n-1; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void unesi_matricu(int mat[5][5], int m, int n) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			printf("Unesite [i][j] element matrice: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void zadatak_F(int mat[5][5], int kolona_prve, int kolona_druge) {
	unesi_matricu(mat, 4, 4);
	for (int i = 0; i <4; i++)
	{
		for (int j = 0; j <4; j++)
		{
			printf("%d\t", mat[kolona_prve][kolona_druge]);
		}
	}
}

void unija_kolona(int mat[5][5], int k1, int k2, int niz[], int* n) {
	int i, j;
	*n = 0;
	for (i = 0; i < 5; i++) {
		for ( j = 0; j < 5; j++)
		{
			if ((j == k1 || j == k2)) {
				niz[(*n)++] = mat[i][j];
			}
		}
	}
	for (int s = 0; s <*n; s++)
	{
		printf("%d\t", niz[s]);
	}
}

void main() {
	int niz[15];
	int broj ;
	
	int max=0;
	int n;
	
	/*printf("Unesite broj koji ce predstavljati broj elemenata koji cete uneti:");
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	{
		printf("Unesite %d broj: ", i+1);
		scanf("%d", &broj);

		if (zbir_cifara(broj) > zbir_cifara(max)) {
			max = broj;
		}
	}
	printf("Broj %d ima najveci zbir i on iznosi: %d", max, zbir_cifara(max));
	*/
	//parni_trocifreni_zbir_13();
	//zadatak_E();
	//zadatak_E_nacin2();
	int mat[30][30];
	//zadatak_F(mat, 4, 5);
	//ispisi_Matricu(mat, 5, 5);

	procitaj_fajlove();
}