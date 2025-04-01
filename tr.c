#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void replace_chars(char* str, char* replace, char* replacement, int length) {
	while(*str) {
		for(int i = 0; i < length; i++) {
			if(*str == replace[i]) {
				*str = replacement[i];
				break;
			}
		}
		str++;
	}
}


int main(int argc, char** argv) {
	if (argc < 2) { 
		printf("No arguments\n");
		return 1;
	}
	else if (argc < 3) {
		printf("Not enough arguments\n");
		return 1;
	}
	else if (argc > 3) {
		printf("Too many arguments\n");
		return 1;
	}
	
	if (strlen(argv[1]) != strlen(argv[2])) {
		printf("Invalid arguments\n");
		return 1;
	}
	char* replace = argv[1];
	char* replacement = argv[2];
	int length = strlen(replace);
	char buf[256];
	while(fgets(buf, sizeof(buf), stdin) != NULL) {
		replace_chars(buf, replace, replacement, length);
		printf("%s", buf);
	}
	return 0;
}