P241OBJ = p241.o ../tool.o
CC = gcc

.PHONY: p241

p241: p241.out

p241.out: $(P241OBJ)
	$(CC) -o p241.out $(P241OBJ)

p241.o: p241.c
	$(CC) -c p241.c
