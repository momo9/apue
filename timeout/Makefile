TAR = timeout.out
OBJ = timeout.o ../tool.o

$(TAR): $(OBJ)
	cc -o $(TAR) $(OBJ)
timeout.o: timeout.c
	cc -c timeout.c
