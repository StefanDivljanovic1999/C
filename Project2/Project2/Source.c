#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int a;
	int b;
	char operaciju;
	float rez;

	printf("Unesite operaciju:");
	scanf("%c", &operaciju);

	printf("Unesite broj a: \n");
	scanf("%d", &a);

	printf("Unesite broj b: \n");
	scanf("%d", &b);


	switch (operaciju)
	{
	case '+':
		rez = a + b;
		printf("Rezultat nakon sabiranja broja %d i broja %d je: \n %f", a, b, rez);
		break;
	case '-':
		rez = a - b;
		printf("Rezultat nakon oduzimanja broja %d i broja %d je: \n %f", a, b, rez);
		break;
	case '*':
		rez = a * b;
		printf("Rezultat nakon mnozenja broja %d i broja %d je: \n %f", a, b, rez);
		break;
	case '/':
		rez = (float) a / b;
		printf("Rezultat nakon deljenja broja %d i broja %d je: \n %f", a, b, rez);
		break;
	default: printf("Uneli ste operaciju u nepravilnom formatu!!!");


	}
}
	

