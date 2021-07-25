CC=gcc
FLAGS=-Wall -Werror --pedantic -Os

all:fsize

fsize:fsize.c
	${CC} ${FLAGS} $^ -o $@

clean:
	rm fsize
