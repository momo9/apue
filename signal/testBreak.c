#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void breakHandler(int signo) {
    printf("break\n");
    fflush(stdout);
}

int main(void) {
    signal(SIGINT, breakHandler);
    int cnt = 5;
    while (cnt-- > 0) {
        pause();
    }
}
