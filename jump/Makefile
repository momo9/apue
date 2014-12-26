CC = gcc
FLG = -g -Wall

JMP_TAR = jump.out
JMP_OBJ = jump.o ../tool.o
$(JMP_TAR): $(JMP_OBJ)
	$(CC) -o $(JMP_TAR) $(JMP_OBJ) $(FLG)
jump.o: jump.c
	$(CC) -c jump.c $(FLG)
