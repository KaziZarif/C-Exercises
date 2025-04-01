#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check_anagram(char* str1, char* str2) {
	char* clean_str1 = malloc(256);
	char* clean_str2 = malloc(256);
	int i = 0;
	while(*str1) {
		if(isalnum(*str1)) {
				clean_str1[i++] = tolower(*str1);
		}
		str1++;
	}
	clean_str1[i] = '\0';
	int j = 0;
	while(*str2) {
		if(isalnum(*str2)) {
				clean_str2[j++] = tolower(*str2);
		}
		str2++;
	}
	clean_str2[j] = '\0';
	if (i != j) {
		free(clean_str1);
		free(clean_str2);
		return 0;
	}
	int ascii[128];
	for (int index = 0; index < 128; index++) {
		ascii[index] = 0;
	}
	for (int index = 0; index < i; index++) {
		ascii[(unsigned char)clean_str1[index]] += 1;
	}
	for (int index = 0; index < j; index++) {
		ascii[(unsigned char)clean_str2[index]] -= 1;
	}
	for (int index = 0; index < 128; index++) {
		if (ascii[index] != 0) {
			free(clean_str1);
			free(clean_str2);
			return 0;
		}
	}
	free(clean_str1);
	free(clean_str2);
	return 1;
	
}


int main(void) {
	char line[256];
	char anagram[256];
	printf("Enter line: ");
	fgets(line, sizeof(line), stdin);
	printf("Enter anagram: ");
	fgets(anagram, sizeof(anagram), stdin);
	printf("\n");
	if (check_anagram(line, anagram)) {
		printf("Anagram!\n");
	} else {
		printf("Not an anagram.\n");
	}
	
	return 0;
}