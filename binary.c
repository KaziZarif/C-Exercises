#include <stdio.h>
#include <string.h>

#define MAX_SIZE 8

int power_of_two(int n) {
	return 1 << n;
}

void binary_to_decimal(char *string, int length) {
	int sum = 0;
	int exponent = 0;
	while(length > 0) {
		if (string[length - 1] != '0' && string[length - 1] != '1') {
			printf("Not binary!\n");
			return;
		}
		sum += (string[length - 1] - '0') * power_of_two(exponent);
		exponent++;
		length--;
	}
	printf("%d in decimal\n", sum);
	
}

int main(void) {
	char buffer[MAX_SIZE+1];
	printf("Enter binary: ");
	scanf("%8s", buffer);
	printf("\n");
	int length = strlen(buffer);
	binary_to_decimal(buffer, length);
	
	return 0;
}