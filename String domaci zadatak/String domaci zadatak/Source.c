#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ispisiASCII() {
	for (int i = 0; i <256; i++)
	{
		printf("%c\t%d\n", i, i);
	}
}

void uvecajCifre(char s[]) {
	int i;
	for ( i = 0; s[i]!='\0'; i++)
	{
		if (s[i] >=48 && s[i] <=57 ) {
			if (s[i] == 57) {
				s[i] = 48;
			}
			else {
				s[i] += 1;
			}
		}
		
	}
}

void desifrujEmail(char email[]) {
	char* token = strtok(email, ".@");
	printf("Naziv posiljaoca: %s\n", token);
	token = strtok(NULL, ".@");
	printf("Naziv servera: %s\n", token);
	token = strtok(NULL, ".@");
	printf("Domen: %s\n", token);
}

void brojReci(char s[]) {
	int brojac = 0;
	char* token = strtok(s, " ");
	while (token != NULL) {
		if(strlen(token)>=3 )
		
		brojac++;
		token = strtok(NULL, " ");

	}
	printf("Broj reci je: %d\n", brojac);
}

int daLiJeSamoglasnik(char s) {
	if (s == 'a' || s == 'A' || s == 'E' || s == 'e' || s == 'i' || s == 'I' || s == 'o' || s == 'O' || s == 'u' || s=='u') {
		return 1;
	}
}

void ispisiSamoglasnike(char s[]) {
	int brojac = 0;
	for (int i = 0; s[i]!='\0'; i++)
	{
		if (daLiJeSamoglasnik(s[i])) {
			brojac++;
		}
	}
	printf("%d\n", brojac);
}

void napraviNoviString(char s[],char s2[],int n2) {
	n2 = 0;
	for (int i = 0; i <strlen(s); i++)
	{
		if (s[i] >= 48 && s[i] < 57) {
			while(s[i]!='\0  ')
			s2[++n2] = s[i];
		}
	}
	printf("%s", s2);
}

void main() {
	
	//ispisiASCII();
	char email[] = "stefanDivljanovic2984@gmail.com";
	uvecajCifre(email);
	printf("%s\n", email);
	char poslovni[] = "Coca-Cola@hbc.rs";
	desifrujEmail(poslovni);
	char recenica[] = "Daj mi javu ja cu tebi san, pti9co moja bijeli labude!";
	
	brojReci(recenica);
	char s2[100];
	ispisiSamoglasnike(recenica);
	napraviNoviString(recenica,s2,0);
}