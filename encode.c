#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODES (10)
#define MAX_STRING (512)
#define INT_START (48)
#define INT_END (57)

int count_unique_chars(const char* str, int len) {
	int characters[128] = {0};
	int count = 0;
	for (int i = 0; i < len; i++) {
		char c = str[i];
		if (c < INT_START || c > INT_END) {
			characters[(unsigned char)c] += 1;
			if (characters[(unsigned char)c] == 1) {
				count++;
			}
		} 
	}
	
	return count;

}

void encode(const char* msg, int len) {
	char* alphabets = malloc(11);
	if (alphabets == NULL) {
		printf("Memory allocation failed.\n");
		return;
	}
	char* indices = malloc(len + 1);
	if (indices == NULL) {
		printf("Memory allocation failed.\n");
		free(alphabets);
		return;
	}
	int position[128];
	for (int i = 0; i < 128; i++) position[i] = -1;
	
	int nth_unique = 0;
	for (int i = 0; i < len; i++) {
		char letter = msg[i];
		if (position[(unsigned char) letter] == -1 && !isdigit(letter)) {
			position[(unsigned char) letter] = nth_unique;
			alphabets[nth_unique] = letter;
			nth_unique++;
		}
	}
	alphabets[nth_unique] = '\0';
	
	for (int i = 0; i < len; i++) {
		char letter = msg[i];
		indices[i] = position[(unsigned char) letter] + '0';
	}
	indices[len] = '\0';
	
	printf("%s%s\n", alphabets, indices);
	
	free(alphabets);
	free(indices);
	return;
}


int main(int argc, char** argv) {
	char buffer[MAX_STRING];
	int length;
	while(fgets(buffer, MAX_STRING, stdin) != NULL) {
		length = strlen(buffer);
		
		if (buffer[length - 1] == '\n') {
			buffer[length - 1] = '\0';
			length--;
		}
		
		if (count_unique_chars(buffer, length) > 10) {
			return 1;
		}
		//printf("%s\n", buffer);
		encode(buffer, length);
	}
	
	
	return 0;
}
