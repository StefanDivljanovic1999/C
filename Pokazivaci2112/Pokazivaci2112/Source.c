#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void zbir(x, y) {
	int z = x + y;
	printf("%d + %d = %d", x, y, z);
}

void uvecaj(int* broj) {
	*broj=*broj+1;
	//printf("%d", broj);
}
void uvecajDaRadi(int* broj) {

}

void igranjeSaPokazivacima() {
	int a = 0;
	int* pa = &a;


}
void zamenaMesta(int *x, int *y) {
	
	
	printf("Brojevi nakon funkcije (zamenaMesta) imaju vrednost:\n a=%d i b=%d\n", *x, *y);
	int z = *x;
	*x = *y;
	*y = z;
	printf("Brojevi nakon funkcije (zamenaMesta) imaju vrednost:\n a=%d i b=%d\n", *x, *y);
}
void main() {
	int a = 5;
	int b = 10;
	/*printf("Brojevi nakon funkcije (zamenaMesta) imaju vrednost:\n a=%d i b=%d\n", a, b);
	zamenaMesta(&a, &b);
	printf("Brojevi nakon funkcije (zamenaMesta) imaju vrednost:\n a=%d i b=%d\n", a, b);
    */
	int* pa = &a;
	++*pa;
	printf("%d", a);
	
}