#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int valid_number(char* str) {
	while(*str) {	
		if(!isdigit((unsigned char)*str)) {
			return 0;
		}
		str++;
	}
	return 1;
}

void build_board(int width, int height, int x, int y, int limit) {
	printf("+");
	for (int i =0; i <= 2*width - 2; i++) {
		printf("-");
	}
	printf("+\n");
	
	char* board = malloc(height * width * sizeof(char));
	if (board == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	for(int i = 0; i < height; i++) {
		for(int j = 0; j < width; j++) {
			if (i == y && j == x) {
				board[i*width + j] = 'C';
			}
			else {
				board[i*width + j] = ' ';
			}
		}
	}
	for (int i = 0; i < height * width * sizeof(char); i++) {
		printf("|%c", board[i]);
		if ((i+1) % width == 0) {
			printf("|\n");
		}
	}
	free(board);
	printf("+");
	for (int i =0; i <= 2*width - 2; i++) {
		printf("-");
	}
	printf("+\n");

	return;
}


int main(int argc, char** argv) {
	if (argc != 6) {
		printf("Invalid Number of Arguments\n");
		return 1;
	}
	const char* arg_names[] = {"Width", "Height", "Character Properties"};
	for(int i = 1; i < argc; i++) {
		if (!valid_number(argv[i])) {
			if (i > 2){
				printf("Invalid %s\n", arg_names[2]);
			} else {
				printf("Invalid %s\n", arg_names[i-1]);
			}
			return 1;
		}
	}
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int x = atoi(argv[3]);
	int y = atoi(argv[4]);
	int limit = atoi(argv[5]);
	
	if (width <= 0) {
		printf("Invalid Width\n");
		return 1;
	}
	else if (height <= 0) {
		printf("Invalid Height\n");
		return 1;
	}
	else if (x < 0 || x >= width) {
		printf("Invalid Character Properties\n");
		return 1;
	}
	else if (y < 0 || y >= height) {
		printf("Invalid Character Properties\n");
		return 1;
	}
	else if (limit < 0) {
		printf("Invalid Character Properties\n");
		return 1;
	}
	
	build_board(width, height, x, y, limit);
	
	return 0;
}