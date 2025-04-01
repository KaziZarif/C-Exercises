#include <stdio.h>


int main(int argc, char** argv) {
	if (argc < 2) { 
		printf("No arguments\n");
		return 1;
	}
	else if (argc < 3) {
		printf("Not enough arguments\n");
		return 1;
	}
	else if (argc > 3) {
		printf("Too many arguments\n");
		return 1;
	}
	return 0;
}