#include <stdio.h>
#include <stdlib.h>

#define BUF_LEN (512)

int main(int argc, char** argv) {
	
	char buf[BUF_LEN];
	//Your code here
	if (argc < 2) {
		return 1;
	}
	int allowed[256] = {0}; 
	for (int i = 1; i < argc; i++) {
		allowed[(unsigned char) argv[i][0]] = 1;
	}
	while(fgets(buf, BUF_LEN-1, stdin) != NULL) {
		for(char *ptr = buf; *ptr != '\0'; ptr++) {
			if(allowed[(unsigned char) *ptr]) {
				printf("%c", *ptr);
			}
		}
	}
	return 0;
	
}
