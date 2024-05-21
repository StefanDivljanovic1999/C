#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main() {
	int sifra;
	//int cena;
	int stanje;
	int izlazna;
	printf("Program za racunanje putarina na autoputu \n");
	printf("U daljem delu se nalaze sifre za najcesce koriscene rampe\n");
	printf("BEOGRAD -> 1 \n");
	printf("NOVI SAD -> 2 \n");
	printf("NIS -> 3 \n");
	printf("MALI POZAREVAC -> 4 \n");

	int	cena12 = 240;
	int cena13 = 890;
	int cena14 = 80;

	int cena21 = cena12;
	int cena23 = 1160;
	int cena24 = 320;

	int cena31 = cena13;
	int cena32 = cena23;
	int cena34 = 840;

	int cena41 = cena14;
	int cena42 = cena24;
	int cena43 = cena34;

	printf("Unesite sifru ulazne rampe\n");
	scanf("%d", &sifra);

	printf("Unesite sifru izlazne rampe\n");
	scanf("%d", &izlazna);

	printf("Unesite stanje na racunu:\n");
	scanf("%d", &stanje);


	switch (sifra)
	{
	case 1:
		if (izlazna == sifra)
			printf("Unesite izlaznu stanicu koja je razlicita od ulazne!!!");

		if (izlazna == 2)
			stanje -= cena12;
		if (stanje <= cena12) {
			printf("Nemate dovoljno novca za prelazak rampe!");

		}
		if (izlazna == 3)
			stanje -= cena13;
		if (stanje <= cena13) {
			printf("Nemate dovoljno novca za prelazak rampe!");

			if (izlazna == 4)
				stanje -= cena14;
			if (stanje <= cena14) {
				printf("Nemate dovoljno novca za prelazak rampe!");

			}


			printf("Novo stanje nakon prelaska: \n");
			printf("%d", stanje);
			break;
	case 2:
		if (izlazna == sifra) {
			printf("Unesite izlaznu stanicu koja je razlicita od ulazne!!!");
		}
		if (izlazna == 1) {
			stanje -= cena21;
			if (stanje <= cena21) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 3) {
			stanje -= cena23;
			if (stanje <= cena23) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 4) {
			stanje -= cena24;
			if (stanje <= cena24) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		printf("Novo stanje nakon prelaska: \n");
		printf("%d", stanje);
		break;
	case 3:
		if (izlazna == sifra) {
			printf("Unesite izlaznu stanicu koja je razlicita od ulazne!!!");
		}
		if (izlazna == 1) {
			stanje -= cena31;
			if (stanje <= cena31) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 4) {
			stanje -= cena34;
			if (stanje <= cena34) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 2) {
			stanje -= cena32;
			if (stanje <= cena32) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		printf("Novo stanje nakon prelaska: \n");
		printf("%d", stanje);
		break;
	case 4:
		if (izlazna == sifra) {
			printf("Unesite izlaznu stanicu koja je razlicita od ulazne!!!");
		}
		if (izlazna == 1) {
			stanje -= cena41;
			if (stanje <= cena41) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 3) {
			stanje -= cena43;
			if (stanje <= cena43) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		if (izlazna == 2) {
			stanje -= cena42;
			if (stanje <= cena42) {
				printf("Nemate dovoljno novca za prelazak rampe!");
			}
		}
		printf("Novo stanje nakon prelaska: \n");
		printf("%d", stanje);
		break;
	default: printf("Unesite pravilnu sifru stanice!");
		break;
		}



	}
}
