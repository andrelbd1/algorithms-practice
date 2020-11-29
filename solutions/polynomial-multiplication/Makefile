CC=g++
CFLAGS=-Wall
LIBS=-lm
SRC=$(wildcard *.c *.cpp)

all: polymul

polymul: $(SRC)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

clean:
	rm -f *.o *.exe
