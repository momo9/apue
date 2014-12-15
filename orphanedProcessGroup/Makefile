TAR = orphaned.out

$(TAR): main.o ../tool.o
	gcc -o $(TAR) main.o ../tool.o

main.o: main.c
	gcc -c main.c

tool.o: ../tool.c
	gcc -c ../tool.c
