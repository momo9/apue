#include "../tool.h"
#include <signal.h>

static void recieveFromChild(int signo) {
    err("parent exit");
}

int main(void) {
    if (signal(SIGUSR1, recieveFromChild) < 0) {
        err("signal error");
    }
    pid_t childId;
    sigset_t zeroSet;
    sigemptyset(&zeroSet);
    if ((childId = fork()) < 0) {
        err("fork error");
    } else if (childId != 0) {
        sigsuspend(&zeroSet);
    }
    sleep(5);
    kill(getppid(), SIGUSR1);
    err("child end");
}
