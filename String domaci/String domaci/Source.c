#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int daLiSuSVeSlova(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] >= 'Z'))) {
			return 0;
		}
		
	}
	return 1;
}

void kolikoImaReci(char s[]) {
	int i;
	int brojReci = 0;
	
	char* token = strtok(s, " ");
	while (token != NULL) {
		token = strtok(NULL, " ");
		if (daLiSuSVeSlova(token) && strlen(token) >= 3)
			brojReci++;
		//token = strtok(NULL, " ");
		printf("Broj reci u tekstu: \n %s \n je : %d", s, brojReci);
	}
	
	
}

void podeliEmailAdresu(int s) {
	char* token = strtok(s, "@.");
	printf("Naziv: %s\n", token);
	token = strtok(NULL, "@.");
	printf("Server: %s\n", token);
	token = strtok(NULL, "@.");
	printf("Domen: %s\n", token);

		
}
void main() {
	char tekst[]="stefidasa@gmail.com ";
//	kolikoImaReci(tekst);
	podeliEmailAdresu(tekst);
	//printf("%d ", daLiSuSVeSlova(tekst));
}