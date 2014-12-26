#include "../tool.h"
#include <signal.h>

void alarmHandler(int signo) {

}

int main(void) {
    sigset_t newmask, oldmask, pendmask;

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);
    if (sigprocmask(SIG_BLOCK, &newmask, NULL) < 0) {
        err("block error");
    }

    if (signal(SIGALRM, alarmHandler) < 0) {
        err("signal error");
    }
    alarm(5);
    pause();

    printf("unblocked\n");
    if (sigprocmask(SIG_UNBLOCK, &newmask, NULL) < 0) {
        err("unblock error");
    }
    pause();
    exit(EXIT_SUCCESS);
}
