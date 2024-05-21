#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


 typedef struct {
	 char ime[200];
	 char prezime[200];
	 int godiste;
}Osoba;




void main() {
	Osoba o1;
	printf("Unesite ime i prezime osobe broj 1: ");
	scanf("%s %s", &o1.ime, &o1.prezime);
//	printf("%s %s\n", o1.ime, o1.prezime);
	printf("Unesite godiste:");
	scanf("%d", &o1.godiste);
	
	
	Osoba o2;
	printf("Unesite ime i prezime osobe broj 2: ");
	scanf("%s %s", &o2.ime, &o2.prezime);
//	printf("%s %s", o2.ime, o2.prezime);
	printf("Unesite godiste: ");
	scanf("%d", &o2.godiste);
	

	Osoba s;
	if (o1.godiste < o2.godiste) {
		s = o1;
		printf("Ime i prezime starije osobe je: %s %s\n, godiste: %d\n", s.ime, s.prezime, s.godiste);
	}
	else {
		s = o2;
		printf("Ime i prezime starije osobe je: %s %s\n, godiste: %d\n", s.ime, s.prezime, s.godiste);
	}

//	o1.prezime = "Divljanovic";

	



}