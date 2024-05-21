#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//napisati funkciju koja pomocu while petlje pise parne brojeve u rasponu od ulaznih brojeva

void brojevi(int m, int n) {
	
	//int i = m;
	while (m < n) {
		if(m%2==0)
		printf("%5d\n", m);
		m = m + 1;
		
	}

}


void main() {
	//int i = 0;
	/*while (i<5)
	{
		printf("%5d", i);
		i = i + 1;
	}*/
	//brojevi(2,100);
	faktorijel(5);
}