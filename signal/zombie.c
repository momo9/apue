#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include "../tool.h"

int main(int argc, char **argv) {
    int nz = 0;
    if (argc == 2) {
        if (strcmp(argv[1], "--nz") == 0) {
            nz = 1;
        } else {
            char buf[256];
            snprintf(buf, sizeof(buf), "invalid: %s", argv[1]);
            err(buf);
        }
    }

    pid_t pid;

    if (nz) {
        signal(SIGCHLD, SIG_IGN);
    }

    if ((pid = fork()) < 0) {
        err("fork error");
    } else if (pid == 0) {
        exit(EXIT_SUCCESS);
    } else {
        pause();
        pause();
        exit(EXIT_SUCCESS);
    }
}
