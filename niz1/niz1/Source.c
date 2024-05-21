#define _CRT_SECURE_NO_WARNINGS
#define MAX 2000000;
#include <stdio.h>

void dodaj_u_niz(int niz[], int* n, int p) {
	niz[(*n)++] = p;
}
void ispisi_niz(int niz[], int n) {
	printf("Elementi niza su: \n");
	for (int i = 0; i <n; i++)
	{
		printf("%d\t", niz[i]);
	}
}
int suma_niza(int niz[], int n) {
	int suma = 0;
	for (int i = 0; i <n; i++)
	{
		suma += niz[i];
	}
	return suma;
}
double avg_neparnih(int niz[], int n) {
	int brojac = 0;
	int suma = 0;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 != 0) {
			suma += niz[i];
			brojac++;
		}
	}
	return (double)suma / brojac;
}
void smesti_samo_parne(int niz[], int* n) {
	int x;
	int brojac = 0;
	int broj;
	printf("\nUnesite zeljeni broj unosa: ");
	scanf("%d", &broj);
	do {
		printf("Unesite neki broj: ");
		scanf("%d", &x);
		brojac++;
	
	if (x % 2 == 0) {
		dodaj_u_niz(niz, n, x);
	}
	} while (brojac != broj
		);
	//ispisi_niz(niz, n);

}
int najmanji_parni_element(int niz[], int n) {
	int min = MAX;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < min) {
			min = niz[i];
		}
	}
	return min;
}
void pomeri_za_mesto_udesno(int niz[], int* n) {
	(*n)++;
	for (int i = (*n)-1; i>0; i--)
	{
		niz[i] = niz[i - 1];
	}
	
	
}
void dodaj_na_drugo_mesto(int niz[], int* n, int poz, int pod) {
	int ni = 0;
	98 - 46;
	printf("%d", 313 - 68);
}
void dodaj_na_K_mesto(int niz[], int* n, int el, int k) {
	(*n)++;
	for (int i = (*n) - 1; i > 0; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[k-1] = el;
	
}
void napravi_dva_nova_od_niza(int niz[], int n, int parni[], int* p1, int neparni[], int* n2) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 0) {
			dodaj_u_niz(parni, p1, niz[i]);
		}
		else {
			dodaj_u_niz(neparni, n2, niz[i]);
		}
	}
}
void ubaci_na_pocetak(int niz[], int* n, int el) {
	(*n)++;
	for (int i = *n-1; i >0; i--)
	{
		niz[i] = niz[i - 1];
	}
	niz[0] = el;
}
int postoji_u_nizu(int niz[], int n, int el) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] == el) {
			return 1;
		}
		
	}
	return -1;
}
int pun_niz(int niz[], int n) {
	int br = 0;
	for (int i = 0; i < n; i++)
	{
		br++;
	}
	if (br >= 8) {
		return -1;
	}
	return 0;
}
int suma(int niz[], int n) {
	int s = 0;
	for (int i = 0; i <n; i++)
	{
		s += niz[i];
	}
	return s;
}
int br_elemenata(int niz[], int n) {
	int brojac = 0;
	for (int i = 0; i < n; i++)
	{
		brojac++;
	}
	return brojac;

}
void zadatak2() {
	
	/*Имплементирати непараметризовану процедуру zadatak_2.У оквиру ове процедуре
		прихватити n бројева и убацити их и низ.Приликом убацивања елемената у низ проверити да
		ли је низ пун и да ли у низу већ не постоји такав број.Уколико су ова два услова испуњена
		убацити број на почетак низа.Уколико је низ пун приказати поруку : Niz je pun., а ако број
		постоји у низу приказати поруку : Broj(koji broj) ce vec nalazi u nizu.У процедури zadatak_2
		позвати процедуру за приказ елемената низа.Процедура zadatak_2 мора бити
		имплементирана.Ово је предуслов да би се бодовале претходно имплементиране процедуре
		и функције*/
	
	int niz[399];
	int* n = 0;
	int k;
	int br;
	do
	{
		printf("Unesite broj elementa niza: ");
		scanf("%d", &k);
	} while (k<1);
	printf("\n");
	do {
		printf("Unesite neki el: ");
		scanf("%d", &br);
		if (postoji_u_nizu(niz, n, br) == -1 && pun_niz(niz,n)==0) {
			ubaci_na_pocetak(niz, &n, br);
		}
		else {
			printf("Broj(%d) je vec smesten u niz!!!",br);
		}
		
	} while (br_elemenata(niz, n) < k);
	ispisi_niz(niz, n);


	
}
void unos_niza(int x[], int *n) {
		int i = 0;
		int broj;
		
		do {
			printf("Unesite ceo broj: ");
			scanf("%d", &broj);
			if (postoji_u_nizu(x, *n, broj) == -1) {
				ubaci_na_pocetak(x, n, broj);
			}
			
		} while (broj > 0);
	}
void izbaci_sa_pocetka(int niz[], int* n) {
	
	for (int i = 0; i < *n; i++)
	{
		niz[i] = niz[i + 1];
	}
	(*n)--;
}
int posotoji_paran_broj(int niz[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (niz[i] % 2 == 0) {
			return 1;
		}
	}
	return -1;
}
int min_parni_broj(int niz[], int n) {
	int min = MAX;
	for (int i = 0; i < n; i++)
	{
		if (niz[i] < min && niz[i] % 2 == 0) {
			min = niz[i];
		}
	}
	return min;
}
void zadatak3(int niz[], int* n) {
	int odg;
	
	printf("Izaberite opciju:");
	printf("\n1. Izbacite element sa pocetka niza \n2. Provera da li posotoji paran broj\n3. Minimalan paran broj\n0.Izlaz  ");
	scanf("%d", &odg);
	switch (odg)
	{
	case 1:
		izbaci_sa_pocetka(niz, n);
	case 2:
		printf("Postoji li paran broj: %d", posotoji_paran_broj(niz, *n));
	case 3:
		printf("Minimalan paran broj je: %d" , min_parni_broj(niz, *n));
	case 0:
		return;
		break;
	}
}

void main() {
	int niz[9];
	int n = 0;
	dodaj_u_niz(niz, &n, 15);
	dodaj_u_niz(niz, &n, 18);
	dodaj_u_niz(niz, &n, 23);
	dodaj_u_niz(niz, &n, 46); 
	dodaj_u_niz(niz, &n, 7);
	dodaj_u_niz(niz, &n, 97);
	dodaj_u_niz(niz, &n, 3);
	dodaj_u_niz(niz, &n, 4);
	ispisi_niz(niz, n);
	izbaci_sa_pocetka(niz, &n);
	printf("\n");
	ispisi_niz(niz, n);
	printf("\nPostoji paran broj: %d", posotoji_paran_broj(niz, n));
	printf("\nMinimalan paran broj: %d", min_parni_broj(niz, n));
	zadatak3(niz,&n);
	ispisi_niz(niz, n);
}