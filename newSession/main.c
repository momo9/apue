#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../tool.h"

static int testTerm(void) {
    int fd;
    int ret;
    if ((fd = open("/dev/tty", O_RDWR)) < 0) {
        ret = 0;
    } else {
        ret = 1;
        close(fd);
    }
    return ret;
}

static void prIds(char* name) {
    printf("%s: ", name);
    printf("ppid = %d, pid = %d, grpid = %d, has term = %d\n",
            getppid(), getpid(), getpgrp(), testTerm());
    fflush(stdout);
}

int main(void) {
    prIds("parent");

    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        err("cannot fork");
    } else if (pid > 0) {
        if (wait(&status) != pid) {
            err("wait error");
        }
        printf("wait %d: %d\n", pid, WEXITSTATUS(status));
        exit(EXIT_SUCCESS);
    } else {
        prIds("child before set session");
        if (setsid() == -1) {
            err("session error");
        }
        prIds("child after set session");
        exit(EXIT_SUCCESS);
    }
}
