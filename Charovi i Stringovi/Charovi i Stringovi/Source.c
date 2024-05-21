#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void ispisiASCII() {
	printf("\tASCII tabela\n\nkod\tkarakter\n ");
	for (int i = 0; i <256; i++)
	{
		printf(" %d \t%c\n", i, i);
	}
} 
void malaUVelika(char s[]) {
	//napisati funkciju koja sva mala slova iz teksta pretvara u velika slova!
	printf(" \n Tekst pre prebacivanja malih u velika slova:  \n %s \n", s);
	int i;
	for ( i = 0; s[i]!='\0' ; i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] -='a'-'A' ;

		}
	}
	printf("\n  Tekst nakon prebacivanja malih u velika slova: \n %s \n", s);

}
void radSaStringovima() {
	char c = 'a';
	printf("ASCII kod znaka %c je %d\n", c, c);
	c += 4;
	printf("ASCII kod znaka %c je %d\n", c, c);

	//ispisiASCII();

	char reci[] = { 'r','e','c' };
	char string[] = { 'r','e','c','\0' };
	char string2[] = "ovo je neki tekst";
	printf("String2 je: %s\n", string2);

	char string3[200];
	strcpy(string3, string2);

	printf("\n%d\n", strcmp(string, string2));
	printf("String3 je: %s\n", string3);


	//printf("\nSpojeni string i string2 zajedno izgledaju ovako: \n %s ", strcat(string2, string3));

	printf("Duzina stringa3 je: %d", strlen(string3));

	if (strcmp(string2, string3)) {
		printf("\nIsti su!\n");
	}
	char nekaRecenica[] = "Ides za kanadu";
	printf("\nReci posle slova t: %s\n", strchr(nekaRecenica, 'I'));

	char string4[200] = "ovo je neki tekst upisan malim slovima koji zelimo da pretvorimo u velika!";
	_strupr(string4);
	printf("%s\n", string4);
	_strrev(string4);
	printf("%s\n", string4);

	printf("%s\n", strpbrk(string3, "ies"));

	char* token;
	token = strtok(string2, " ");

	while (token != NULL) {
		token = strtok(NULL, " ");
		printf("%s\n", token);
	}
	char s[] = "Ovo je neki ProbNi sTrinG!";
	//malaUVelika(s);
	printf("%s\n", s);
	char* x = s;
	while (*x != '\0') {
		if (*x >= 'a' && *x <= 'z') {
			*x -= 32;
		}
		x++;
	}

	printf("%s\n", s);
}
void izbaciGluposti(char s[]) {
	printf("\n Tekst pre izbacivanja glupih karaktera:\n %s \n", s);
	int i,j;
	for (i = 0; s[i] != '\0'; i++) 
		if (!((s[i] >= 'a'&& s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' ')) {
			//printf(" %d ", i);
			for (j = i; s[j] != '\0'; j++) {
				s[j] = s[j + 1];
			}
		}
	
	printf("\n Tekst posle izbacivanja glupih karaktera:\n %s \n", s);
}
void izbaciSlovo(char tekst[]) {
	printf("Tekst pre izbacivanja slova : \n%s\n", tekst);
	int i;
	for(i=1;tekst[i] !='\0';i++)
	{
		//printf("e");
		if (!(tekst[i] >= 'a' && tekst[i]<='z')) {
			tekst[i] = ' ';
			//continue;
		}
		i++;
	}
	printf("\n Tekst posle  izbacivanja slova a karaktera:\n %s \n", tekst);
}
void uvecajCifreZa1(char s[]) {
	printf("\nTekst pre uvecavanja cifara za 1 glasi:\n %s\n", s);
	int i;
	for (i = 0; s[i] != '\0'; i++) {
	//	printf("Usao sam!");
		if (s[i] >= 48 && s[i] <= 57) {
			
			if (s[i] == 57) {
				s[i] = 48;
			}
			else {
				s[i] += 1;
			}
		}
	}
	printf("\nTekst posle uvecavanja cifara za 1 glasi:\n %s\n", s);
}
void podelaDomena(char s[]) {
	
}
void main() {
	//ispisiASCII();
	char tekst[] = "Ovoa je Neki probni. Tekst?";
	char mejl[] = "stefidasa1999@gmail.com";
	uvecajCifreZa1(mejl);
	//ispisiASCII();
}