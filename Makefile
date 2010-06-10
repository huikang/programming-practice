CC=gcc

test:	test.o
	${CC} -o test test.o

test.o:	test.c
	${CC} -o test.o -c test.c

clean:
	rm *.o test