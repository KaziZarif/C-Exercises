#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
	int dist;

} Pos;

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
    // Print top border
    printf("+");
    for (int i = 0; i <= 2 * width - 2; i++) {
        printf("-");
    }
    printf("+\n");

    // Allocate board array
    char* board = malloc(height * width * sizeof(char));
    if (board == NULL) {
        printf("Memory allocation failed for board\n");
        return;
    }

    // Distance array, initialize with -1 meaning "unvisited"
    int* distArr = malloc(height * width * sizeof(int));
    if (distArr == NULL) {
        printf("Memory allocation failed for distArr\n");
        free(board);
        return;
    }

    for (int i = 0; i < height * width; i++) {
        board[i] = ' ';
        distArr[i] = -1;
    }

    // BFS setup
    Pos* queue = malloc(height * width * sizeof(Pos));
    if (queue == NULL) {
        printf("Memory allocation failed for queue\n");
        free(board);
        free(distArr);
        return;
    }
    int front = 0;
    int rear = 0;

    // Directions: up, down, left, right
    int dirs[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    // Enqueue starting position with distance 0
    queue[rear++] = (Pos){ x, y, 0 };
    distArr[y * width + x] = 0;  // distance = 0 at character's position

    // BFS loop
    while (front < rear) {
        Pos current = queue[front++];
        int curX = current.x;
        int curY = current.y;
        int curDist = current.dist;

        // Stop exploring neighbors if we've hit the walk limit
        if (curDist >= limit) {
            continue;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int nx = curX + dirs[i][0];
            int ny = curY + dirs[i][1];

            // Check boundaries
            if (nx < 0 || nx >= width || ny < 0 || ny >= height) {
                continue;
            }
            int neighborIndex = ny * width + nx;

            // If not visited yet
            if (distArr[neighborIndex] == -1) {
                distArr[neighborIndex] = curDist + 1;
                queue[rear++] = (Pos){ nx, ny, curDist + 1 };
            }
        }
    }

    // Now fill the board based on distArr
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int index = row * width + col;
            int d = distArr[index];

            if (col == x && row == y) {
                board[index] = 'C';  // Character’s position
            } else if (d >= 0 && d <= limit) {
                // 'd' steps away, so remaining walk points = limit - d
                // Display it as a digit if <= 9, else use another symbol
                int remaining = limit - d;
                if (remaining >= 0 && remaining <= 9) {
                    board[index] = '0' + remaining;
                } else {
                    board[index] = '*'; // If remaining > 9, mark it differently
                }
            } else {
                // Not reachable within limit => remains ' '
            }
        }
    }

    // Print the board
    for (int i = 0; i < height; i++) {
        printf("|");
        for (int j = 0; j < width; j++) {
            printf("%c|", board[i * width + j]);
        }
        printf("\n");
    }

    // Print bottom border
    printf("+");
    for (int i = 0; i <= 2 * width - 2; i++) {
        printf("-");
    }
    printf("+\n");

    // Free memory
    free(board);
    free(distArr);
    free(queue);
}


int main(int argc, char** argv) {
	if (argc != 6) {
		printf("Invalid Number Of Arguments\n");
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