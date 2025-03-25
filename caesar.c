// your code here
#include <stdio.h>

int main(void) {
	int n;
	char msg[128];
	printf("Enter key: ");
	scanf("%d", &n);
	if (n < 0 || n > 26) {
		printf("\n");
		printf("Invalid key!\n");
		return 1;
	}
	while (getchar() != '\n');
	printf("Enter line: ");
	fgets(msg, 127, stdin);
	char *ptr = msg;
	while (*ptr) {
		if ((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')) {
			char base = (*ptr >= 'a') ? 'a' : 'A';
			*ptr = ((*ptr - base + n) % 26) + base;
		}
		ptr++;
	}
	printf("\n");
	printf("%s", msg);
	return 0;
}