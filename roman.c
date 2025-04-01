#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
	char input[100];
    char *endptr;
    long num = 0;
	printf("Enter a number: ");
	if(fgets(input, sizeof(input), stdin)) {
		num = strtol(input, &endptr, 10);
		
		while(isspace((unsigned char)* endptr)) endptr++;
		
		if (*endptr != '\0' && *endptr != '\n') {
			printf("\nNot a number.\n");
		} else {
			printf("\nValid number: %ld\n", num);
		}
	}
	return 0;
}
