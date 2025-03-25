// your code here
#include <stdio.h>

int main(void) {
	int n;
	char msg[128];
	printf("Enter key: ");
	scanf("%d", &n);
	printf("\n");
	if (n < 0 || n > 26) {
		printf("Invalid key!\n");
		return 1;
	}
	return 0;