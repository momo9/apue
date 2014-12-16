#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "../tool.h"

void handler(int signo) {
    printf("signal: %d\n", signo);
    fflush(stdout);
    exit(EXIT_SUCCESS);
}

int main(void) {
    if (SIG_ERR == signal(SIGUSR1, handler)) {
        err("signal fail");
    }
    printf("bound with SIGUSR1 (%d)\n", SIGUSR1);
    sleep(10);
    fputs("normal\n",stdout);
    exit(EXIT_SUCCESS);
}
