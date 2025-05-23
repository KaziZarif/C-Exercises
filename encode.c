#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	//Main function to encode
	
	return;
}


int main(int argc, char** argv) {
	char buffer[MAX_STRING];
	int length;
	while(fgets(buffer, MAX_STRING, stdin) != NULL) {
		length = strlen(buffer);
		
		if (buffer[length - 1] == '\n') {
			buffer[length - 1] = '\0';
		}
		length--;
		
		if (count_unique_chars(buffer, length) > 10) {
			return 1;
		}
	}
	
	
	
	//encode(buffer, length);
	
	
	//printf("%s\n", msg);
	return 0;
}
