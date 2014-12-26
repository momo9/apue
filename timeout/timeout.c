#include "../tool.h"
#include <signal.h>

#define LINE_SIZE 1024

void alarmHandler(int signo) {
}

int main() {
    char line[LINE_SIZE];
    ssize_t n = -1;
    struct sigaction act;
    act.sa_handler = alarmHandler;
    act.sa_flags &= ~SA_RESTART;
    if (sigaction(SIGALRM, &act, NULL) != 0) {
        perror("signal error");
    }
    alarm(5);
    if ((n = read(STDIN_FILENO, line, LINE_SIZE)) < 0) {
        alarm(0);
        perror("time out");
    }
    printf(line);
    alarm(0);
    exit(EXIT_SUCCESS);
}
