#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {

	int a;
	int b;
	int c;
	char op;

	printf("Unesite operaciju: \n");
	scanf("%c", &op);

	printf("Unesite broj a:\n");
	scanf("%d", &a);

	printf("Unesite broj b:\n");
	scanf("%d", &b);





	if (op == '+') {
		c = a + b;
		printf("Zbir brojeva a i b je jednak: %d", c);
	}
	if (op == '-') {
		c = a - b;
		printf("Razlika brojeva a i b je jednak: %d", c);
	}
    if (op == '*') {
		c = a * b;
		printf("Proizvod brojeva a i b je jednak: %d", c);
	}
	if (op == '/') {
		float c = a / b;
		printf("Kolicnik brojeva a i b je jednak: %f", c);
	}
	if (op != '+' && op != '-' && op != '*' && op != '/') {
		printf("Uneli ste nepravilnu operaciju!!!");
	}
	
	
}