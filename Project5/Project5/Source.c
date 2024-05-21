#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double vratiNajveci(double x, double y, double z) {
	double najveci;
	if (x > y && x > z) {
		najveci = x;
	}
	else if (y > x && y > z) {
		najveci = y;
	}
	else {
		najveci = z;
	}
	printf("Najveci je %f", najveci);
	return najveci;
	
}
void daLiJeSamoglasnik(char x) {
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
		printf("\nKarakter %c je samoglasnik\n", x);
	}
	else {
		printf("\nKarakter %c je suglasnik\n", x);
	}
}
void proizvodCifara(int broj) {
	int jednice = broj / 1000;
	int destice = broj / 10;
	int stote = broj / 100;
	int hiljadite = broj / 1000;
}

void prevestiUCelzijuse(double kelvin) {
	double celzijus = kelvin - 273.15;
	printf("%f kelvina je %f celzijusa", kelvin, celzijus);
}
void dnevniKurs() {
	float dnevniKurs;
	float brojEvra;
	float brojDinara;
	printf("Unesite danasnju kurs evra:\n");
	scanf("%f", &dnevniKurs);
	printf("Unesite kolicnu evra za razmenu:\n");
	scanf("%f", &brojEvra);
	brojDinara = brojEvra * dnevniKurs;
	printf("Za kolicnu od %f evra po kursu od %f dinara po evru dobijate %f dinara!", brojEvra, dnevniKurs, brojDinara);
}
void operacijeSaBrojevima() {
	int a;
	int b;
	char operacija;
	printf("Unesite broj 1: \n");
	scanf("%d", &a);
	printf("Unesite broj 2: \n");
	scanf("%d", &b);
	printf("Unesite operciju: \n");
	scanf("\n%c", &operacija);
	switch (operacija)
	{
	case '+':
		printf("Zbir brojeva %d i %d je %d", a, b, a + b);
		break;
	case '-':
		printf("Razlika brojeva %d i %d je %d", a, b, a - b);
		break;
	case '*':
		printf("Proizvod brojeva %d i %d je %d", a, b, a * b);
		break;
	case '/':
		printf("Kolicnik brojeva %d i %d je %f", a, b, (float) a / b);
		break;
	case 'k':
		printf("Koreni brojeva %d i %d su %f i %f", a, b, sqrt(a),sqrt(b));
		break;

	default: 
		printf("Unesite operaciju u pravilnom formatu: '+', '-', '/' , 'k'!");
		
	
		break;
	}

}
void pomocnaVsr() {
	float brojMinuta;
	printf("Unesite broj minuta koji je trebalo: \n");
	scanf("%f", &brojMinuta);
	printf("Broj sati je: \n %f", brojMinuta / 60);
}
void srednjaBrzina() {
	float brojKilometara;
	float brojSati;
	printf("Unesite predjenu putanju:\n");
	scanf("%f", &brojKilometara);
	printf("Unesite vreme koje vam je trebalo da predjete putanju:\n");
	pomocnaVsr();
	printf("\nUnesite konvertovano vreme u satima:\n");
	scanf("%f", &brojSati);
	printf("Srednja brzina na putu je: \n %f km/h!", brojKilometara/brojSati);

}
void brojNaStepen() {
	int m;
	int n;
	printf("Unesite broj m\n");
	scanf("%d", &m);
	printf("Unesite broj n\n");
	scanf("%d", &n);
	int stepen = pow(m, n);
	printf("%d na %d je: \n %d", m, n, stepen);
}
char maloSlovo() {
	char slovo;
	printf("Unesite neko malo slovo: \n");
	scanf("%c", &slovo);
	char velikoS = slovo - 32;
	return velikoS;
}

void proizvod() {
	int broj;
	printf("Unesite neki broj\n:");
	scanf("%d", &broj);
	int hiljadite = broj / 1000;
	int stote = (broj / 100) % 10;
	int desetice = (broj / 10) % 10;
	int jedinice = broj % 10;
	printf("Cifre broja %d su %d, %d, %d i %d\n",broj, hiljadite, stote, desetice, jedinice);
	int p = hiljadite * stote*desetice*jedinice;
	printf("Proizvod cifara broja %d je:\n %d ", broj, p);
}
void verovatnoca() {
	int brojC;
	int brojB;
	int brojP;
	char izbor;
	printf("U kutiji se nalaze crne, bele i plave kuglice.\n");
	
	printf("Unesite broj crnih kuglica:\n");
	scanf("%d", &brojC);
	
	printf("Unesite broj belih kuglica:\n");
	scanf("%d", &brojB);
	
	printf("Unesite broj plavih kuglica:\n");
	scanf("%d", &brojP);

	printf("Verovatnoce za boje se dobijaju nakon unosa zelenih sifara\n c-> crna \n b-> bela \n p->plava\n");
	printf("Unesite zeljenu sifru:\n");
	scanf("\n%c", &izbor);

	int zbir = brojC + brojB + brojP;

	switch (izbor)
	{
	case 'c':
	    printf("Verovatnoca izvlacenja crne loptice je: %f", (float)brojC/zbir);
		break;
	case 'b':
		printf("Verovatnoca izvlacenja bele loptice je: %f",(float) brojB/zbir);
		break;
	case 'p':
		printf("Verovatnoca izvlacenja plave loptice je: %f", (float)brojP /zbir);
		break;
	default:
		printf("Unesite sifru u pravilnom foramtu, tj. \nc-> crna \n b-> bela \n p->plava\n");
		break;
	}

}
void popust() {
	float cena;
	float popust;
	printf("Unesite aktuelnu cenu proizvoda:\n ");
	scanf("%f", &cena);
	printf("Unesite popust u procentima:\n ");
	scanf("%f", &popust);
	double novaCena = cena-cena * popust / 100;
	printf("Snizena cena proizvoda je:\n %f ",novaCena);
	
}
void razlPiZ(int broj) {
	int c1 = broj / 10000;
	int c2 = (broj / 1000) % 10;
	int c3 = (broj / 100) % 10;
	int c4 = (broj / 10) % 10;
	int c5 = broj % 10;

	printf("Cifre unetog broja su: \n%d, %d, %d, %d, %d", c1, c2, c3, c4, c5);

	int prvi = c1;
	int poslednji = c5;
	printf("\nRazlika izmedju prve i poslednje cifre broja %d je \n%d", broj, prvi - poslednji);
}
void ArmstrongovBroj() {
	printf("Unesite neki broj: \n");
	int broj;
	scanf("\n%d", &broj);
	int stariBr = broj;
	int c1 = broj / 100;
	int c2 = (broj / 10) % 10;
	int c3 = (broj / 1) % 10;
	int brojac = 0;
	while (broj != 0) {
		broj /= 10;
		brojac++;
	}
	
	int arm = pow(c1, brojac) + pow(c2, brojac) + pow(c3, brojac);
	
	if (arm == stariBr) {
		printf("Broj %d je Armstrongov broj!",stariBr);
	}
	else {
		printf("Uneti broj %d nije Armstrongov!", stariBr);
	}

}
void main() {
	//vratiNajveci(15, 111, 188);
	//daLiJeSamoglasnik('e');
	//prevestiUCelzijuse(570);
	//dnevniKurs();
	//operacijeSaBrojevima();
	//srednjaBrzina();
	//brojNaStepen();
	//printf("%c",maloSlovo());
	//proizvod();
	//verovatnoca();
	//popust();
	//razlPiZ(46859);
	ArmstrongovBroj();
}