// your code here
#include <stdio.h>
#include <string.h>

int main(void) {
	char msg[128];
	while (fgets(msg, 127, stdin) != NULL) {
		int index = strlen(msg) - 1;
		for(int i = index; i >= 0; i--) {
			printf("%c", msg[i]);
		}
	}
	return 0;
}