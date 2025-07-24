#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>=


struct sigaction sa;

int main(int argc, char** argv) {

    pid_t id = fork();
    if (id == -1) {
        printf("Fork failed.\n");
        return 1;
    } 
    if (id == 0) {

    } else {
        
    }

    return 0;
}