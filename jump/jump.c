#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <signal.h>
#include "../tool.h"
#include <unistd.h>

static jmp_buf env;

void intHandler(int signo) {
    longjmp(env, 10);
}

int main() {
    if (signal(SIGINT, intHandler) == SIG_ERR) {
        err("cannot set handler");
    }
    int ret = 0;
    if ((ret = setjmp(env)) == 0) {
        printf("pausing...\n");
        pause();
    }
    printf("return %d\n", ret);
    exit(EXIT_SUCCESS);
}
