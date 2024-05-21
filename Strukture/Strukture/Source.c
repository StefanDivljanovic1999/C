#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void jelka() {
	int i, j, k;
	int brEl = 5;

	for (i = 1; i <= brEl; i++)
	{
		for (j = 0; j <= brEl - i; j++)
		{
			printf(" ");
		}
		for (k = 0; k < i; k++)
		{
			printf("* ");
		}

		printf("\n");
	}
}

void pravougli()
{
	int n;
	printf("Unesite broj elemenata: \n");
	scanf("%d", &n);

	int i, k;



}
void suprotniPravougli() {
	int n;
	printf("Unesite br. elemenata: \n");
	scanf("%d", &n);
	int i, j, k;
	
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= n - i; j++) { printf(" ");
	}
		for (k = 0; k < i; k++)  printf("*");
		
		

		printf("\n");
	}


}
void neparniTrougao() {
	printf("Unesite broj elemenata:\n");
	int n, i, j, k;
	scanf("%d", &n);
	for ( i = 0; i <n; i++)
	{
		
		for (j = 0; j <= n-i; j++)
		{
			printf("  ");
		}
		
		
		for ( k = 1; k <= 2*i+1; k++)
		{
			printf(" *");
			
		}


		

		printf("\n");
	}
}
void plesanje() {
	printf("Unesite broj elemenata:\n");
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i = i + 1) {
		if (i %2!= 0) 
			printf(" ");
			for (j = 0; j < n; j++)
			
				printf("* ");
			
		
		

		printf("\n");
	}

}
void okvir(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {

		for (j = 1; j <= n; j++) {
			if(i==1 || i==n)
			printf("*");
			else {
				if (j == 1 || j == n) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
}
void obrnutiPravougli(int n) {
	int i, j, k;
	for (i = 0; i <n; i++) {

		/*for ( j = 0; j < n; j++)
		{
			printf(" ");
		}*/
		for (k = 1; k <= n - i; k++) {
			printf("*");
		}


		printf("\n");
	}
}
void obrnuti2(int n) {
	int i, j, k;
	for (i = 0; i < n; i++) {

		for ( j=0;j<=i;j++)
		{
			printf(" ");
		}
		for (k = 1; k <= n - i; k++) {
			printf("*");
		}


		printf("\n");
	}
}
void obrnutaJelka(int n) {
	int i, j, k;

	for ( i = 1; i <= n; i++)
	{
		for ( j =1; j<=n-i; j++)
		{


		printf("5");

		}
		for ( k = 1; k<=2*n-1; k++)
		{
			printf("*");
		}



		printf("\n");
	}
}
void main() {
	//pravougli();
	//suprotniPravougli();
	//neparniTrougao();
	//plesanje();
	//okvir(7);3
	//obrnuti2(4);
	obrnutaJelka(4);
}