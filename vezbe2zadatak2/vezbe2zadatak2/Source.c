#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	for (int i = 1; i <=10; i++)
	{
		if (i%2==0){
			printf("Broj %d je paran.\n", i);
		}
		else {
			printf("Broj %d je neparan.\n", i);
		}
	}
}