#include "tool.h"
#include <stdio.h>
#include <stdlib.h>

void err(char* msg) {
    fputs(msg, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
}
