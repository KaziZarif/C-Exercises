#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define ROMAN_NUMBERS 13

typdef struct {
	const char* symbol;
	int value;
} Roman;

const romanSymbols[] = {
	{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400},
    {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40},
	{"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
					
void numToRoman(int num) {
	char* romanNumeral = malloc(64);
	int pos = 0;
	while (num > 0) {
		int i = 0;
		while(i < ROMAN_NUMBERS && num > 0) {
			if (num >= romanSymbols[i].value) {
				strcpy(&romanNumeral[pos], 
			}
		}
	}
	
}

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
