#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>=

volatile sig_atomic_t start = 0;

struct sigaction sa_1;
struct sigaction sa_2;
struct sigaction sa_3;

void handle_sigusr1(int sig) {
    start = 1;
}

void handle_sigusr2(int sig) {
    start = 0;
}

void handle_sigint(int sig) {
    start = 2;
}

int main(int argc, char** argv) {

    pid_t id = fork();
    if (id == -1) {
        printf("Fork failed.\n");
        return 1;
    } 
    if (id == 0) {
        sa_1.sa_handler = &handle_sigusr1;
        sigaction

    } else {
        while(1) {
            char c;
            printf("Press s to start stopwatch, p to pause and q to quit: \n");
            scanf("%c", &c);
            if (c == 's') {
                kill(id, SIGUSR1);
            } 
            else if (c == 'p') {
                kill(id, SIGUSR2);
            } 
            else if (c == 'q') {
                kill(id, SIGINT);
                break;
            }
        }
        wait(NULL);
    }

    return 0;
}