#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODES (10)
#define MAX_STRING (512)

void decode(const char* data, int length) {
	//Main function to decode
	int count = 0;
	int num_index = -1;
	for(int i = 0; i < length; i++) {
		if (!isdigit(data[i])) {
			count++;
		} else {
			num_index = i;
			break;
		}
		if (count > 10 || ((i < length - 1) && data[i] == '\0'))  {
			return;
		}
	}
	if (num_index < 0) return;
	
	char* msg = malloc(MAX_STRING);
	if (msg == NULL) {
		return;
	}
	char *ptr = msg;
	for(int i = num_index; i < length; i++) {
		int alpha_index = data[i] - '0';
		if (alpha_index >= count) {
			free(msg);
			return;
		}
		*ptr = data[alpha_index];
		ptr++;
	}
	*ptr = '\0';
	printf("%s", msg);
	printf("\n");
	free(msg);
}


int main(void) {
	char buffer[MAX_STRING];
	while(fgets(buffer, MAX_STRING, stdin) != NULL) {
		int length = strlen(buffer);
		if (buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
            length--;
        }
		decode(buffer, length);
	}
	return 0;
}
