// your code here
#include <stdio.h>
#include <string.h>

int main(void) {
	char msg[128];
	while (fgets(msg, 127, stdin) != NULL) {
		int index = strlen(msg) - 1;
		if (msg[index] == '\n') {
			msg[index] = '\0';
			index--;
		}
		for(int i = index; i >= 0; i--) {
			printf("%c", msg[i]);
		}
		printf("\n");
	}
	return 0;
}