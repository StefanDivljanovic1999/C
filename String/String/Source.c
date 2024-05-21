#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <string.h>

void ispisiASCII() {
	
	for (int i = 0; i <256; i++)
	{
		printf("%d\t%c\n", i, i);
	}
}
void poredjenjeStringova(char s[100], char s2[100]) {
	if (strcmp(s, s2) == 0) {
		printf("Isti su!");
	}
}

void testStringova() {
	char c = 'a';
	//printf("ASCII kod karakera %c je: %d", c,c);
	//ispisiASCII();
	char nizKaraktera[] = { 'r','e','c','\0' };
	printf("nizKaraktera: %s\n", nizKaraktera);
	char string2[] = "ovo je neki teskt!";
	char string[] = "Alal vera majstore";
	//strcpy(string, string2);
	printf("String: %s\n", string);
	poredjenjeStringova(string, string2);

	char string4[200];
	/*strcat(string2, string2);
	printf("Konkatenacija s i s2 je: %s ", string);
*/
	char* odV = strchr(nizKaraktera, 'e');
	printf("%s\n", odV);

	char* mala = _strupr(string2);
	printf("%s\n", string2);

	char s[] = "ides za kanadu, sivi audi rola po Beogradu!";
	_strrev(s);
	printf("%s\n", s);
	_strrev(s);
	printf("%s\n", strpbrk(s, "abk"));
	printf("%s\n", strstr(s, "sivi"));

	char datum[] = { "28.01.2022. 15:55" };
	char* token = strtok(datum, "  . :");
	while (token != NULL) {
		printf("%s\t", token);
		token = strtok(NULL, " . :");
	}
}

void pretvoriSvamalaUVelikaSlova(char s[100]) {
	for (int i = 0; i<=strlen(s); i++)
	{
		if (s[i] >=97 && s[i] <= 122) {
			s[i] -= 32;
			
		}
	}
	printf("Tekst sa pretvorenim svim malim u velika slova glasi:\n%s\n", s);
}

void izbaciGluposti(char s[]) {
	int i;
	for ( i = 0; s[i]!='\0'; i++)
	{
		if (!(s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] <= 122 || s[i] == ' ')) {
			s[i] =' ';
		}
	}
	printf("Tekst nakon izmene:\n %s\n", s);
}

void main() {
	//testStringova();
	//ispisiASCII();
	char s[] = "Dani! idu DaNi putuju, nEkI? srecni, NeKi TuGUjU";
	//pretvoriSvamalaUVelikaSlova(s);
	izbaciGluposti(s);
}
