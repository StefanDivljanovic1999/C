#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ispisi_ASCII() {
	int i;
	for ( i = 0; i <= 256; i++)
	{
		printf("%d\t%c\n", i, i);
	}
}

void stringovi() {
	char nizKaraktera[] = { 'r','e','c','\0' };
	printf("Niz karaktera: %s\n", nizKaraktera);

	char string2[] = "ovo je neki tekst!";
	printf("Niz karaktera: %s\n", string2);

	char string3[400];

	strcpy(string3, string2);
	printf("Niz karaktera: %s\n", string3);

	char string4[400];
	strcpy(string4, string2);
	strcat(string4, string3);
	printf("Niz karaktera: %s\n", string4);

	printf("Duzina stringa2 je:%d\n", strlen(string2));

	char* odV = strchr(string4, 'j');
	printf("%s\n", odV);

	_strupr(string4);
	printf("Velika slova: %s\n", string4);

	_strrev(string4);
	printf("Inverzno: %s\n", string4);

	printf("%s\n", strpbrk(string2, "o"));

	printf("%s\n", strstr(string4, "EJ"));

	char tekst[] = "18.12.2022. 20:41";
	char* token = strtok(tekst, " ");
	printf("%s\n", token);
	token = strtok(NULL, " ");
	printf("%s\n", token);
	token = strtok(NULL, " ");
	printf("%s\n", token);
}

void u_velika(char string[]) {
	for (int i = 0; string[i]!='\0'; i++)
	{
		if (string[i] >= 97 && string[i] <= 122) {
			string[i] -= 32;
		}
	}
}

void izbaci_gluposti(char s[]) {
	for (int i = 0; s[i] != '\0'; i++)
	{
		while (!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))) {
			for (int j = i; s[j] != '\0'; j++)
			{
				s[j] = s[j + 1];
				if (s[j] == '\0') {
					break;
				}
			}
		}
	
	}
}

void sredjivanje_cifara(char s[]) {
	
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (s[i] == '9') {
			s[i] = '0';
		}


		else if (s[i] >= 48 && s[i] < 57) {
			s[i]++;
			
		}	
		
	}
}

void cepanje_teksta(char s[]) {
	char* token = strtok(s, "@ ");
	printf("Naziv: %s\n", token);
	
	token = strtok(NULL, ". ");
	printf("Servis: %s\n", token);

	token = strtok(NULL, ". ");
	printf("Domen: %s\n", token);
}

int rec(char s[]) {
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (!((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))) {
			return 0;
		}
		
	}
	return 1;
}

int broj_ponavljanja(char s[], char c) {
	int br = 0;
	for (int i = 0; s[i] !='\0'; i++)
	{
		if (s[i] == c) {
			br++;
		}
	}
	return br;
}

void izbaci_char(char s[], char c) {
	
	int i=0;
	while (broj_ponavljanja(s, c) != 0) {
		while (s[i] != c) {
			i++;
		}
		for (int j = i; s[j] != '\0'; j++)
		{
			s[j] = s[j + 1];
			if (s[j] == '\0') {
				break;
			}
		}
	}
}

void samo_cifre(char s[]) {
	int i = 0;
	while (s[i] != '\0' && broj_ponavljanja(s,s[i])!=0) {
		if (s[i] >= 48 && s[i] <= 57) {		
				izbaci_char(s, s[i]);
		}
		i++;
	}
}

void zadatak3(char s[]) {
	int brojac = 0;
	char* token;
	token = strtok(s, " .,!?");
	printf("%s\n", token);
	while (token != NULL) {
		token = strtok(NULL, " .,!?");
		if (strlen(token) >= 3 && rec(token)==1) {
			printf("%s\n", token);
		}
			
		 
	}
}



void to_lower(char  s) {

	if (s >= 65 && s <= 90) {
		s += 32;

	}
}

void samoglasnici(char s[]) {

		for (int i = 0; s[i] != '\0'; i++)
		{
			if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
				s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
				s[i] == 'U')) {
				izbaci_char(s, s[i]);
			}
		}
	}

int IsSamoglasnik(char ch)
{
	ch = tolower(ch);   // ako je veliko slovo, pretvori ga u malo, radimo sa malim slovima

	if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return 1;
	else
		return 0;
} // IsSamoglasnik()

void Izvestaj(char *naslov, char *tekst, char *NajduziPodstring, int i, int dnp, int ipnp, int Tdnp, int Tipnp)
{
	printf("\n-- i = %d ------ %s --------------\n", i, naslov);
	printf("\n tekst[%d]=%c , tekst=|%s| , NajduziPodstring=|%s| \n",
		i, tekst[i], tekst, NajduziPodstring);
	printf("\n dnp %d \t ipnp %d \t Tdnp %d \t Tipnp %d \n",
		dnp, ipnp, Tdnp, Tipnp);
	//    getch();
} // Izvestaj()

char* NajduziPodstringSamoglasnika(char* tekst, char* NajduziPodstring)
{
	int i = 0, DuzinaTeksta;
	int dnp = 0, ipnp = 0, Tdnp = 0, Tipnp = 0; // T znaci privremen, temporary
	char TNajduziPodstring[100] = "";

	DuzinaTeksta = strlen(tekst);   // strlen() ne broji znak na kraju stringa '\0'
//    printf("\n\n DuzinaTeksta = %d \n\n", DuzinaTeksta );

	while (tekst[i]!='\0') {  // Od pocetka do kraja stringa tekst, ponavljamo sledece:

		Tdnp = 0; // resetujemo privremeni brojac duzine podstringa samoglasnika za novo brojanje

		// dok ne naidjes na samoglasnik ili do kraja stringa, preskaci znakove
		while (!IsSamoglasnik(tekst[i]) && tekst[i]) {
			i++;    // preskaci znakove uvecavanjem indeksa
		}

		// sada smo na prvom novom samoglasniku ili smo na kraju stringa tekst
		Tipnp = i; // pamtimo indeks (to mesto) prvog novog samoglasnika)

		// dok je samoglasnik ili do kraja stringa, broj samoglasnike
		while (IsSamoglasnik(tekst[i]) && tekst[i]!='\0') {    // ne mora  tekst[i] != '\0'
			TNajduziPodstring[Tdnp] = tekst[i];
			Tdnp++;
			i++;
		}

		// sada vise nismo na samoglasniku ili smo na kraju stringa tekst
		if (dnp < Tdnp) {     // dnp je uvek duzina najduzeg dosadasnjeg podstringa samoglasnika
			dnp = Tdnp;         // sada je to duzina najduzeg podstringa samoglasnika
			ipnp = Tipnp;       // sada je to indeks (mesto pocetka) najduzeg podstringa samoglasnika
			strcpy(NajduziPodstring, TNajduziPodstring);
		}

	} // while( tekst[i] )

	printf("\n Najduzi podstring samoglasnika pocinje na %d mestu i dugacak je %d samoglasnika. \n",
		ipnp + 1, dnp);

	return NajduziPodstring;
} // NajduziPodstringSamoglasnika()

int suglasnik(char c) {
	if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && !IsSamoglasnik(c)) {
		return 1;
	}
	return 0;
}

char* najduzi_podstring_suglasnika(char* tekst, char* NajduziPodniz) {
	int i = 0;
	int T_duzina = 0, max_duzina = 0, T_index = 0, max_index = 0;
	char max[100]="";

	while (tekst[i]!='\0') {
		T_duzina = 0;

		while (!suglasnik(tekst[i]) && tekst[i] != '\0') {
			i++;
		}
		T_index = i;
		while (suglasnik(tekst[i]) && tekst[i] != '\0') {
			max[T_duzina] = tekst[i];
			T_duzina++;
			i++;

		}

		if (T_duzina > max_duzina) {
			max_duzina = T_duzina;
			max_index = T_index;
			strcpy(NajduziPodniz, max);
		}

	}
	return NajduziPodniz;
}

char* najkraci_podniz_samoglasnika(char* tekst, char* minPodniz) {
	int i = 0, T_index = 0, Max_i = 0,T_duzina=0, Max_duzina=0;
	char podniz[100] = " ";
	while (tekst[i] != '\0') {
		T_duzina = 0;

		while (!IsSamoglasnik(tekst[i]) && tekst[i] != '\0') {
			i++;
		}
		
		T_index = i;

		while (IsSamoglasnik(tekst[i]) && tekst[i] != '\0') {
			podniz[T_duzina] = tekst[i];
			i++;
			T_duzina++;
		}
		if (T_duzina < Max_duzina) {
			Max_duzina = T_duzina;
			Max_i = T_index;
			strcpy(minPodniz, podniz);
		}
	}
	return minPodniz;
}

int main(void){
	char tekst[100]; //="12 fg aaa bvcf ssd ae";
	char NajduziPodstring[100];
	int DuzinaTeksta;

	//    strcpy(tekst, "12 fg aaa bvcf ssd ae" );

	printf("\n\n Unesi tekst sa slovima i/ili ciframa: ");
	gets(tekst);

	//486332-15=486318

	printf("\n U tekstu: |%s| najkraci podstring samoglasnika je: |%s|\n\n",
		tekst, najkraci_podniz_samoglasnika(tekst, NajduziPodstring));

	/*
	  // Ovo sluzi da bi se pratilo kako funkcija radi
		printf("\n\n U tekstu: |%s| najduzi podstring samoglasnika je: |%s|\n\n",
			   tekst, NajduziPodstringSamoglasnikaSaIzvestajima(tekst, NajduziPodstring) );
	*/



	printf("\n\n");
	system("PAUSE");


}





