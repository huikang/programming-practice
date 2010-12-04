CC=gcc

ALL:	gcd postfix bitree test sumTov strcmp

test:	test.o
	${CC} -o test test.o

test.o:	test.c
	${CC} -o test.o -c test.c


gcd:	gcd.o
	${CC} -o gcd gcd.o

gcd.o:	gcd.c
	${CC} -o gcd.o -c gcd.c


postfix:	postfix.o
	${CC} -o postfix postfix.o
postfix.o:	postfix.c
	${CC} -o postfix.o -c postfix.c


# Binary tree application
bitree: bitree.o
	${CC} -o bitree bitree.o
bitree.o:	bitree.c
	${CC} -o bitree.o -c bitree.c

sumTV: sumTov.o
	${CC} -o sumTov sumTo.o
sumTov.o:	sumTov.c
	${CC} -o sumTov.o -c sumTov.c
	
strcmp: strcmp.o
	${CC} -o strcmp strcmp.o
strcmp.o:	strcmp.c
	${CC} -o strcmp.o -c strcmp.c


clean:
	rm *.o test postfix gcd bitree sumTov strcmp
