#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef int BROJ;
typedef char KARAKTER;
typedef int NIZ[200];


struct tacka
{
	double x;
	double y;
};

typedef struct tacka TACKA;
typedef struct trougao{
	TACKA A, B, C;
}TROUGAO;

void zamenaKoordinata(TACKA* tacka) {
	double tmp = tacka->x;
	tacka->x = tacka->y;
	tacka->y = tmp;

}

void main() {
	//printf("Stef kari");
	struct tacka t1;
	t1.x = 8;
	t1.y = 9;
	printf("Kordinate tacke t1 su x:%.2lf i y:%.2lf\n", t1.x, t1.y);

	struct tacka t2 = { 3.5,6 };
	printf("Kordinate tacke t2 su x:%.2lf i y:%.2lf\n", t2.x, t2.y);

	BROJ sedmica = 7;
	KARAKTER sedmoSlovo = 'e';
	printf("Broj sedam se pise: %d, a sedmo slovo azbuke je: %c\n",sedmica,sedmoSlovo);
    
	NIZ brojevi;
	brojevi[0] = 18;
	printf("Prvi element niza brojevi je: %d\n",brojevi[0]);

	TACKA t3 = { 15,18.8 };
    
	TROUGAO pravougli;
	pravougli.A = t1;
	pravougli.B = t2;
	pravougli.C = t3;

	TROUGAO* ptr = &pravougli;
	(*ptr).A.x = 1800;
	ptr->A.x = 1900;

	TACKA s = { 2.4,6.5 };
	printf("s: %.2lf i %.2lf\n", s.x, s.y);
	zamenaKoordinata(&s);
	printf("Koordinate tacke s nakon zamene: %.2lf i %.2lf\n", s.x, s.y);
 
	printf("%.2lf i %.2lf", s.x, s.y);

}