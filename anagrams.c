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
	clean_str1[i] = '\0'
	int j = 0;
	while(*str2) {
		if(isalnum(*str2)) {
				clean_str2[j++] = tolower(*str2);
		}
		str2++;
	}
	clean_str2[j] = '\0'
}


int main(void) {
	char line[256];
	char anagram[256];
	printf("Enter line: ");
	fgets(line, sizeof(line), stdin);
	printf("Enter anagram: ");
	fgets(anagram, sizeof(anagram), stdin);
	
	
	return 0;
}