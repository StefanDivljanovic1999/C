#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zbir(int x, int y) {
	int z = x + y;
	printf("%d+%d=%d\n", x, y, z);
}
void uvecaj(int* a) {
	(*a)++;
	//printf("%d",a);
}
void igranje_sa_pokazivacima() {
	int a=0;
	int* pa = &a;
	a++;
	printf("a=%d\t&a=%p\n*pa=%d\t&pa=%p", a, &pa,*pa,&pa);
}
void zameni_mesta(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}
void najveci_broj() {
	int a, b, c;
	printf("Unesite broja a: ");
	scanf("%d", &a);
	printf("Unesite broj b: ");
	scanf("%d", &b);
	printf("Unesite broj c: ");
	scanf("%d", &c);
	int max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}
	printf("Najveci broj je: %d", max);
}
void digitron() {
	printf("Unesite broj a: ");
	int a, b;
	scanf("%d", &a);
	printf("Unesite broj b: ");
	scanf("%d", &b);
	printf("Unesite operaciju: ");
	char op;
	scanf("\n%c", &op);
	switch (op)
	{
	case '+':
		printf("Rezultat je: %d", a + b);
		break;
	case '-':
		printf("Rezultat je: %d", a - b);
		break;
	case '/':
		printf("Rezultat je: %.2lf",(double)a / b);
		break;
	case '*':
		printf("Rezultat je: %d", a * b);
		break;
	default: printf("Pogresna operacija");
		break;
	}


}
void suma_jednocifrenih() {
	int suma = 0;
	for (int i = 0; i < 10; i++)
	{
		suma += i;
	}
	printf("Suma jednocifrenih brojeva je: %d", suma);
}
void suma_jednocifrenih_dw() {
	int i = 0;
	int suma = 0;
	do {
		i++;
		suma += i;
	} while (i != 10);
	printf("Suma jednocifrenih je: %d", suma);
}
void suma_cifrara_deljiva_sa_tri() {
	int a, b;
	do {
		printf("Unesite donju granicu intervala: ");
		scanf("%d", &a);
		printf("Unesite gornju granicu intervala: ");
		scanf("%d", &b);
	} while (a > b);
	for (int i = a; i <=b; i++)
	{
		if (suma_cifara(i) % 3 ==  0) {
			printf("%d\t", i);
		}
	}
}
int suma_cifara(int br) {
	int suma = 0;
	int cifra = br;
	while (br > 0) {
		cifra = br % 10;
		suma += cifra;
		br = br / 10;
	}
	return suma;
}
void unosi_dok_je_aritmeticki() {
	int a, b, d;
	printf("Unesite razliku niza: ");
	scanf("%d", &d);
	do {
		printf("Unesite neki broj: ");
		
		scanf("%d %d", &a,&b);
		
		
	} while (b - a == d);
}
int prost(int br) {
	int brojac = 0;
	for (int i = 1; i <= br; i++)
	{
		if (br%i == 0) {
			brojac++;
		}
	}
	if (brojac == 2) {
		return 1;
	}
	return 0;
}
void ispisi_proste_u_intervalu() {
	int a, b;
	do {
		printf("Unesite donju granicu intervala: ");
		scanf("%d", &a);

		printf("Unesite gornju granicu intervala: ");
		scanf("%d", &b);
	} while (a > b);
	for (int i = a; i <=b; i++)
	{
		if (prost(i) == 1) {
			printf("%d\t", i);
		}
	}
}
int jedinica_jednaka_9(int br) {

	if (br % 10 == 9) {
		return 1;
	}
	return 0;

}
void interval2() {
	int a, b;
	int suma = 0;
	do {
		printf("Unesite donju granicu intervala: ");
		scanf("%d", &a);

		printf("Unesite gornju granicu intervala: ");
		scanf("%d", &b);
	} while (a > b);
	for (int i = a; i <= b; i++)
	{
		if (jedinica_jednaka_9(i) == 1) {
			suma += i;
		}
	}
	printf("Suma brojeva iz intervala je: %d", suma);

}
void zvezdice(int n) {
	for (int i = 0; i < n; i++)
	{
		



		for (int j = 0; j <=i; j++)
		{
			printf(" 1 ");
		}
		
	
		printf("\n");
		}
}

int main() {
	//najveci_broj();
	//digitron();
	//suma_jednocifrenih();
	//suma_jednocifrenih_dw();
	//suma_cifrara_deljiva_sa_tri();
	//ispisi_proste_u_intervalu();
	//interval2();
	zvezdice(5);
}

