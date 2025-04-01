#include <stdio.h>

int main(void) {
	char line[256];
	char anagram[256];
	printf("Enter line: ");
	fgets(line, sizeof(line), stdin);
	printf("Enter anagram: ");
	fgets(anagram, sizeof(anagram), stdin);
	
	return 0;
}