#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define PI 3.14;

typedef struct tacka
{
	double x;
	double y;
}TACKA;



rastojanjeIzmedjuTacaka(TACKA a, TACKA b) {
	double x1 = a.x;
	double y1 = a.y;

	double x2 = b.x;
	double y2 = b.y;

	double rastojanje;
	rastojanje = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	printf("\nRastojanje izmedju tacke 1 i tacke 2 iznosi: %.2lf", rastojanje);
}

void main() {
	TACKA a1;
	a1.x = 1;
	a1.y = 4;
	printf("%.2lf i %.2lf", a1.x, a1.y);

	TACKA a2;
	a2.x = 9;
	a2.y = 10;
	printf("%.2lf i %.2lf", a1.x, a1.y);

	rastojanjeIzmedjuTacaka(a1, a2);

	


}