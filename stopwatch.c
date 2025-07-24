#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>=

volatile sig_atomic_t start = 0;

struct sigaction sa_1;
struct sigaction sa_2;
struct sigaction sa_3;

void handle_sigusr1(int sig) {

}

void handle_sigusr2(int sig) {

}

void handle_sigint(int sig) {

}

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