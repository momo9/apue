FLAG = -g
CC = gcc

.PHONY: all
all: p241 testBreak zombie

.PHONY: p241
P241OBJ = p241.o ../tool.o
p241: p241.out
p241.out: $(P241OBJ)
	$(CC) -o p241.out $(P241OBJ) $(FLAG)
p241.o: p241.c
	$(CC) -c p241.c $(FLAG)

.PHONY: testBreak
TEST_BREAK_OBJ = testBreak.o
testBreak: testBreak.out
testBreak.out: $(TEST_BREAK_OBJ)
	$(CC) -o testBreak.out $(TEST_BREAK_OBJ) $(FLAG)
testBreak.o: testBreak.c
	$(CC) -c testBreak.c $(FLAG)

.PHONY: zombie
ZOBJ = zombie.o ../tool.o
zombie: zombie.out
zombie.out: $(ZOBJ)
	$(CC) -o zombie.out $(ZOBJ) $(FLAG)
zombie.o: zombie.c
	$(CC) -c zombie.c $(FLAG)

.PHONY: clean
clean:
	-rm *.o *.out
