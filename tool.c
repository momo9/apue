#include "tool.h"
#include <stdio.h>
#include <stdlib.h>

void err(char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}
