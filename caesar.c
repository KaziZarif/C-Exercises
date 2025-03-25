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
	printf("Enter line: ");
	scanf("%127s", msg);
	return 0;
}