#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

typedef int BROJ;
typedef int NIZ[200];


struct tacka
{
	double x;
	double y;
};
typedef struct tacka TACKA;
typedef struct trougao {
	TACKA A, B, C;
}TROUGAO;

void zameni_koordinate(TACKA* t) {
	double c;
	c=t->x;
	t->x = t->y;
	t->y = c;

}

double rastojanje_izm_dve_tacke(TACKA A, TACKA B) {
	double d;
	d = sqrt(pow((B.x - A.x),2)+ pow((B.y - A.y), 2));
	return d;
}

double obim_trougla(TROUGAO t) {
	double strA = rastojanje_izm_dve_tacke(t.A, t.B);
	double strB = rastojanje_izm_dve_tacke(t.B, t.C);
	double strC= rastojanje_izm_dve_tacke(t.A, t.C);
	return strA + strB + strC;
}

void main() {
	struct tacka t1;
	t1.x = 3;
	t1.y = t1.x + 2;

	struct tacka t2 = { 3.5,0 };

	BROJ a = 4;
	NIZ brojevi = { 200,400,6000,40,10 };
	brojevi[0] = 12;

	TACKA t3= { 2,-6.94 };

	TROUGAO tr;
	tr.A = t1;
	tr.B = t2;
	tr.C = t3;
	tr.A.y++;
	tr.C.x = tr.B.x-2.88;

	TROUGAO* ptr = &tr;
	(*ptr).A.x = 5;//isto sto i ptr->A.x=5;
	


	printf("Koordinate tacke t1 pre zamene su x=%.2lf i y=%.2lf\n" , t1.x,t1.y);
	zameni_koordinate(&t1);
	printf("Koordinate tacke t1 posle zamene su x=%.2lf i y=%.2lf\n", t1.x, t1.y);

	TACKA s1 = {2,3};
	TACKA s2 = {5,7};
	printf("Rastojanje izmedju tacke t1 i tacke t2 je %.2lf\n",rastojanje_izm_dve_tacke(s1,s2));

	printf("Obim trougla tr je: %.2lf\n", obim_trougla(tr));
}