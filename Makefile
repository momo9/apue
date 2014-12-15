TAR = testBreak.out
CC  = gcc
$(TAR): testBreak.c
	$(CC) -o testBreak.out testBreak.c
