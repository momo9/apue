#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "../tool.h"

static void prIds(char* name) {
    printf("%s: pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n",
            name, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}

static void sigHup(int signo) {
    printf("SIGHUP received, pid = %d\n", getpid());
    fflush(stdout);
}

int main(void) {

    char c;
    pid_t pid;

    prIds("parent");

    if ((pid = fork()) < 0) {
        err("cannot fork");
    } else if (pid > 0) { // pararent
        sleep(3);
        exit(EXIT_SUCCESS);
    } else { // child
        prIds("child");
        signal(SIGHUP, sigHup);
        kill(getpid(), SIGTSTP);
        prIds("child");
        if (read(STDOUT_FILENO, &c, 1) != 1) {
            printf("read error, errno = %d\n", errno);
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
}
